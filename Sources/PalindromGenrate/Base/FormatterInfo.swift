struct FormatterInfo {
    let command: Command
    var flags: Set<String>
    var mode: Mode
    let variation: UInt16
    var vars: [(name: String, value: String)]
    var prefixs: [CommandPrefix]

    func update(_ block: (_ info: inout FormatterInfo) -> Void) -> Self {
        var info = self
        block(&info)
        return info
    }
}

extension FormatterInfo {
    var bigAddressSize: String {
        if mode == .mod32 || !prefixs.contains(.addressSizePrefix) {
            return "32"
        } else {
            return "16"
        }
    }

    var littleAddressSize: String {
        if mode == .mod32 || !prefixs.contains(.addressSizePrefix) {
            return "16"
        } else {
            return "8"
        }
    }

    var changeDataSize: String {
        if flags.contains("w") {
            if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
                return "32"
            } else {
                return "16"
            }
        } else {
            return "8"
        }
    }


    var bigDataSize: String {
        if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
            return "32"
        } else {
            return "16"
        }
    }

    var sign: String {
        if flags.contains("s") {
            return ""
        } else {
            return "u"
        }
    }
}

enum CommandPrefix: Int {
    case dataSizePrefix = 66
    case addressSizePrefix = 67
}

extension FormatterInfo {
    var isBase: Bool {
        flags.isEmpty && !vars.contains(where: { $0.value != "0x00" })
    }

    var functionName: String {
        "handlerCommand\(mode == .mod32 ? "32" : "16")Code\(variation)" + prefixs.map { "Prefix\($0)" }.joined()
    }
}
