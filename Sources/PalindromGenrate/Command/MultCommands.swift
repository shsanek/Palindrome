let multlCommand = Command(
    code: 0x01AF,
    name: "Mul",
    format: .init(
        hasPrefixAddress: false,
        hasPrefixData: false,
        inlines: []
    ),
    functionFormatter: Formatter(
        customizers: [
            .functionName,
            .settings([.bigData, .bigAddress]),
            .mrm,
            """
            LazyFlagVarA%dataSize = *(int%dataSize_t*)target;
            LazyFlagVarB%dataSize = *(int%dataSize_t*)source;
            LazyFlagResultContainer%dataSize = LazyFlagVarA%dataSize * LazyFlagVarB%dataSize;
            lazyFlagType = t_MUL;
            *(int%dataSize_t*)source = LazyFlagResultContainer%dataSize;
            """
        ]
    ),
    installFormatter: InitialFormatter()
)

func appendMultCommand(generator: Generator) {
    generator.addCommand(multlCommand)
}
