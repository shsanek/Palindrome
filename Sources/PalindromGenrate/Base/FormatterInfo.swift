struct FormatterInfo {
    let command: Command
    var flags: Set<String>
    var mode: Mode
    let variation: UInt16
    var vars: [(name: String, value: String)]
    var prefixs: [CommandPrefix]
    var additionalInfo: [FormatterAdditionalInfo] = []
    let attributes = AttributeContainer()

    func update(_ block: (_ info: inout FormatterInfo) -> Void) -> Self {
        var info = self
        block(&info)
        return info
    }
}

struct FormatterInfoAttributeKey<Value>: Hashable {
    let identifier: String
}

final class AttributeContainer {
    private var values: [String: Any] = [:]

    init() { }

    func getValue<Value>(key: FormatterInfoAttributeKey<Value>) -> Value? {
        values[key.identifier] as? Value
    }

    func setValue<Value>(key: FormatterInfoAttributeKey<Value>, value: Value?) {
        values[key.identifier] = value
    }
}

enum FormatterAdditionalInfo {
    case sign

    case bigData
    case littleData
    case changeableData
    case fixOperand(_ fix: Int)
    case fixData(_ fix: Int)

    case bigAddress
    case littleAddress
    case fixAddress(_ fix: Int)

    case fpu

    case mrmRegisterSize(info: [FormatterAdditionalInfo])
    case mrmAddressSize(info: [FormatterAdditionalInfo])
}

extension FormatterInfo {
    var isFPU: Bool {
        for info in additionalInfo {
            switch info {
            case .fpu:
                return true
            default:
                continue;
            }
        }
        return false
    }
    var operandSize: Int {
        for info in additionalInfo {
            switch info {
            case .fixOperand(let fix):
                return fix
            default:
                continue;
            }
        }
        return dataSize
    }

    var addressSize: Int {
        for info in additionalInfo {
            switch info {
            case .bigAddress:
                if mode == .mod32 && !prefixs.contains(.addressSizePrefix) {
                    return 32
                } else {
                    return 16
                }
            case .littleAddress:
                if mode == .mod32 && !prefixs.contains(.addressSizePrefix) {
                    return 16
                } else {
                    return 8
                }
            case .fixAddress(let fix):
                return fix
            default:
                continue
            }
        }
        if mode == .mod32 && !prefixs.contains(.addressSizePrefix) {
            return 32
        } else {
            return 16
        }
    }

    var addressMask: String {
        switch addressSize {
        case 32:
            return "0xFFFFFFFF"
        case 16:
            return "0xFFFF"
        case 8:
            return "0xFF"
        default:
            return "0xFFFFFFFF"
        }
    }

    var dataSize: Int {
        for info in additionalInfo {
            switch info {
            case .bigData:
                if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
                    return 32
                } else {
                    return 16
                }
            case .changeableData:
                if flags.contains("w") {
                    if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
                        return 32
                    } else {
                        return 16
                    }
                } else {
                    return 8
                }
            case .fixData(let fix):
                return fix
            case .littleData:
                if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
                    return 16
                } else {
                    return 8
                }
            default:
                continue
            }
        }
        if mode == .mod32 && !prefixs.contains(.dataSizePrefix) {
            return 32
        } else {
            return 16
        }
    }

    var dataMask: String {
        switch dataSize {
        case 32:
            return "0xFFFFFFFF"
        case 16:
            return "0xFFFF"
        case 8:
            return "0xFF"
        default:
            return "0xFFFFFFFF"
        }
    }

    var sign: String {
        for info in additionalInfo {
            switch info {
            case .sign:
                return ""
            default:
                continue
            }
        }
        if flags.contains("s") {
            return ""
        }
        return "u"
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
        "handlerCommand\(mode == .mod32 ? "32" : "16")Code\(variation.rawHex)" + Array(Set(prefixs)).sorted(by: { $0.rawValue < $1.rawValue }).map { "P\($0.rawValue)" }.joined()
    }
}
