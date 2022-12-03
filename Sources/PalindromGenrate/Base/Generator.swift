final class Generator {
    private var commands: [Command] = []

    public func addCommand(_ command: Command) {
        self.commands.append(command)
    }

    public func addCommands(_ commands: [Command]) {
        commands.forEach { self.commands.append($0) }
    }

    func generateAllCommand(_ installPrefix: String) -> String {
        let installGenerate = FunctionGenerator()

        let functionGenerate = FunctionGenerator()
        
        for cpuMode in [CPUMod.real, CPUMod.protected] {
            for mode in [Mode.mod16, Mode.mod32] {
                if cpuMode == .protected {
                    if mode == .mod16 {
                        installGenerate.add("void installCommandFunction16PM() {")
                    } else {
                        installGenerate.add("void installCommandFunction32PM() {")
                    }
                } else {
                    if mode == .mod16 {
                        installGenerate.add("void installCommandFunction16RM() {")
                    } else {
                        installGenerate.add("void installCommandFunction32RM() {")
                    }
                }
                installGenerate.add(installPrefix)
                for command in commands.sorted(by: { $0.code < $1.code }) {
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
                        let info = FormatterInfo(
                            command: command,
                            flags: Set(flags),
                            mode: mode,
                            cpuMode: cpuMode,
                            variation: variation,
                            vars: vars,
                            prefixs: []
                        )
                        installGenerate.add(command.installFormatter.format(with: info))
                        functionGenerate.add(command.functionFormatter.format(with: info))
                    }
                }
                installGenerate.add("}")
            }
        }

        return "\(functionGenerate.text) \n\n \(installGenerate.text)"
    }
}
