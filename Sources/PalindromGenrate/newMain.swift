import Foundation

func generate() {
    let file = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/PalindromeC/Function/GenerateFunctions.c"
    let generator = Generator()

    appendAddCommand(generator: generator)
    appendMoveCommand(generator: generator)
    appendIncCommand(generator: generator)
    appendDecCommand(generator: generator)
    appendLoopCommand(generator: generator)
    appendIntCommand(generator: generator)
    appendStackCommand(generator: generator)
    appendSpecialCommand(generator: generator)
    appendMultCommand(generator: generator)
    appendF6F7Command(generator: generator)
    var text = "#include \"GenerateFunctions.h\"\n"

    text = text + generator.generateAllCommand(installGenerate)

    try! text.write(toFile: file, atomically: true, encoding: .utf8)
}

private func installGenerate(_ content: String) -> String {
    let base = """
    void mCommandFunctionEmpty() {
    context.end = 2;
    printf("function not implementation\\n");
    }

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
