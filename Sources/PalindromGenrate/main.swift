//
//  File.swift
//  
//
//  Created by Alex Shipin on 10/17/22.
//

import Foundation

generate()

let mrm: String = generateMRMFunction(info: nil)
let mrmFile = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/PalindromeC/Base/MRM2.c"
try! mrm.write(toFile: mrmFile, atomically: true, encoding: .utf8)

print("GENERATE \(countCommand)")
