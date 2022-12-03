enum Mode {
    case mod32
    case mod16
}

enum CPUMod {
    case real
    case protected
}

extension Mode {
    var togle: Mode {
        switch self {
        case .mod32:
            return .mod16
        case .mod16:
            return .mod32
        }
    }
}
