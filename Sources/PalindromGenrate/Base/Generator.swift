final class Generator {
    private var commands: [Command] = []

    public func addCommand(_ command: Command) {
        self.commands.append(command)
    }

    func generateAllCommand(_ installFormat: (String) -> String) -> String {
        let installGenerate = FunctionGenerator()
        let functionGenerate = FunctionGenerator()

        for mode in [Mode.mod16, Mode.mod32] {
            for command in commands {
                let variations = command.allVariation
                for variation in variations {
                    let flags = command
                        .format
                        .inlines
                        .filter { $0.isFlag && $0.getByte(UInt8(variation & 0x00FF)) != 0 }
                        .map { $0.name }
                    let vars = command
                        .format
                        .inlines
                        .filter { !$0.isFlag }
                        .map { (name: $0.name, value: $0.getByte(UInt8(variation & 0x00FF)).hex) }
                    let info = FormatterInfo(command: command, flags: Set(flags), mode: mode, variation: variation, vars: vars, prefixs: [])
                    installGenerate.add(command.installFormatter.format(with: info))
                    functionGenerate.add(command.functionFormatter.format(with: info))
                }
            }
        }

        return "\(functionGenerate.text) \n\n\(installFormat(installGenerate.text))"
    }
}
