import PalindromeC

extension Context {
    public var AL: Int8 {
        var muttable = self
        let pointer = UnsafeMutablePointer(&muttable)
        guard let result = register8(pointer, UInt8(BR_AL)) else {
            return 0
        }
        return result[0]
    }

    public var uAL: UInt8 {
        var muttable = self
        let pointer = UnsafeMutablePointer(&muttable)
        guard let result = register8u(pointer, UInt8(BR_AL)) else {
            return 0
        }
        return result[0]
    }
}
