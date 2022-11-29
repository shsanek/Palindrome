import Foundation

extension UInt8 {
    public var hex: String {
        String(format: "0x%02X", self)
    }

    public var rawHex: String {
        String(format: "%02X", self).uppercased()
    }

    public init(bits: [UInt8]) {
        var result: UInt8 = 0
        var m: UInt32 = 1
        let min = bits.count < 8 ? bits.count : 8
        for i in 0..<min {
            result += UInt8(bits[bits.count - 1 - i]) * UInt8(m)
            m *= 2
        }
        self = result
    }

    var bits: [UInt8] {
        var base = Array(repeating: UInt8(0), count: 8)
        var byte = self
        for i in 0..<8 {
            base[7 - i] = UInt8(byte % 2)
            byte = byte / 2
        }
        return base
    }
}

extension UInt16 {
    public var rawHex: String {
        UInt8((self >> 8) & 0x00FF).rawHex + UInt8(self & 0x00FF).rawHex
    }

    public init(bits: [UInt8]) {
        var result: UInt16 = 0
        var m: UInt32 = 1
        let min = bits.count < 16 ? bits.count : 16
        for i in 0..<min {
            result += UInt16(bits[bits.count - 1 - i]) * UInt16(m)
            m *= 2
        }
        self = result
    }

    var bits: [UInt8] {
        var base = Array(repeating: UInt8(0), count: 16)
        var byte = self
        for i in 0..<16 {
            base[15 - i] = UInt8(byte % 2)
            byte = byte / 2
        }
        return base
    }
}

public final class FunctionGenerator {
    public private(set) var text = ""
    private var tab: Int = 0

    public init() { }

    public func add(_ lines: String?) {
        guard let lines = lines?.replacingOccurrences(of: "\t", with: "") else {
            return
        }
        for line in lines.split(separator: "\n") {
            let line = line.replacingOccurrences(of: "\t", with: "")
            if let separate = line.firstIndex(where: { $0 == "{" || $0 == "(" || $0 == "[" }) {
                tab -= line[line.startIndex..<separate].filter( { $0 == "}" || $0 == ")" || $0 == "]" }).count
            } else {
                tab -= line.filter( { $0 == "}" || $0 == ")" || $0 == "]" }).count
            }
            text += (0..<max(0, tab)).map { _ in "\t" }.joined() + line + "\n"
            if let separate = line.lastIndex(where: { $0 == "}" || $0 == ")" || $0 == "]" }) {
                tab += line[separate..<line.endIndex].filter( { $0 == "{" || $0 == "(" || $0 == "[" }).count
            } else {
                tab += line.filter( { $0 == "{" || $0 == "(" || $0 == "[" }).count
            }

        }
    }

    public func swich(a: String, b: String, tmp: String = "SYSTEM_REPLACE_STRING") {
        text = text.replacingOccurrences(of: a, with: tmp)
        text = text.replacingOccurrences(of: b, with: a)
        text = text.replacingOccurrences(of: tmp, with: b)
    }
}
