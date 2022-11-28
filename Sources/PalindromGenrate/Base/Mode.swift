enum Mode {
    case mod32
    case mod16
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
