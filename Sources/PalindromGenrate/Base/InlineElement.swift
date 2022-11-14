struct InlineElement {
    let name: String
    let indexBit: Int
    let count: Int

    var value: String? = nil

    func getByte(_ byte: UInt8) -> UInt8 {
        var mask: UInt8 = 1
        for _ in 0..<count {
            mask *= 2
        }
        return (byte >> indexBit) & (mask - 1)
    }

    var isFlag: Bool {
        count == 1
    }
}
