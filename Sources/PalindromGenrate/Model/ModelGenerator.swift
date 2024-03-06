indirect enum FieldType {
    case WORD
    case DWORD
    case BYTE
    case STRING(count: Int?)
    case submodel(model: Model)
    case array(type: FieldType, countMap: String)
}

extension FieldType {
    func cRead(in field: String, obj: String) -> String {
        switch self {
        case .STRING(let count):
            if let count = count {
                return """
                \(obj).\(field) = malloc(\(count));
                for (int i = 0; i < \(count); i++) {
                \(obj).\(field) = rawData[i];
                }
                rawData += \(count);
                """
            } else {
                return """
                int \(field)Count = 0;
                while (rawData[\(field)Count] != 0) {
                \(field)Count += 1;
                }
                \(obj).\(field) = malloc(\(field)Count + 1);
                for (int i = 0; i < \(field)Count; i++) {
                \(obj).\(field) = rawData[i];
                }
                \(obj).\(field)[\(field)Count] = 0;
                rawData += \(field)Count;
                """
            }
        case .WORD:
            return "\(obj).\(field) = *(\(cType)*)rawData; rawData += 2;"
        case .DWORD:
            return "\(obj).\(field) = *(\(cType)*)rawData; rawData += 4;"
        case .BYTE:
            return "\(obj).\(field) = *(\(cType)*)rawData; rawData += 1;"
        case .submodel(let model):
            return "\(obj).\(field) = Create\(model.name)(&rawData);"
        case .array(let type, let countMap):
            return """
            \(obj).\(field) = malloc(\(obj).\(countMap) * sizeof(\(type.cType)));
            for (int i = 0; i < \(obj).\(countMap); i++) {
            \(type.cRead(in: "\(field)[i]", obj: obj))
            }
            """
        }
    }

    func cFree(with field: String, obj: String) -> String {
        switch self {
        case .STRING:
            return "free(\(obj).\(field));"
        case .submodel(let model):
            return "Free\(model.name)(\(obj).\(field));"
        case .array(let type, let countMap):
            return """
            for (int i = 0; i < \(obj).\(countMap); i++) {
            \(type.cFree(with: "\(field)[i]", obj: obj))
            }
            free(\(obj).\(field));
            """
        default:
            return ""
        }
    }

    var cType: String {
        switch self {
        case .STRING:
            return "uint8_t*"
        case .WORD:
            return "uint16_t"
        case .DWORD:
            return "uint32_t"
        case .BYTE:
            return "uint8_t"
        case .submodel(let model):
            return "\(model.name)"
        case .array(let type, _):
            return "\(type.cType)*"
        }
    }
    var submodel: Model? {
        switch self {
        case .submodel(let model):
            return model
        case .array(let type, _):
            return type.submodel
        default:
            return nil
        }
    }
}

struct Field {
    let name: String
    let type: FieldType
    let comment: String
}

extension Field {
    static func WORD(_ name: String, comment: String = "") -> Self {
        .init(name: name, type: .WORD, comment: comment)
    }
    static func DWORD(_ name: String, comment: String = "") -> Self {
        .init(name: name, type: .DWORD, comment: comment)
    }
    static func BYTE(_ name: String, comment: String = "") -> Self {
        .init(name: name, type: .BYTE, comment: comment)
    }

    static func submodel(_ name: String, model: Model, comment: String = "") -> Self {
        .init(name: name, type: .submodel(model: model), comment: comment)
    }

    static func array(_ name: String, type: FieldType, countMap: String, comment: String = "") -> Self {
        .init(name: name, type: .array(type: type, countMap: countMap), comment: comment)
    }

    static func string(_ name: String, count: Int?, comment: String = "") -> Self {
        .init(name: name, type: .STRING(count: count), comment: comment)
    }
}

struct Model {
    let name: String
    let fields: [Field]
    let comment: String
}

extension Model {
    func allSubmodels() -> [Model] {
        var result = [Model]()
        for field in fields {
            if let model = field.type.submodel {
                result.append(contentsOf: model.allSubmodels())
            }
        }
        result.append(self)
        return result
    }
}

struct ModelGenerateResult {
    let interface: String
    let implementation: String
}

