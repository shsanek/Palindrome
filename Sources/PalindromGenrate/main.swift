//
//  File.swift
//  
//
//  Created by Alex Shipin on 10/17/22.
//

import Foundation


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
//
//let callCommand = MachineCommand(
//    name: "Call",
//    command: .init(base: 0x00E8),
//    format: .init(
//        functioinType: .custom,
//        inlineElements: [],
//        arguments: [.init(name: "address", type: .address, size: .minMax(min: 16, big: 32))]
//    ),
//    functionFormat: """
//context->currentCallStack += 1;
//context->currentCallStack[0] = (void*)(context->index + %addressSize);
//context->index += read%addressSizeu(context);
//"""
//)
//
//let retCommand = MachineCommand(
//    name: "Ret",
//    command: .init(base: 0x00C3),
//    format: .init(
//        functioinType: .custom,
//        inlineElements: [],
//        arguments: [.init(name: "address", type: .address, size: .changeable)]
//    ),
//    functionFormat: """
//context->index = context->currentCallStack[0];
//context->currentCallStack += 1;
//"""
//)
//
//let imulCommand = MachineCommand(
//    name: "IMul",
//    command: .init(base: 0x01AF),
//    format: .init(
//        functioinType: .mrm,
//        inlineElements: [],
//        arguments: []
//    ),
//    functionFormat: "*(%dataType*)target *= *(%dataType*)source;"
//)
//
//
//let leaCommand = MachineCommand(
//    name: "Lea",
//    command: .init(base: 0x008D),
//    format: .init(
//        functioinType: .mrm,
//        inlineElements: [],
//        arguments: [],
//        fixedSize: .big
//    ),
//    functionFormat: "*(uint%dataSize_t*)target = (uint%dataSize_t)(((uint64_t)*(uint%dataSize_t*)source) - ((uint64_t)context->memory));"
//)
//
//let nopCommand = MachineCommand(
//    name: "Nop",
//    command: .init(base: 0x0090),
//    format: .init(
//        functioinType: .custom,
//        inlineElements: [],
//        arguments: []
//    ),
//    functionFormat: ""
//)
//
//let andCommand = MachineCommand(
//    name: "AND",
//    command: .init(base: 0x0080),
//    format: .init(
//        functioinType: .mnm(code: 0x04),
//        inlineElements: [
//            .init(name: "w", indexBit: 0, count: 1, recoverable: false),
//            .init(name: "s", indexBit: 1, count: 1, recoverable: false)
//        ],
//        arguments: []
//    ),
//    functionFormat: "*(%sTypeint%dataSize_t*)target &= (%sTypeint%dataSize_t)read%dataSize_t%sType(context);"
//)
//
//let subCommand = MachineCommand(
//    name: "SUB",
//    command: .init(base: 0x0080),
//    format: .init(
//        functioinType: .mnm(code: 0x05),
//        inlineElements: [
//            .init(name: "w", indexBit: 0, count: 1, recoverable: false),
//            .init(name: "s", indexBit: 1, count: 1, recoverable: false)
//        ],
//        arguments: []
//    ),
//    functionFormat: "*(%sTypeint%dataSize_t*)target -= (%sTypeint%dataSize_t)read%dataSize_t%sType(context);"
//)

generate()

