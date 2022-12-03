final class FPUGenerator {
    private var stackCommands: [Command] = []
    private var memCommands: [Command] = []

    public func addCommand(_ command: Command, isStack: Bool) {
        if isStack {
            stackCommands.append(command)
        } else {
            memCommands.append(command)
        }
    }

    private func generateAllFunction(for commands: [Command]) -> [UInt16: [String: IFormatter]] {
        var nnnFunctions = [UInt16: [String: IFormatter]]()

        for command in commands {
            let variations = command.allVariation
            for variation in variations {
                let flags = command
                    .format
                    .inlines
                    .filter { $0.isFlag && ($0.value == nil ? $0.getByte(UInt8(variation & 0x00FF)) != 0 : ($0.value == "true")) }
                    .map { $0.name }
                let vars = command
                    .format
                    .inlines
                    .filter { !$0.isFlag }
                    .map { (name: $0.name, value: $0.value ?? $0.getByte(UInt8(variation & 0x00FF)).hex) }
                if flags.contains("pop") && !flags.contains("d") { continue }
                var info = FormatterInfo(command: command, flags: Set(flags), mode: .mod16, cpuMode: .protected, variation: variation, vars: vars, prefixs: [])
                info.additionalInfo = [.fpu]

                let realCommand = variation >> 3
                nnnFunctions[realCommand] = nnnFunctions[realCommand] ?? [:]
                let nnn = UInt8(variation & 7)
                nnnFunctions[realCommand]?[nnn.hex] = BaseFormat({ cInfo in
                    command.functionFormatter.format(with: info.update {
                        $0.mode = cInfo.mode
                        $0.cpuMode = cInfo.cpuMode
                    })
                })
            }
        }
        return nnnFunctions
    }

    func generateAllCommand(generator: Generator) {
        let stack = generateAllFunction(for: stackCommands)
        let memory = generateAllFunction(for: memCommands)

        let kyes = Array(Set(Array(stack.keys) + Array(memory.keys))).sorted()

        var nnnFunctions = [UInt16: [(String, IFormatter)]]()

        for key in kyes.sorted() {
            for i in 0..<8 {
                let memFormatter = memory[key]?[UInt8(i).hex] ?? TemplateFormat("// NON FUNCTION\nmCommandFunctionEmpty();")
                let stackFormatter = stack[key]?[UInt8(i).hex] ?? TemplateFormat("// NON FUNCTION\nmCommandFunctionEmpty();")

                nnnFunctions[key] = nnnFunctions[key] ?? []
                nnnFunctions[key]?.append((UInt8(i).hex, fpuBaseIfTarget(ifStack: stackFormatter, else: memFormatter)))
            }
        }

        for key in nnnFunctions.keys.sorted() {
            let command = Command(
                code: key,
                name: "FPU",
                format: .init(
                    hasPrefixAddress: false,
                    hasPrefixData: false,
                    inlines: []
                ),
                functionFormatter: Formatter(customizers: [
                    .functionName,
                    .settings([.fpu]),
                    .nnn(nnnFunctions[key]!)
                ]),
                installFormatter: InitialFormatter())
            generator.addCommand(command)
        }
    }
}
