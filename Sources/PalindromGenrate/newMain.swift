import Foundation

func generate() {
    let file = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/PalindromeC/Function/GenerateFunctions.c"
    let generator = Generator()

    appendMoveCommand(generator: generator)

    appendAddCommand(generator: generator)
    appendIncCommand(generator: generator)
    appendDecCommand(generator: generator)
    appendLoopCommand(generator: generator)
    appendIntCommand(generator: generator)
    appendStackCommand(generator: generator)
    appendSpecialCommand(generator: generator)
    appendMultCommand(generator: generator)
    appendF6F7Command(generator: generator)
    appendSwipeCommand(generator: generator)
    appendMockCommand(generator: generator)
    append0F90Command(generator: generator)
    appendBitShiftCommand(generator: generator)
    appendPop8fCommand(generator:generator)
    appendFlagsCommand(generator: generator)
    appendInlineCommand(generator: generator)

    fpuGenerator(generator: generator)

    let fileGenerator = FunctionGenerator()
    fileGenerator.add("""
        #include "GenerateFunctions.h"
        void mCommandFunctionEmpty() {
        context.end = 2;
        printf("function not implementation %X\\n", context.lastCommandInfo.command);
        //*((uint8_t*)NULL) = 0;
        }
        """
    )

    let text = fileGenerator.text + generator.generateAllCommand(installGenerate)

    try! text.write(toFile: file, atomically: true, encoding: .utf8)
}

func fpuGenerator(generator: Generator) {
    let fpuGenerator = FPUGenerator()
    appendFPUMoveCommand(generator: fpuGenerator)
    appendFPUAddCommand(generator: fpuGenerator)
    appendFPUSubCommand(generator: fpuGenerator)
    appendFPUDivCommand(generator: fpuGenerator)
    appendFPUMulCommand(generator: fpuGenerator)
    appendFPUControlCommand(generator: fpuGenerator)

    fpuGenerator.generateAllCommand(generator: generator)
}

private func installGenerate(_ content: String) -> String {
    let base = """

    void installCommandFunction() {
    for(int i = 0; i < 256 * 8; i++) {
    commandFunctions16[i] = mCommandFunctionEmpty;
    commandFunctions32[i] = mCommandFunctionEmpty;
    }
    \(content)
    }
    """
    let generator = FunctionGenerator()
    generator.add(base)

    return generator.text
}