extension Model {
    func generateInterface() -> String {
        let model = self
        let generate = FunctionGenerator()
        generate.add("/// \(model.comment)")
        generate.add("typedef struct \(model.name) {")
        for field in model.fields {
            generate.add("/// \(field.comment)")
            generate.add("\(field.type.cType) \(field.name);")
        }
        generate.add("} \(model.name);")

        generate.add("\(model.name) Create\(model.name)(uint8_t **data);")
        generate.add("void Free\(model.name)(\(model.name) obj);")

        return generate.text
    }

    func generateImplementation() -> String {
        let model = self
        let generate = FunctionGenerator()
        generate.add("/// \(model.comment)")
        generate.add("\(model.name) Create\(model.name)(uint8_t **data) {")
        generate.add("uint8_t *rawData = *data;")
        generate.add("\(model.name) obj;")
        for field in model.fields {
            generate.add(field.type.cRead(in: field.name, obj: "obj"))
        }
        generate.add("*data = rawData;")
        generate.add("return obj;")
        generate.add("};")

        generate.add("void Free\(model.name)(\(model.name) obj) {")
        for field in model.fields {
            generate.add(field.type.cFree(with: field.name, obj: "obj"))
        }
        generate.add("};")

        return generate.text
    }
}

func generateModel(_ models: [Model]) -> [ModelGenerateResult] {
    let allModels = models.flatMap { $0.allSubmodels() }
    var result: [ModelGenerateResult] = [];
    for model in allModels {
        result.append(
            .init(
                interface: model.generateInterface(),
                implementation: model.generateImplementation()
            )
        )
    }
    return result
}

func saveModelInFile(models: [Model], file: String) throws {
    let h = file.appending(".h")
    let c = file.appending(".c")

    var hContent = """
    #ifndef WindowsNTHeader_h
    #define WindowsNTHeader_h

    #include <stdio.h>
    #include "WindowsHeader.h"

    """
    var cContent = """
    #include "\(h.components(separatedBy: "/").last!)"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    \n\n
    """

    for result in generateModel(models) {
        hContent.append(result.interface)
        cContent.append(result.implementation)

        hContent.append("\n")
        cContent.append("\n")
    }

    hContent.append("#endif")

    try hContent.write(toFile: h, atomically: true, encoding: .utf8)
    try cContent.write(toFile: c, atomically: true, encoding: .utf8)
}


