fileprivate let pushRegDataCommand = Command(
    code: 0x0050,
    name: "Push",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [.functionName, .vars, .prefixBigData, .bigData],
        baseFormatter: TemplateFormat(
            template: """
            uint%dataSize_t* sp = register%dataSizeu(context, BR_SP);
            *sp -= %dataSize / 8;
            *(uint%dataSize_t*)(mem(context, SR_SS) + *sp) = *register%dataSizeu(context, reg);
            """
        )
    ),
    installFormatter: InitialFormatter()
)

fileprivate let popRegDataCommand = Command(
    code: 0x0058,
    name: "Pop",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: true,
        inlines: [
            .init(name: "reg", indexBit: 0, count: 3)
        ]
    ),
    functionFormatter: Formatter(
        customizers: [.functionName, .vars, .prefixBigData, .bigData],
        baseFormatter: TemplateFormat(
            template: """
            uint%dataSize_t* sp = register%dataSizeu(context, BR_SP);
            *register%dataSizeu(context, reg) = *(uint%dataSize_t*)(mem(context, SR_SS) + *sp);
            *sp += %dataSize / 8;
            """
        )
    ),
    installFormatter: InitialFormatter()
)

func appendStackCommand(generator: Generator) {
    generator.addCommand(pushRegDataCommand)
    generator.addCommand(popRegDataCommand)

}

//let pushCommand = MachineCommand(
//    name: "Push",
//    command: .init(base: 0x0050),
//    format: .init(
//        functioinType: .custom,
//        inlineElements: [
//            .init(name: "reg", indexBit: 0, count: 3, recoverable: true)
//        ],
//        arguments: [.init(name: "", type: .data, size: .changeable)]
//    ),
//    functionFormat: """
//*(%dataType*)context->currentStack = *registeru%dataSize(context, reg);
//context->currentStack += %dataSize;
//"""
//)
//
//let popCommand = MachineCommand(
//    name: "Pop",
//    command: .init(base: 0x0058),
//    format: .init(
//        functioinType: .custom,
//        inlineElements: [
//            .init(name: "reg", indexBit: 0, count: 3, recoverable: true)
//        ],
//        arguments: [.init(name: "", type: .data, size: .changeable)]
//    ),
//    functionFormat: """
//context->currentStack -= %dataSize;
//*registeru%dataSize(context, reg) = *(%dataType*)context->currentStack;
//"""
//)
