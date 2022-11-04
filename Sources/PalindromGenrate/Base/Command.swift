import Foundation

struct Command {
    let code: UInt16
    let name: String

    let format: CommandFormat

    let functionFormatter: IFormatter
    let installFormatter: IFormatter
}

extension Command {
    var rootByte: UInt8 {
        UInt8(code & 0x00FF)
    }
}

extension Command {
    var allVariation: [UInt16] {
        let bitCount = format.inlines.reduce(0, { $0 + $1.count })
        let variationCount = powf(Float(2), Float(bitCount))
        let baseBits = code.bits

        var result: [UInt16] = []

        for i in 0..<UInt8(variationCount) {
            var current = baseBits
            var index = 0
            for inline in format.inlines {
                for j in 0..<inline.count {
                    current[15 - inline.indexBit - j] = i.bits[7 - index]
                    index += 1
                }
            }
            result.append(.init(bits: current))
        }
        return result.sorted()
    }
}
