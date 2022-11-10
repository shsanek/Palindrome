var countCommand = 0

struct FunctionBodyFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let name = info.functionName;
        if info.prefixs.isEmpty && info.mode == .mod32 {
            countCommand += 1
        }
        generator.add("//\(info.command.name)")
        generator.add("void \(name)() {")
        generator.add(baseFormatter.format(with: info))
        generator.add("}")
        return generator.text
    }
}

struct MRMFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add("uint8_t mrmByte = read8u();")
        addPrepare(generator, with: info)
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        var registerFunction = "(uint8_t*)readRegisterMRM%dataSize(mrmByte)"
        var addressFunction = "(uint8_t*)readAddressMRM%dataSize(mrmByte)"

        let prepareGenerator = FunctionGenerator()
        prepareGenerator.add("uint8_t* target = \(addressFunction);")
        prepareGenerator.add("uint8_t* source = \(registerFunction);")
        if info.flags.contains("d") {
            prepareGenerator.swich(a: "target", b: "source")
        }
        generator.add(prepareGenerator.text)
    }
}

struct PrefixAddressFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        if info.mode == .mod32 {
            let prefixInfo = info.update { $0.prefixs += [.addressSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
            generator.add(baseFormatter.format(with: info))
        } else {
            generator.add(baseFormatter.format(with: info))
        }
        return generator.text
    }
}

struct PrefixDataFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        if info.mode == .mod32 {
            let prefixInfo = info.update { $0.prefixs += [.dataSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
            generator.add(baseFormatter.format(with: info))
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

struct ReplaceTemplateFormat: IFormatter {
    let baseFormatter: IFormatter

    init(baseFormatter: IFormatter) {
        self.baseFormatter = baseFormatter
    }

    func format(with info: FormatterInfo) -> String? {
        var text = baseFormatter.format(with: info)
        for h in info.vars {
            text = text?.replacingOccurrences(of: "%\(h.name)", with: h.value)
        }
        return text?
            .replacingOccurrences(of: "%addressMask", with: info.addressMask)
            .replacingOccurrences(of: "%addressSize", with: "\(info.addressSize)")
            .replacingOccurrences(of: "%dataType", with: "\(info.sign)int\(info.dataSize)_t")
            .replacingOccurrences(of: "%dataSize", with: "\(info.dataSize)")
            .replacingOccurrences(of: "%dataMask", with: info.dataMask)
            .replacingOccurrences(of: "%sType", with: info.sign)
            .replacingOccurrences(of: "%sign", with: info.sign)
            .replacingOccurrences(of: "%operandSize", with: "\(info.operandSize)")
    }
}

struct SetInfoFormat: IFormatter {
    let baseFormatter: IFormatter
    let setting: [FormatterAdditionalInfo]

    init(baseFormatter: IFormatter, setting: [FormatterAdditionalInfo]) {
        self.baseFormatter = baseFormatter
        self.setting = setting
    }

    func format(with info: FormatterInfo) -> String? {
        baseFormatter.format(with: info.update { $0.additionalInfo = setting })
    }
}

struct TemplateFormat: IFormatter {
    let template: String

    init(_ template: String) {
        self.template = template
    }

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

struct CustomFormat: IFormatter {
    let baseFormatter: IFormatter
    let customFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add(customFormatter.format(with: info))
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }
}

//info.flags.contains("w")

enum FormatCustomizer {
    case mrm

    case vars

    case formatter(IFormatter)

    case prefixAddress
    case prefixData

    case functionName

    case replace
    case settings(_ info: [FormatterAdditionalInfo])

    case nnn(_ variations: [(code: String, formatter: IFormatter)])
}

extension FormatCustomizer: ExpressibleByStringLiteral {
    init(stringLiteral value: StringLiteralType) {
        self = .formatter(TemplateFormat(value))
    }
}

extension FormatCustomizer {
    static func template(_ text: String) -> Self {
        return .formatter(TemplateFormat(text))
    }
}

final class Formatter: IFormatter {
    let customizers: [FormatCustomizer]

    private lazy var rootFormatter = generateRootFormatter(with: customizers, formatter: TemplateFormat(""))

    init(
        customizers: [FormatCustomizer]
    ) {
        self.customizers = customizers
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
            return ReplaceTemplateFormat(baseFormatter: MRMFunctionFormatter(baseFormatter: formatter))
        case .prefixData:
            return PrefixDataFunctionFormatter(baseFormatter: formatter)
        case .prefixAddress:
            return PrefixAddressFunctionFormatter(baseFormatter: formatter)
        case .functionName:
            return FunctionBodyFormatter(baseFormatter: formatter)
        case .settings(let info):
            return SetInfoFormat(baseFormatter: formatter, setting: info)
        case .vars:
            return VarsFunctionFormatter(baseFormatter: formatter)
        case .formatter(let custom):
            return ReplaceTemplateFormat(baseFormatter: CustomFormat(baseFormatter: formatter, customFormatter: custom))
        case .nnn(let variations):
            return ReplaceTemplateFormat(baseFormatter: NNNFunctionFormatter(baseFormatter: formatter, variations: variations))
        case .replace:
            return ReplaceTemplateFormat(baseFormatter: formatter)
        }
    }
}

struct InitialFormatter: IFormatter {
    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let name = info.functionName;
        if info.mode == .mod32 {
            generator.add("commandFunctions32[\(info.variation)] = \(info.functionName);")
            if info.command.format.hasPrefixAddress {
                generator.add("commandFunctions32[\(info.variation) | 0x0200 ] = \(info.update { $0.prefixs += [.addressSizePrefix] }.functionName);")
            }
            if info.command.format.hasPrefixData {
                generator.add("commandFunctions32[\(info.variation) | 0x0400] = \(info.update { $0.prefixs += [.dataSizePrefix] }.functionName);")
            }
            if info.command.format.hasPrefixData && info.command.format.hasPrefixAddress {
                generator.add("commandFunctions32[\(info.variation) | 0x0200 | 0x0400] = \(info.update { $0.prefixs += [.dataSizePrefix, .addressSizePrefix] }.functionName);")
            }
        } else {
            generator.add("commandFunctions16[\(info.variation)] = \(name);")
        }
        return generator.text
    }
}

struct NNNFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter
    let variations: [(String, IFormatter)]

