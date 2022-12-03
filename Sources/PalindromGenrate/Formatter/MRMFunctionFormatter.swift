var countCommand = 0

struct FunctionBodyFormatter: IFormatter {
    let baseFormatter: IFormatter

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let name = info.functionName;
        if info.prefixs.isEmpty && info.mode == .mod32 && !info.isFPU {
            countCommand += 1
        }
        generator.add("//\(info.command.name)")
        generator.add("void \(name)() {")
        generator.add("LOG(\"%s\",\"\(info.command.name)\");")
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
        if (info.flags.contains("d") && info.flags.contains("SEGMENT")) {
            generator.add("recalculatePointerSegmentRegisterMRM")
        }
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        let reg = info.flags.contains("SEGMENT") ? "uint8_t sr = readMiddle3Bit(mrmByte);" : ""

        let registerFunction = info.flags.contains("SEGMENT") ? "(uint8_t*)readSegmentRegisterMRM" : "(uint8_t*)readRegisterMRM%dataSize(mrmByte)"
        let addressFunction = "(uint8_t*)readAddressMRM%MODFor%dataSize(mrmByte)"

        let prepareGenerator = FunctionGenerator()
        prepareGenerator.add(reg)
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
            let prefixInfo = info.update { $0.prefixs += [.addressSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
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
            let prefixInfo = info.update { $0.prefixs += [.dataSizePrefix] }
            generator.add(baseFormatter.format(with: prefixInfo))
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
            .replacingOccurrences(of: "%2dataSize", with: "\(info.dataSize * 2)")
            .replacingOccurrences(of: "%firstBitMask", with: "\(info.firstBitMask)")
            .replacingOccurrences(of: "%1/2dataSize", with: "\(info.dataSize / 2)")
            .replacingOccurrences(of: "%MOD", with: info.mode == .mod16 ? "16" : "32")

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
    var replace: [(String) -> String] = []

    init(_ handler: @escaping (FormatterInfo) -> String?) {
        self.handler = handler
    }

    func format(with info: FormatterInfo) -> String? {
        guard var text = handler(info) else {
            return nil
        }
        for replace in self.replace {
            text = replace(text)
        }
        return text
    }
}

extension IFormatter {
    func replace(_ oldValue: String, to newValue: String) -> IFormatter {
        var result = (self as? BaseFormat) ?? BaseFormat { info in
            self.format(with: info)
        }
        result.replace.append { $0.replacingOccurrences(of: oldValue, with: newValue) }
        return result
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

    case nnn(_ variations: [(code: String, formatter: IFormatter)], prepare: IFormatter? = nil)
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
        case .nnn(let variations, let prepare):
            return ReplaceTemplateFormat(baseFormatter: NNNFunctionFormatter(baseFormatter: formatter, variations: variations, prepare: prepare))
        case .replace:
            return ReplaceTemplateFormat(baseFormatter: formatter)
        }
    }
}

struct InitialFormatter: IFormatter {
    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        let prefix = info.mode == .mod32 ? "32" : "16"
        generator.add("commandFunctions\(prefix)[\(info.variation)] = \(info.functionName);")
        if info.command.format.hasPrefixAddress {
            generator.add("commandFunctions\(prefix)[\(info.variation) | 0x0200 ] = \(info.update { $0.prefixs += [.addressSizePrefix] }.functionName);")
        }
        if info.command.format.hasPrefixData {
            generator.add("commandFunctions\(prefix)[\(info.variation) | 0x0400] = \(info.update { $0.prefixs += [.dataSizePrefix] }.functionName);")
        }
        if info.command.format.hasPrefixData && info.command.format.hasPrefixAddress {
            generator.add("commandFunctions\(prefix)[\(info.variation) | 0x0200 | 0x0400] = \(info.update { $0.prefixs += [.dataSizePrefix, .addressSizePrefix] }.functionName);")
        }
        return generator.text
    }
}

struct NNNFormatter {
    let hex: String
    let prepare: IFormatter?
    let formater: IFormatter
}

struct NNNFunctionFormatter: IFormatter {
    let baseFormatter: IFormatter
    let variations: [NNNFormatter]
    let prepare: IFormatter?

    init(baseFormatter: IFormatter, variations: [(String, IFormatter)], prepare: IFormatter?) {
        self.baseFormatter = baseFormatter
        self.variations = variations.map {
            .init(
                hex: $0.0,
                prepare: nil,
                formater: $0.1
            )
        }
        self.prepare = prepare
    }

    init(baseFormatter: IFormatter, variations: [NNNFormatter], prepare: IFormatter?) {
        self.baseFormatter = baseFormatter
        self.variations = variations
        self.prepare = prepare
    }

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add("uint8_t mrmByte = read8u();")
        generator.add("uint8_t nnn = readMiddle3Bit(mrmByte);")
        generator.add("switch (nnn) {")
        for variation in variations {
            generator.add("case \(variation.hex): {")
            if let prepare = variation.prepare {
                generator.add(prepare.format(with: info))
            } else {
                addPrepare(generator, with: info)
            }
            generator.add(prepare?.format(with: info))
            generator.add(variation.formater.format(with: info))
            generator.add("}")
            generator.add("break;")
        }
        generator.add("default:")
        generator.add("mCommandFunctionEmpty();")
        generator.add("}")
        generator.add(baseFormatter.format(with: info))
        return generator.text
    }

    private func addPrepare(_ generator: FunctionGenerator, with info: FormatterInfo) {
        guard !info.isFPU else {
            return
        }
        let prepareGenerator = FunctionGenerator()

        prepareGenerator.add(targetMRMFormat.format(with: info))
        if info.flags.contains("d") {
            prepareGenerator.swich(a: "target", b: "source")
        }
        generator.add(prepareGenerator.text)
    }
}

let targetMRMFormat = BaseFormat { info in
    "uint8_t* target = (uint8_t*)readAddressMRM%MODFor%dataSize(mrmByte);"
}

struct DestFormatter: IFormatter {
    let formatter: IFormatter

    init(_ formatter: () -> IFormatter) {
        self.formatter = formatter()
    }

    func format(with info: FormatterInfo) -> String? {
        let generator = FunctionGenerator()
        generator.add(formatter.format(with: info))
        if info.flags.contains("d") {
            generator.swich(a: "target", b: "source")
        }
        return generator.text
    }
}
