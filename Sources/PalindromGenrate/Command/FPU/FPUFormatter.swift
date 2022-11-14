func fpuMFDefault(_ formetter: IFormatter, isStack: Bool) -> BaseFormat {
    BaseFormat { info in
        let generator = FunctionGenerator()
        generator.add(fpuComment.format(with: info))
        generator.add("// \(info.command.name)")
        let mftFormatter = fpuMFTarget(memory: !isStack, formatter: formetter)
        generator.add(mftFormatter.format(with: info))
        return generator.text
    }
}

let fpuComment = BaseFormat { info in
    let command = info.variation
    let opa = ((info.variation >> 3) & 7)
    let opb = (info.variation & 7)
    return "// OPA \(opa.bits[13...15].map { "\($0)" }.joined()), OPB \(opb.bits[13...15].map { "\($0)" }.joined())"
}

func fpuBaseIfTarget(ifStack handler: IFormatter, else elseHandler: IFormatter) -> BaseFormat {
    BaseFormat { info in
        return """
        if ((mrmByte >> 6 & 3) == 3) {
        \(handler.format(with: info) ?? "")
        } else {
        \(elseHandler.format(with: info) ?? "")
        }
        """
    }
}

func fpuMFTarget(memory: Bool, formatter: IFormatter) -> BaseFormat {
    BaseFormat { info in
        let generator = FunctionGenerator()
        if !info.flags.contains("d") && info.flags.contains("push") {
            generator.add("fpuStackIndex -= 1;");
        }
        generator.add("double* valueA = fpuStack + fpuStackIndex;")
        if info.flags.contains("pop") && !info.flags.contains("d") {
            generator.add("double* target = valueA + 1;")
        } else {
            generator.add("double* target = valueA;")
        }
        if memory {
            let mf = info.vars.first(where: { $0.name == "MF" })
            var type = "NONE"
            if mf?.value == "0x00" {
                type = "float"
            }
            if mf?.value == "0x01" {
                type = "int32_t"
            }
            if mf?.value == "0x02" {
                type = "double"
            }
            if mf?.value == "0x03" {
                type = "int16_t"
            }
            if mf?.value == "lDouble" {
                type = "double"
            }
            if mf?.value == "lInt" {
                type = "int64_t"
            }
            let addressFunction = "(\(type)*)readAddressMRM\(info.mode == .mod32 ? "32" : "16")For8(mrmByte)"
            generator.add("\(type)* valueB = \(addressFunction);")
            generator.add("\(type)* source = valueB;")
        } else {
            generator.add("double* valueB = fpuStack + fpuStackIndex + (mrmByte & 7);")
            generator.add("double* source = valueB;")
        }
        if info.flags.contains("pop") {
            generator.add("fpuStackIndex += 1;");
        }
        if info.flags.contains("d") {
            generator.swich(a: "target", b: "source")
        }

        return generator.text + (formatter.format(with: info) ?? "")
    }
}