    init(baseFormatter: IFormatter, variations: [(String, IFormatter)]) {
        self.baseFormatter = baseFormatter
        self.variations = variations
    }

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add("uint8_t mrmByte = read8u();")
        generator.add("uint8_t nnn = readMiddle3Bit(mrmByte);")
        addPrepare(generator, with: info)
        generator.add("switch (nnn) {")
        for variation in variations {
            generator.add("case \(variation.0): {")
            generator.add(variation.1.format(with: info))
            generator.add("}")
            generator.add("break;")
        }
        generator.add("}")
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        let addressFunction = "(uint8_t*)readAddressMRM%addressSize(mrmByte)"

        let prepareGenerator = FunctionGenerator()
        prepareGenerator.add("uint8_t* target = \(addressFunction);")
        if info.flags.contains("d") {
            prepareGenerator.swich(a: "target", b: "source")
        }
        generator.add(prepareGenerator.text)
    }
}


struct VariationsFormatter: IFormatter {
    let baseFormatter: IFormatter
    let variations: [(UInt16, IFormatter)]

    init(baseFormatter: IFormatter, variations: [(UInt16, IFormatter)]) {
        self.baseFormatter = baseFormatter
        self.variations = variations
    }

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add("uint8_t mrmByte = read8u();")
        generator.add("uint8_t nnn = readMiddle3Bit(mrmByte);")
        addPrepare(generator, with: info)
        var isNotFirst = false
        for variation in variations {
            let prefix = isNotFirst ? "} else " : ""
            generator.add(prefix + "if (nnn == \(variation.0)) {")
            generator.add(variation.1.format(with: info))
            isNotFirst = true
        }
        if isNotFirst {
            generator.add("}")
        }
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        let addressFunction = "(uint8_t*)readAddressMRM%addressSize(mrmByte)"

        let prepareGenerator = FunctionGenerator()
        prepareGenerator.add("uint8_t* target = \(addressFunction);")
        if info.flags.contains("d") {
            prepareGenerator.swich(a: "target", b: "source")
        }
        generator.add(prepareGenerator.text)
    }
}
