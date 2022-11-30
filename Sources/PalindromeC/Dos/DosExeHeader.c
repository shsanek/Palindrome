#include "DosExeHeader.h"

uint8_t dosExeHeaderDamp[528] = {
    0x4D, 0x8E, 0x17, 0x0F, 0x00, 0x75, 0x06, 0x3A, 0x06, 0x94, 0xD2, 0x74, 0x34, 0x00, 0x5B, 0x17,
    0x54, 0x4D, 0x50, 0x3D, 0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44, 0x4F, 0x57, 0x53, 0x5C, 0x54,
    0x45, 0x4D, 0x50, 0x00, 0x54, 0x45, 0x4D, 0x50, 0x3D, 0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44,
    0x4F, 0x57, 0x53, 0x5C, 0x54, 0x45, 0x4D, 0x50, 0x00, 0x50, 0x52, 0x4F, 0x4D, 0x50, 0x54, 0x3D,
    0x24, 0x70, 0x24, 0x67, 0x00, 0x77, 0x69, 0x6E, 0x62, 0x6F, 0x6F, 0x74, 0x64, 0x69, 0x72, 0x3D,
    0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44, 0x4F, 0x57, 0x53, 0x00, 0x50, 0x41, 0x54, 0x48, 0x3D,
    0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44, 0x4F, 0x57, 0x53, 0x3B, 0x43, 0x3A, 0x5C, 0x57, 0x49,
    0x4E, 0x44, 0x4F, 0x57, 0x53, 0x5C, 0x43, 0x4F, 0x4D, 0x4D, 0x41, 0x4E, 0x44, 0x00, 0x43, 0x4F,
    0x4D, 0x53, 0x50, 0x45, 0x43, 0x3D, 0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44, 0x4F, 0x57, 0x53,
    0x5C, 0x43, 0x4F, 0x4D, 0x4D, 0x41, 0x4E, 0x44, 0x2E, 0x43, 0x4F, 0x4D, 0x00, 0x77, 0x69, 0x6E,
    0x64, 0x69, 0x72, 0x3D, 0x43, 0x3A, 0x5C, 0x57, 0x49, 0x4E, 0x44, 0x4F, 0x57, 0x53, 0x00, 0x42,
    0x4C, 0x41, 0x53, 0x54, 0x45, 0x52, 0x3D, 0x41, 0x32, 0x32, 0x30, 0x20, 0x49, 0x35, 0x20, 0x44,
    0x31, 0x20, 0x48, 0x35, 0x20, 0x54, 0x36, 0x00, 0x43, 0x4D, 0x44, 0x4C, 0x49, 0x4E, 0x45, 0x3D,
    0x44, 0x45, 0x42, 0x55, 0x47, 0x20, 0x64, 0x3A, 0x5C, 0x64, 0x6F, 0x6F, 0x6D, 0x2E, 0x45, 0x58,
    0x45, 0x00, 0x00, 0x01, 0x00, 0x44, 0x3A, 0x5C, 0x44, 0x4F, 0x4F, 0x4D, 0x2E, 0x45, 0x58, 0x45,
    0x00, 0xFF, 0xCD, 0x21, 0x1F, 0x72, 0x0B, 0x8B, 0xD8, 0xB0, 0xFF, 0x86, 0x47, 0x18, 0xA2, 0x18,
    0x4D, 0x8E, 0x17, 0x1C, 0x0F, 0xD2, 0x00, 0x3D, 0x44, 0x4F, 0x4F, 0x4D, 0x00, 0xFF, 0x74, 0x06,
    0xCD, 0x20, 0xAA, 0x26, 0x00, 0x9A, 0xF0, 0xFE, 0x1D, 0xF0, 0x4F, 0x03, 0xF2, 0x10, 0x8A, 0x03,
    0xF2, 0x10, 0x17, 0x03, 0xF2, 0x10, 0xE1, 0x10, 0x01, 0x01, 0x01, 0x00, 0x02, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x17, 0x64, 0x3E,
    0xF2, 0x10, 0x14, 0x00, 0x18, 0x00, 0x8E, 0x17, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xCD, 0x21, 0xCB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0D, 0x64, 0x3A, 0x5C, 0x64, 0x6F, 0x6F, 0x6D, 0x2E, 0x45, 0x58, 0x45, 0x0D, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t dos02F0HeaderDamp[128] = {
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0,
    0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0, 0x53, 0xff, 0x00, 0xf0
};