func generatePEHeader() throws {
    let IMAGE_DATA_DIRECTORY = Model(
        name: "IMAGE_DATA_DIRECTORY",
        fields: [
            .DWORD("VirtualAddress"),
            .DWORD("Size")
        ],
        comment: ""
    )

    let IMAGE_OPTIONAL_HEADER32 = Model(
        name: "IMAGE_OPTIONAL_HEADER32",
        fields: [
            .WORD("Magic"),
            .BYTE("MajorLinkerVersion"),
            .BYTE("MinorLinkerVersion"),
            .DWORD("SizeOfCode"),
            .DWORD("SizeOfInitializedData"),
            .DWORD("SizeOfUninitializedData"),
            .DWORD("AddressOfEntryPoint"),
            .DWORD("BaseOfCode"),
            .DWORD("BaseOfData"),
            .DWORD("ImageBase"),
            .DWORD("SectionAlignment"),
            .DWORD("FileAlignment"),
            .WORD("MajorOperatingSystemVersion"),
            .WORD("MinorOperatingSystemVersion"),
            .WORD("MajorImageVersion"),
            .WORD("MinorImageVersion"),
            .WORD("MajorSubsystemVersion"),
            .WORD("MinorSubsystemVersion"),
            .DWORD("Win32VersionValue"),
            .DWORD("SizeOfImage"),
            .DWORD("SizeOfHeaders"),
            .DWORD("CheckSum"),
            .WORD("Subsystem"),
            .WORD("DllCharacteristics"),
            .DWORD("SizeOfStackReserve"),
            .DWORD("SizeOfStackCommit"),
            .DWORD("SizeOfHeapReserve"),
            .DWORD("SizeOfHeapCommit"),
            .DWORD("LoaderFlags"),
            .DWORD("NumberOfRvaAndSizes"),
            .array("DataDirectory", type: .submodel(model: IMAGE_DATA_DIRECTORY), countMap: "NumberOfRvaAndSizes")
        ],
        comment: ""
    )

    let IMAGE_FILE_HEADER = Model(
        name: "IMAGE_FILE_HEADER",
        fields: [
            .WORD("Machine", comment: "Архитектура процессора"),
            .WORD("NumberOfSections", comment: "Кол-во секций"),
            .DWORD("TimeDateStamp", comment: "Дата и время создания программы"),
            .DWORD("PointerToSymbolTable", comment: "Указатель на таблицу символов"),
            .DWORD("NumberOfSymbols", comment: "Число символов в таблицу"),
            .WORD("SizeOfOptionalHeader", comment: "Размер дополнительного заголовка"),
            .WORD("Characteristics", comment: "Характеристика")
        ],
        comment: ""
    )

    let IMAGE_NT_HEADERS32 = Model(
        name: "IMAGE_NT_HEADERS32",
        fields: [
            .DWORD("Signature", comment: "Сигнатура"),
            .submodel("FileHeader", model: IMAGE_FILE_HEADER, comment: "Файловый заголовка"),
            .submodel("OptionalHeader", model: IMAGE_OPTIONAL_HEADER32, comment: "Дополнительный")
        ],
        comment: ""
    )

    let IMAGE_SECTION_HEADER = Model(
        name: "IMAGE_SECTION_HEADER",
        fields: [
            .string("Name", count: 8),
            .DWORD("VirtualSize"),
            .DWORD("VirtualAddress"),
            .DWORD("SizeOfRawData"),
            .DWORD("PointerToRawData"),
            .DWORD("PointerToRelocations"),
            .DWORD("PointerToLinenumbers"),
            .WORD("NumberOfRelocations"),
            .WORD("NumberOfLinenumbers"),
            .DWORD("Characteristics")
        ],
        comment: ""
    )

    let WINDOWS_EXE_HEADER = Model(
        name: "WINDOWS_EXE_HEADER",
        fields: [
            .submodel("Header", model: IMAGE_NT_HEADERS32),
            .array("Sections", type: .submodel(model: IMAGE_SECTION_HEADER), countMap: "Header.FileHeader.NumberOfSections")
        ],
        comment: ""
    )

    let IMAGE_BASE_IMPORT_DESCRIPTOR = Model(
        name: "IMAGE_BASE_IMPORT_DESCRIPTOR",
        fields: [
            .DWORD("OriginalFirstThunk"),
            .DWORD("TimeDateStamp"),
            .DWORD("ForwarderChain"),
            .DWORD("Name"),
            .DWORD("FirstThunk")
        ],
        comment: ""
    )

    let IMAGE_DELAY_IMPORT_DESCRIPTOR = Model(
        name: "IMAGE_DELAY_IMPORT_DESCRIPTOR",
        fields: [
            .DWORD("grAttrs"),
            .DWORD("szName"),
            .DWORD("phmod"),
            .DWORD("pIAT"),
            .DWORD("pINT"),
            .DWORD("pBoundIAT"),
            .DWORD("pUnloadIAT"),
            .DWORD("dwTimeStamp")
        ],
        comment: ""
    )

    let IMAGE_BOUND_IMPORT_DESCRIPTOR = Model(
        name: "IMAGE_BOUND_IMPORT_DESCRIPTOR",
        fields: [
            .DWORD("TimeDataStamp"),
            .WORD("OffsetModuleName"),
            .WORD("NumberOfModuleForwarderRefs")
        ],
        comment: ""
    )

    let IMAGE_IMPORT_BY_NAME = Model(
        name: "IMAGE_IMPORT_BY_NAME",
        fields: [
            .WORD("Hint"),
            .string("Name", count: nil)
        ],
        comment: ""
    )

    let rootPath = "/Users/alexandershipin/Documents/projects/Palindrome/Sources/PalindromeC/Dos/Windows/"
    try saveModelInFile(
        models: [
            WINDOWS_EXE_HEADER,
            IMAGE_BASE_IMPORT_DESCRIPTOR,
            IMAGE_DELAY_IMPORT_DESCRIPTOR,
            IMAGE_BOUND_IMPORT_DESCRIPTOR
        ],
        file: rootPath + "ImageNT32Header"
    )
}
