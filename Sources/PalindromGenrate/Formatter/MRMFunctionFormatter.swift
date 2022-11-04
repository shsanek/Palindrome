struct FunctionBodyFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let name = info.functionName;
        generator.add("void \(name)(Context *context) {")
        generator.add(baseFormatter.format(with: info))
        generator.add("}")
        return generator.text
    }
}

struct MRMFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add("uint8_t mrmByte = read8u(context);")
        addPrepare(generator, with: info)
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        let type = "\(info.sign)int\(info.changeDataSize)_t"
        let registerFunction = "(\(type)*)readRegisterMRM\(info.changeDataSize)(context, mrmByte);"
        let addressFunction = "(\(type)*)readAddressMRM\(info.mode == .mod32 ? "32" : "16")(context, mrmByte);"

        let prepareGenerator = FunctionGenerator()
        prepareGenerator.add("\(type)* target = \(addressFunction);")
        prepareGenerator.add("\(type)* source = \(registerFunction);")
        if info.flags.contains("d") {
            prepareGenerator.swich(a: "target", b: "source")
        }
        generator.add(prepareGenerator.text)
    }
}

struct PrefixDataFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        if info.mode == .mod32 && info.flags.contains("w") {
            generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
            let prefixInfo = info.update { $0.prefixs += [.dataSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
            generator.add("} else {")
            generator.add(baseFormatter.format(with: info))
            generator.add("}")
        } else {
            generator.add(baseFormatter.format(with: info))
        }
        return generator.text
    }
}

struct PrefixBigDataFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        if info.mode == .mod32 {
            generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
            let prefixInfo = info.update { $0.prefixs += [.dataSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
            generator.add("} else {")
            generator.add(baseFormatter.format(with: info))
            generator.add("}")
        } else {
            generator.add(baseFormatter.format(with: info))
        }
        return generator.text
    }
}

struct PrefixAddressFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        if info.mode == .mod32 {
            generator.add("if (context->lastCommandInfo.prefixInfo.operandSizePrefix) {")
            let prefixInfo = info.update { $0.prefixs += [.dataSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
            generator.add("} else {")
            generator.add(baseFormatter.format(with: info))
            generator.add("}")
        } else {
            generator.add(baseFormatter.format(with: info))
        }
        return generator.text
    }
}

struct VarsFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        for item in info.vars {
            generator.add("uint8_t \(item.name) = \(item.value);")
        }
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }
}

struct ChangeableDataTemplateFormat: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        baseFormatter.format(with: info)?
            .replacingOccurrences(of: "%dataType", with: "\(info.sign)int\(info.changeDataSize)_t")
            .replacingOccurrences(of: "%dataSize", with: info.changeDataSize)
            .replacingOccurrences(of: "%sType", with: info.sign)
    }
}

struct BigDataTemplateFormat: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        baseFormatter.format(with: info)?
            .replacingOccurrences(of: "%dataType", with: "\(info.sign)int\(info.bigDataSize)_t")
            .replacingOccurrences(of: "%dataSize", with: info.bigDataSize)
            .replacingOccurrences(of: "%sType", with: info.sign)
    }
}

struct BigAddressTemplateFormat: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        baseFormatter.format(with: info)?
            .replacingOccurrences(of: "%addressSize", with: info.bigAddressSize)
    }
}

struct LittleAddressTemplateFormat: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        baseFormatter.format(with: info)?
            .replacingOccurrences(of: "%addressSize", with: info.littleAddressSize)
    }
}

struct TemplateFormat: IFormatter {
    let template: String

    func format(with info: FormatterInfo) -> String? {
        template
    }
}

struct BaseFormat: IFormatter {
    let handler: (FormatterInfo) -> String?

    init(_ handler: @escaping (FormatterInfo) -> String?) {
        self.handler = handler
    }

    func format(with info: FormatterInfo) -> String? {
        handler(info)
    }
}

enum FormatCustomizer {
    case mrm

    case vars

    case prefixAddress
    case prefixData
    case prefixBigData

    case functionName

    case littleAddress
    case bigAddress

    case changeableData
    case bigData
}

final class Formatter: IFormatter {
    let customizers: [FormatCustomizer]
    let baseFormatter: IFormatter

    private lazy var rootFormatter = generateRootFormatter(with: customizers, formatter: baseFormatter)

    init(
        customizers: [FormatCustomizer],
        baseFormatter: IFormatter
    ) {
        self.customizers = customizers
        self.baseFormatter = baseFormatter
    }

    func format(with info: FormatterInfo) -> String? {
        rootFormatter.format(with: info)
    }

    private func generateRootFormatter(with customizers: [FormatCustomizer], formatter: IFormatter) -> IFormatter {
        guard !customizers.isEmpty else {
            return formatter
        }
        var customizers = customizers
        let last = customizers.removeLast()
        let newFormatter = self.formatter(for: last, formatter: formatter)
        return generateRootFormatter(with: customizers, formatter: newFormatter)
    }

    private func formatter(for customizer: FormatCustomizer, formatter: IFormatter) -> IFormatter {
        switch customizer {
        case .mrm:
            return MRMFunctionFormatter(baseFormatter: formatter)
        case .prefixData:
            return PrefixDataFunctionFormatter(baseFormatter: formatter)
        case .prefixAddress:
            return PrefixAddressFunctionFormatter(baseFormatter: formatter)
        case .prefixBigData:
            return PrefixBigDataFunctionFormatter(baseFormatter: formatter)
        case .functionName:
            return FunctionBodyFormatter(baseFormatter: formatter)
        case .littleAddress:
            return LittleAddressTemplateFormat(baseFormatter: formatter)
        case .bigAddress:
            return BigAddressTemplateFormat(baseFormatter: formatter)
        case .changeableData:
            return ChangeableDataTemplateFormat(baseFormatter: formatter)
        case .bigData:
            return BigDataTemplateFormat(baseFormatter: formatter)
        case .vars:
            return VarsFunctionFormatter(baseFormatter: formatter)
        }
    }
}

extension Formatter {
    static func defaultMRM(_ baseFormatter: IFormatter) -> Formatter {
        let customizer: [FormatCustomizer] = [.functionName, .prefixData, .mrm, .changeableData]
        return Formatter(customizers: customizer, baseFormatter: baseFormatter)
    }
}

struct InitialFormatter: IFormatter {
    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let name = info.functionName;
        generator.add("commandFunctions\(info.mode == .mod32 ? "32" : "16")[\(info.variation)] = \(name);")
        return generator.text
    }
}
