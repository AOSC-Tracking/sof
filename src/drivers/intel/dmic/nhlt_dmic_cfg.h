#include <stdint.h>

#if 1
/* Dell 2ch 32 bit 38400 MHz system */
const uint8_t nhlt_dmic_cfg[3049] = {
	0x10, 0xff, 0xff, 0xff, 0x10, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
	0x03, 0x00, 0x38, 0x00, 0x03, 0x00, 0x38, 0x00,
	0x03, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00,
	0x03, 0x18, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0x76, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0xe8, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x40,
	0x81, 0x01, 0x40, 0x40, 0x6d, 0x03, 0x80, 0x40,
	0x53, 0x04, 0xc0, 0x40, 0x78, 0x02, 0x00, 0x41,
	0x19, 0xff, 0x4f, 0x41, 0xed, 0xfd, 0x8f, 0x41,
	0x37, 0x00, 0xc0, 0x41, 0x45, 0x02, 0x00, 0x42,
	0x8c, 0x00, 0x40, 0x42, 0x9b, 0xfd, 0x8f, 0x42,
	0x9d, 0xfe, 0xcf, 0x42, 0x6c, 0x02, 0x00, 0x43,
	0x67, 0x02, 0x40, 0x43, 0xb1, 0xfd, 0x8f, 0x43,
	0x25, 0xfc, 0xcf, 0x43, 0x6f, 0x01, 0x00, 0x44,
	0x21, 0x05, 0x40, 0x44, 0xf3, 0xff, 0x8f, 0x44,
	0xc4, 0xf9, 0xcf, 0x44, 0xf9, 0xfd, 0x0f, 0x45,
	0xbf, 0x06, 0x40, 0x45, 0x8e, 0x04, 0x80, 0x45,
	0x73, 0xf9, 0xcf, 0x45, 0x96, 0xf8, 0x0f, 0x46,
	0x72, 0x05, 0x40, 0x46, 0x69, 0x0a, 0x80, 0x46,
	0xcf, 0xfc, 0xcf, 0x46, 0xd1, 0xf2, 0x0f, 0x47,
	0xa4, 0xff, 0x4f, 0x47, 0x25, 0x0f, 0x80, 0x47,
	0xfc, 0x04, 0xc0, 0x47, 0x13, 0xf0, 0x0f, 0x48,
	0x93, 0xf5, 0x4f, 0x48, 0x33, 0x0f, 0x80, 0x48,
	0x68, 0x10, 0xc0, 0x48, 0x75, 0xf3, 0x0f, 0x49,
	0x99, 0xe9, 0x4f, 0x49, 0xa2, 0x07, 0x80, 0x49,
	0x90, 0x1b, 0xc0, 0x49, 0x65, 0xff, 0x0f, 0x4a,
	0xc2, 0xe0, 0x4f, 0x4a, 0x99, 0xf7, 0x8f, 0x4a,
	0x92, 0x20, 0xc0, 0x4a, 0xc4, 0x12, 0x00, 0x4b,
	0x03, 0xe1, 0x4f, 0x4b, 0x2c, 0xe2, 0x8f, 0x4b,
	0xf2, 0x19, 0xc0, 0x4b, 0xa3, 0x28, 0x00, 0x4c,
	0xf5, 0xee, 0x4f, 0x4c, 0x29, 0xce, 0x8f, 0x4c,
	0x84, 0x04, 0xc0, 0x4c, 0x40, 0x38, 0x00, 0x4d,
	0x2c, 0x0b, 0x40, 0x4d, 0x5e, 0xc5, 0x8f, 0x4d,
	0xe9, 0xe2, 0xcf, 0x4d, 0xf5, 0x37, 0x00, 0x4e,
	0xf8, 0x2f, 0x40, 0x4e, 0x92, 0xd0, 0x8f, 0x4e,
	0xe1, 0xbd, 0xcf, 0x4e, 0xdd, 0x20, 0x00, 0x4f,
	0x18, 0x52, 0x40, 0x4f, 0x4f, 0xf4, 0x8f, 0x4f,
	0xb2, 0xa2, 0xcf, 0x4f, 0x4d, 0xf0, 0x0f, 0x50,
	0x08, 0x60, 0x40, 0x50, 0x78, 0x2d, 0x80, 0x50,
	0x80, 0xa5, 0xcf, 0x50, 0x54, 0xb3, 0x0f, 0x51,
	0x82, 0x4a, 0x40, 0x51, 0xa2, 0x69, 0x80, 0x51,
	0x00, 0xd0, 0xcf, 0x51, 0xf5, 0x7e, 0x0f, 0x52,
	0x5c, 0x0b, 0x40, 0x52, 0xcf, 0x8e, 0x80, 0x52,
	0x52, 0x21, 0xc0, 0x52, 0xdc, 0x70, 0x0f, 0x53,
	0x96, 0xad, 0x4f, 0x53, 0x06, 0x7f, 0x80, 0x53,
	0xc7, 0x82, 0xc0, 0x53, 0x0a, 0xa3, 0x0f, 0x54,
	0x8d, 0x53, 0x4f, 0x54, 0xc1, 0x28, 0x80, 0x54,
	0x14, 0xc8, 0xc0, 0x54, 0x21, 0x1b, 0x00, 0x55,
	0x23, 0x32, 0x4f, 0x55, 0x41, 0x97, 0x8f, 0x55,
	0xf2, 0xb6, 0xc0, 0x55, 0x87, 0xb6, 0x00, 0x56,
	0x02, 0x81, 0x4f, 0x56, 0x43, 0x08, 0x8f, 0x56,
	0x34, 0x25, 0xc0, 0x56, 0x19, 0x1c, 0x01, 0x57,
	0x7e, 0x50, 0x40, 0x57, 0x24, 0xee, 0x8e, 0x57,
	0xfd, 0x2c, 0xcf, 0x57, 0x1c, 0xc9, 0x00, 0x58,
	0x71, 0x47, 0x41, 0x58, 0x01, 0xc6, 0x8f, 0x58,
	0xba, 0x79, 0xce, 0x58, 0x6b, 0x6e, 0x0f, 0x59,
	0xbe, 0x5e, 0x41, 0x59, 0x00, 0x70, 0x81, 0x59,
	0x76, 0x5b, 0xcf, 0x59, 0x77, 0xf7, 0x0d, 0x5a,
	0xac, 0x51, 0x4f, 0x5a, 0x09, 0xcf, 0x81, 0x5a,
	0x53, 0x36, 0xc2, 0x5a, 0x37, 0xce, 0x0f, 0x5b,
	0xa8, 0x3d, 0x4d, 0x5b, 0xb8, 0x65, 0x8d, 0x5b,
	0xef, 0x50, 0xc0, 0x5b, 0x37, 0x8e, 0x03, 0x5c,
	0xb2, 0xe2, 0x44, 0x5c, 0xa5, 0x11, 0x84, 0x5c,
	0xa3, 0x59, 0xc2, 0x5c, 0x48, 0xf2, 0x00, 0x5d,
	0x0e, 0x3f, 0x40, 0x5d, 0x39, 0x08, 0x80, 0x5d,
	0x1b, 0x00, 0x00, 0x80, 0x18, 0x00, 0x40, 0x80,
	0x0a, 0x00, 0x80, 0x80, 0xd7, 0xff, 0xcf, 0x80,
	0x67, 0xff, 0x0f, 0x81, 0xa2, 0xfe, 0x4f, 0x81,
	0x76, 0xfd, 0x8f, 0x81, 0xdd, 0xfb, 0xcf, 0x81,
	0xe2, 0xf9, 0x0f, 0x82, 0xa8, 0xf7, 0x4f, 0x82,
	0x67, 0xf5, 0x8f, 0x82, 0x6c, 0xf3, 0xcf, 0x82,
	0x0b, 0xf2, 0x0f, 0x83, 0x97, 0xf1, 0x4f, 0x83,
	0x4a, 0xf2, 0x8f, 0x83, 0x3b, 0xf4, 0xcf, 0x83,
	0x51, 0xf7, 0x0f, 0x84, 0x3f, 0xfb, 0x4f, 0x84,
	0x88, 0xff, 0x8f, 0x84, 0x92, 0x03, 0xc0, 0x84,
	0xc0, 0x06, 0x00, 0x85, 0x8b, 0x08, 0x40, 0x85,
	0xa2, 0x08, 0x80, 0x85, 0xfd, 0x06, 0xc0, 0x85,
	0xe9, 0x03, 0x00, 0x86, 0xfc, 0xff, 0x4f, 0x86,
	0xff, 0xfb, 0x8f, 0x86, 0xc8, 0xf8, 0xcf, 0x86,
	0x0f, 0xf7, 0x0f, 0x87, 0x45, 0xf7, 0x4f, 0x87,
	0x75, 0xf9, 0x8f, 0x87, 0x3d, 0xfd, 0xcf, 0x87,
	0xda, 0x01, 0x00, 0x88, 0x4c, 0x06, 0x40, 0x88,
	0x8f, 0x09, 0x80, 0x88, 0xd0, 0x0a, 0xc0, 0x88,
	0xa4, 0x09, 0x00, 0x89, 0x27, 0x06, 0x40, 0x89,
	0xff, 0x00, 0x80, 0x89, 0x43, 0xfb, 0xcf, 0x89,
	0x3c, 0xf6, 0x0f, 0x8a, 0x26, 0xf3, 0x4f, 0x8a,
	0xdd, 0xf2, 0x8f, 0x8a, 0xa5, 0xf5, 0xcf, 0x8a,
	0x11, 0xfb, 0x0f, 0x8b, 0x0c, 0x02, 0x40, 0x8b,
	0x0e, 0x09, 0x80, 0x8b, 0x72, 0x0e, 0xc0, 0x8b,
	0xd3, 0x10, 0x00, 0x8c, 0x69, 0x0f, 0x40, 0x8c,
	0x42, 0x0a, 0x80, 0x8c, 0x4f, 0x02, 0xc0, 0x8c,
	0x3e, 0xf9, 0x0f, 0x8d, 0x20, 0xf1, 0x4f, 0x8d,
	0xf1, 0xeb, 0x8f, 0x8d, 0x25, 0xeb, 0xcf, 0x8d,
	0x3d, 0xef, 0x0f, 0x8e, 0x9d, 0xf7, 0x4f, 0x8e,
	0x96, 0x02, 0x80, 0x8e, 0xbd, 0x0d, 0xc0, 0x8e,
	0x6d, 0x16, 0x00, 0x8f, 0x67, 0x1a, 0x40, 0x8f,
	0x5f, 0x18, 0x80, 0x8f, 0x61, 0x10, 0xc0, 0x8f,
	0xe4, 0x03, 0x00, 0x90, 0x8f, 0xf5, 0x4f, 0x90,
	0xab, 0xe8, 0x8f, 0x90, 0x66, 0xe0, 0xcf, 0x90,
	0x12, 0xdf, 0x0f, 0x91, 0x83, 0xe5, 0x4f, 0x91,
	0xc3, 0xf2, 0x8f, 0x91, 0x27, 0x04, 0xc0, 0x91,
	0xd6, 0x15, 0x00, 0x92, 0x99, 0x23, 0x40, 0x92,
	0xd9, 0x29, 0x80, 0x92, 0x84, 0x26, 0xc0, 0x92,
	0xaa, 0x19, 0x00, 0x93, 0xa6, 0x05, 0x40, 0x93,
	0xb6, 0xee, 0x8f, 0x93, 0x21, 0xda, 0xcf, 0x93,
	0x09, 0xcd, 0x0f, 0x94, 0x2c, 0xcb, 0x4f, 0x94,
	0xe8, 0xd5, 0x8f, 0x94, 0xb1, 0xeb, 0xcf, 0x94,
	0x38, 0x08, 0x00, 0x95, 0x31, 0x25, 0x40, 0x95,
	0xaf, 0x3b, 0x80, 0x95, 0xb6, 0x45, 0xc0, 0x95,
	0xc0, 0x3f, 0x00, 0x96, 0xc6, 0x29, 0x40, 0x96,
	0x99, 0x07, 0x80, 0x96, 0x4c, 0xe0, 0xcf, 0x96,
	0xdb, 0xbc, 0x0f, 0x97, 0x3a, 0xa6, 0x4f, 0x97,
	0x39, 0xa3, 0x8f, 0x97, 0xaf, 0xb6, 0xcf, 0x97,
	0x6d, 0xde, 0x0f, 0x98, 0x33, 0x13, 0x40, 0x98,
	0xd5, 0x49, 0x80, 0x98, 0x5a, 0x75, 0xc0, 0x98,
	0xc4, 0x89, 0x00, 0x99, 0xed, 0x7e, 0x40, 0x99,
	0xd5, 0x52, 0x80, 0x99, 0xe7, 0x0a, 0xc0, 0x99,
	0xcc, 0xb3, 0x0f, 0x9a, 0xb8, 0x5f, 0x4f, 0x9a,
	0x67, 0x23, 0x8f, 0x9a, 0x59, 0x12, 0xcf, 0x9a,
	0xea, 0x3a, 0x0f, 0x9b, 0x13, 0xa3, 0x4f, 0x9b,
	0x87, 0x46, 0x80, 0x9b, 0x8b, 0x16, 0xc1, 0x9b,
	0xbc, 0xfb, 0x01, 0x9c, 0x6f, 0xd9, 0x42, 0x9c,
	0x33, 0x92, 0x83, 0x9c, 0x98, 0x0c, 0xc4, 0x9c,
	0x6b, 0x37, 0x04, 0x9d, 0x98, 0x0c, 0x44, 0x9d,
	0x33, 0x92, 0x83, 0x9d, 0x6f, 0xd9, 0xc2, 0x9d,
	0xbc, 0xfb, 0x01, 0x9e, 0x8b, 0x16, 0x41, 0x9e,
	0x87, 0x46, 0x80, 0x9e, 0x13, 0xa3, 0xcf, 0x9e,
	0xea, 0x3a, 0x0f, 0x9f, 0x59, 0x12, 0x4f, 0x9f,
	0x67, 0x23, 0x8f, 0x9f, 0xb8, 0x5f, 0xcf, 0x9f,
	0xcc, 0xb3, 0x0f, 0xa0, 0xe7, 0x0a, 0x40, 0xa0,
	0xd5, 0x52, 0x80, 0xa0, 0xed, 0x7e, 0xc0, 0xa0,
	0xc4, 0x89, 0x00, 0xa1, 0x5a, 0x75, 0x40, 0xa1,
	0xd5, 0x49, 0x80, 0xa1, 0x33, 0x13, 0xc0, 0xa1,
	0x6d, 0xde, 0x0f, 0xa2, 0xaf, 0xb6, 0x4f, 0xa2,
	0x39, 0xa3, 0x8f, 0xa2, 0x3a, 0xa6, 0xcf, 0xa2,
	0xdb, 0xbc, 0x0f, 0xa3, 0x4c, 0xe0, 0x4f, 0xa3,
	0x99, 0x07, 0x80, 0xa3, 0xc6, 0x29, 0xc0, 0xa3,
	0xc0, 0x3f, 0x00, 0xa4, 0xb6, 0x45, 0x40, 0xa4,
	0xaf, 0x3b, 0x80, 0xa4, 0x31, 0x25, 0xc0, 0xa4,
	0x38, 0x08, 0x00, 0xa5, 0xb1, 0xeb, 0x4f, 0xa5,
	0xe8, 0xd5, 0x8f, 0xa5, 0x2c, 0xcb, 0xcf, 0xa5,
	0x09, 0xcd, 0x0f, 0xa6, 0x21, 0xda, 0x4f, 0xa6,
	0xb6, 0xee, 0x8f, 0xa6, 0xa6, 0x05, 0xc0, 0xa6,
	0xaa, 0x19, 0x00, 0xa7, 0x84, 0x26, 0x40, 0xa7,
	0xd9, 0x29, 0x80, 0xa7, 0x99, 0x23, 0xc0, 0xa7,
	0xd6, 0x15, 0x00, 0xa8, 0x27, 0x04, 0x40, 0xa8,
	0xc3, 0xf2, 0x8f, 0xa8, 0x83, 0xe5, 0xcf, 0xa8,
	0x12, 0xdf, 0x0f, 0xa9, 0x66, 0xe0, 0x4f, 0xa9,
	0xab, 0xe8, 0x8f, 0xa9, 0x8f, 0xf5, 0xcf, 0xa9,
	0xe4, 0x03, 0x00, 0xaa, 0x61, 0x10, 0x40, 0xaa,
	0x5f, 0x18, 0x80, 0xaa, 0x67, 0x1a, 0xc0, 0xaa,
	0x6d, 0x16, 0x00, 0xab, 0xbd, 0x0d, 0x40, 0xab,
	0x96, 0x02, 0x80, 0xab, 0x9d, 0xf7, 0xcf, 0xab,
	0x3d, 0xef, 0x0f, 0xac, 0x25, 0xeb, 0x4f, 0xac,
	0xf1, 0xeb, 0x8f, 0xac, 0x20, 0xf1, 0xcf, 0xac,
	0x3e, 0xf9, 0x0f, 0xad, 0x4f, 0x02, 0x40, 0xad,
	0x42, 0x0a, 0x80, 0xad, 0x69, 0x0f, 0xc0, 0xad,
	0xd3, 0x10, 0x00, 0xae, 0x72, 0x0e, 0x40, 0xae,
	0x0e, 0x09, 0x80, 0xae, 0x0c, 0x02, 0xc0, 0xae,
	0x11, 0xfb, 0x0f, 0xaf, 0xa5, 0xf5, 0x4f, 0xaf,
	0xdd, 0xf2, 0x8f, 0xaf, 0x26, 0xf3, 0xcf, 0xaf,
	0x3c, 0xf6, 0x0f, 0xb0, 0x43, 0xfb, 0x4f, 0xb0,
	0xff, 0x00, 0x80, 0xb0, 0x27, 0x06, 0xc0, 0xb0,
	0xa4, 0x09, 0x00, 0xb1, 0xd0, 0x0a, 0x40, 0xb1,
	0x8f, 0x09, 0x80, 0xb1, 0x4c, 0x06, 0xc0, 0xb1,
	0xda, 0x01, 0x00, 0xb2, 0x3d, 0xfd, 0x4f, 0xb2,
	0x75, 0xf9, 0x8f, 0xb2, 0x45, 0xf7, 0xcf, 0xb2,
	0x0f, 0xf7, 0x0f, 0xb3, 0xc8, 0xf8, 0x4f, 0xb3,
	0xff, 0xfb, 0x8f, 0xb3, 0xfc, 0xff, 0xcf, 0xb3,
	0xe9, 0x03, 0x00, 0xb4, 0xfd, 0x06, 0x40, 0xb4,
	0xa2, 0x08, 0x80, 0xb4, 0x8b, 0x08, 0xc0, 0xb4,
	0xc0, 0x06, 0x00, 0xb5, 0x92, 0x03, 0x40, 0xb5,
	0x88, 0xff, 0x8f, 0xb5, 0x3f, 0xfb, 0xcf, 0xb5,
	0x51, 0xf7, 0x0f, 0xb6, 0x3b, 0xf4, 0x4f, 0xb6,
	0x4a, 0xf2, 0x8f, 0xb6, 0x97, 0xf1, 0xcf, 0xb6,
	0x0b, 0xf2, 0x0f, 0xb7, 0x6c, 0xf3, 0x4f, 0xb7,
	0x67, 0xf5, 0x8f, 0xb7, 0xa8, 0xf7, 0xcf, 0xb7,
	0xe2, 0xf9, 0x0f, 0xb8, 0xdd, 0xfb, 0x4f, 0xb8,
	0x76, 0xfd, 0x8f, 0xb8, 0xa2, 0xfe, 0xcf, 0xb8,
	0x67, 0xff, 0x0f, 0xb9, 0xd7, 0xff, 0x4f, 0xb9,
	0x0a, 0x00, 0x80, 0xb9, 0x18, 0x00, 0xc0, 0xb9,
	0x1b, 0x00, 0x00, 0xba, 0x01, 0xc0, 0x00, 0x00,
	0x03, 0x18, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0x76, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0xe8, 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0x00, 0x40,
	0x81, 0x01, 0x40, 0x40, 0x6d, 0x03, 0x80, 0x40,
	0x53, 0x04, 0xc0, 0x40, 0x78, 0x02, 0x00, 0x41,
	0x19, 0xff, 0x4f, 0x41, 0xed, 0xfd, 0x8f, 0x41,
	0x37, 0x00, 0xc0, 0x41, 0x45, 0x02, 0x00, 0x42,
	0x8c, 0x00, 0x40, 0x42, 0x9b, 0xfd, 0x8f, 0x42,
	0x9d, 0xfe, 0xcf, 0x42, 0x6c, 0x02, 0x00, 0x43,
	0x67, 0x02, 0x40, 0x43, 0xb1, 0xfd, 0x8f, 0x43,
	0x25, 0xfc, 0xcf, 0x43, 0x6f, 0x01, 0x00, 0x44,
	0x21, 0x05, 0x40, 0x44, 0xf3, 0xff, 0x8f, 0x44,
	0xc4, 0xf9, 0xcf, 0x44, 0xf9, 0xfd, 0x0f, 0x45,
	0xbf, 0x06, 0x40, 0x45, 0x8e, 0x04, 0x80, 0x45,
	0x73, 0xf9, 0xcf, 0x45, 0x96, 0xf8, 0x0f, 0x46,
	0x72, 0x05, 0x40, 0x46, 0x69, 0x0a, 0x80, 0x46,
	0xcf, 0xfc, 0xcf, 0x46, 0xd1, 0xf2, 0x0f, 0x47,
	0xa4, 0xff, 0x4f, 0x47, 0x25, 0x0f, 0x80, 0x47,
	0xfc, 0x04, 0xc0, 0x47, 0x13, 0xf0, 0x0f, 0x48,
	0x93, 0xf5, 0x4f, 0x48, 0x33, 0x0f, 0x80, 0x48,
	0x68, 0x10, 0xc0, 0x48, 0x75, 0xf3, 0x0f, 0x49,
	0x99, 0xe9, 0x4f, 0x49, 0xa2, 0x07, 0x80, 0x49,
	0x90, 0x1b, 0xc0, 0x49, 0x65, 0xff, 0x0f, 0x4a,
	0xc2, 0xe0, 0x4f, 0x4a, 0x99, 0xf7, 0x8f, 0x4a,
	0x92, 0x20, 0xc0, 0x4a, 0xc4, 0x12, 0x00, 0x4b,
	0x03, 0xe1, 0x4f, 0x4b, 0x2c, 0xe2, 0x8f, 0x4b,
	0xf2, 0x19, 0xc0, 0x4b, 0xa3, 0x28, 0x00, 0x4c,
	0xf5, 0xee, 0x4f, 0x4c, 0x29, 0xce, 0x8f, 0x4c,
	0x84, 0x04, 0xc0, 0x4c, 0x40, 0x38, 0x00, 0x4d,
	0x2c, 0x0b, 0x40, 0x4d, 0x5e, 0xc5, 0x8f, 0x4d,
	0xe9, 0xe2, 0xcf, 0x4d, 0xf5, 0x37, 0x00, 0x4e,
	0xf8, 0x2f, 0x40, 0x4e, 0x92, 0xd0, 0x8f, 0x4e,
	0xe1, 0xbd, 0xcf, 0x4e, 0xdd, 0x20, 0x00, 0x4f,
	0x18, 0x52, 0x40, 0x4f, 0x4f, 0xf4, 0x8f, 0x4f,
	0xb2, 0xa2, 0xcf, 0x4f, 0x4d, 0xf0, 0x0f, 0x50,
	0x08, 0x60, 0x40, 0x50, 0x78, 0x2d, 0x80, 0x50,
	0x80, 0xa5, 0xcf, 0x50, 0x54, 0xb3, 0x0f, 0x51,
	0x82, 0x4a, 0x40, 0x51, 0xa2, 0x69, 0x80, 0x51,
	0x00, 0xd0, 0xcf, 0x51, 0xf5, 0x7e, 0x0f, 0x52,
	0x5c, 0x0b, 0x40, 0x52, 0xcf, 0x8e, 0x80, 0x52,
	0x52, 0x21, 0xc0, 0x52, 0xdc, 0x70, 0x0f, 0x53,
	0x96, 0xad, 0x4f, 0x53, 0x06, 0x7f, 0x80, 0x53,
	0xc7, 0x82, 0xc0, 0x53, 0x0a, 0xa3, 0x0f, 0x54,
	0x8d, 0x53, 0x4f, 0x54, 0xc1, 0x28, 0x80, 0x54,
	0x14, 0xc8, 0xc0, 0x54, 0x21, 0x1b, 0x00, 0x55,
	0x23, 0x32, 0x4f, 0x55, 0x41, 0x97, 0x8f, 0x55,
	0xf2, 0xb6, 0xc0, 0x55, 0x87, 0xb6, 0x00, 0x56,
	0x02, 0x81, 0x4f, 0x56, 0x43, 0x08, 0x8f, 0x56,
	0x34, 0x25, 0xc0, 0x56, 0x19, 0x1c, 0x01, 0x57,
	0x7e, 0x50, 0x40, 0x57, 0x24, 0xee, 0x8e, 0x57,
	0xfd, 0x2c, 0xcf, 0x57, 0x1c, 0xc9, 0x00, 0x58,
	0x71, 0x47, 0x41, 0x58, 0x01, 0xc6, 0x8f, 0x58,
	0xba, 0x79, 0xce, 0x58, 0x6b, 0x6e, 0x0f, 0x59,
	0xbe, 0x5e, 0x41, 0x59, 0x00, 0x70, 0x81, 0x59,
	0x76, 0x5b, 0xcf, 0x59, 0x77, 0xf7, 0x0d, 0x5a,
	0xac, 0x51, 0x4f, 0x5a, 0x09, 0xcf, 0x81, 0x5a,
	0x53, 0x36, 0xc2, 0x5a, 0x37, 0xce, 0x0f, 0x5b,
	0xa8, 0x3d, 0x4d, 0x5b, 0xb8, 0x65, 0x8d, 0x5b,
	0xef, 0x50, 0xc0, 0x5b, 0x37, 0x8e, 0x03, 0x5c,
	0xb2, 0xe2, 0x44, 0x5c, 0xa5, 0x11, 0x84, 0x5c,
	0xa3, 0x59, 0xc2, 0x5c, 0x48, 0xf2, 0x00, 0x5d,
	0x0e, 0x3f, 0x40, 0x5d, 0x39, 0x08, 0x80, 0x5d,
	0x1b, 0x00, 0x00, 0x80, 0x18, 0x00, 0x40, 0x80,
	0x0a, 0x00, 0x80, 0x80, 0xd7, 0xff, 0xcf, 0x80,
	0x67, 0xff, 0x0f, 0x81, 0xa2, 0xfe, 0x4f, 0x81,
	0x76, 0xfd, 0x8f, 0x81, 0xdd, 0xfb, 0xcf, 0x81,
	0xe2, 0xf9, 0x0f, 0x82, 0xa8, 0xf7, 0x4f, 0x82,
	0x67, 0xf5, 0x8f, 0x82, 0x6c, 0xf3, 0xcf, 0x82,
	0x0b, 0xf2, 0x0f, 0x83, 0x97, 0xf1, 0x4f, 0x83,
	0x4a, 0xf2, 0x8f, 0x83, 0x3b, 0xf4, 0xcf, 0x83,
	0x51, 0xf7, 0x0f, 0x84, 0x3f, 0xfb, 0x4f, 0x84,
	0x88, 0xff, 0x8f, 0x84, 0x92, 0x03, 0xc0, 0x84,
	0xc0, 0x06, 0x00, 0x85, 0x8b, 0x08, 0x40, 0x85,
	0xa2, 0x08, 0x80, 0x85, 0xfd, 0x06, 0xc0, 0x85,
	0xe9, 0x03, 0x00, 0x86, 0xfc, 0xff, 0x4f, 0x86,
	0xff, 0xfb, 0x8f, 0x86, 0xc8, 0xf8, 0xcf, 0x86,
	0x0f, 0xf7, 0x0f, 0x87, 0x45, 0xf7, 0x4f, 0x87,
	0x75, 0xf9, 0x8f, 0x87, 0x3d, 0xfd, 0xcf, 0x87,
	0xda, 0x01, 0x00, 0x88, 0x4c, 0x06, 0x40, 0x88,
	0x8f, 0x09, 0x80, 0x88, 0xd0, 0x0a, 0xc0, 0x88,
	0xa4, 0x09, 0x00, 0x89, 0x27, 0x06, 0x40, 0x89,
	0xff, 0x00, 0x80, 0x89, 0x43, 0xfb, 0xcf, 0x89,
	0x3c, 0xf6, 0x0f, 0x8a, 0x26, 0xf3, 0x4f, 0x8a,
	0xdd, 0xf2, 0x8f, 0x8a, 0xa5, 0xf5, 0xcf, 0x8a,
	0x11, 0xfb, 0x0f, 0x8b, 0x0c, 0x02, 0x40, 0x8b,
	0x0e, 0x09, 0x80, 0x8b, 0x72, 0x0e, 0xc0, 0x8b,
	0xd3, 0x10, 0x00, 0x8c, 0x69, 0x0f, 0x40, 0x8c,
	0x42, 0x0a, 0x80, 0x8c, 0x4f, 0x02, 0xc0, 0x8c,
	0x3e, 0xf9, 0x0f, 0x8d, 0x20, 0xf1, 0x4f, 0x8d,
	0xf1, 0xeb, 0x8f, 0x8d, 0x25, 0xeb, 0xcf, 0x8d,
	0x3d, 0xef, 0x0f, 0x8e, 0x9d, 0xf7, 0x4f, 0x8e,
	0x96, 0x02, 0x80, 0x8e, 0xbd, 0x0d, 0xc0, 0x8e,
	0x6d, 0x16, 0x00, 0x8f, 0x67, 0x1a, 0x40, 0x8f,
	0x5f, 0x18, 0x80, 0x8f, 0x61, 0x10, 0xc0, 0x8f,
	0xe4, 0x03, 0x00, 0x90, 0x8f, 0xf5, 0x4f, 0x90,
	0xab, 0xe8, 0x8f, 0x90, 0x66, 0xe0, 0xcf, 0x90,
	0x12, 0xdf, 0x0f, 0x91, 0x83, 0xe5, 0x4f, 0x91,
	0xc3, 0xf2, 0x8f, 0x91, 0x27, 0x04, 0xc0, 0x91,
	0xd6, 0x15, 0x00, 0x92, 0x99, 0x23, 0x40, 0x92,
	0xd9, 0x29, 0x80, 0x92, 0x84, 0x26, 0xc0, 0x92,
	0xaa, 0x19, 0x00, 0x93, 0xa6, 0x05, 0x40, 0x93,
	0xb6, 0xee, 0x8f, 0x93, 0x21, 0xda, 0xcf, 0x93,
	0x09, 0xcd, 0x0f, 0x94, 0x2c, 0xcb, 0x4f, 0x94,
	0xe8, 0xd5, 0x8f, 0x94, 0xb1, 0xeb, 0xcf, 0x94,
	0x38, 0x08, 0x00, 0x95, 0x31, 0x25, 0x40, 0x95,
	0xaf, 0x3b, 0x80, 0x95, 0xb6, 0x45, 0xc0, 0x95,
	0xc0, 0x3f, 0x00, 0x96, 0xc6, 0x29, 0x40, 0x96,
	0x99, 0x07, 0x80, 0x96, 0x4c, 0xe0, 0xcf, 0x96,
	0xdb, 0xbc, 0x0f, 0x97, 0x3a, 0xa6, 0x4f, 0x97,
	0x39, 0xa3, 0x8f, 0x97, 0xaf, 0xb6, 0xcf, 0x97,
	0x6d, 0xde, 0x0f, 0x98, 0x33, 0x13, 0x40, 0x98,
	0xd5, 0x49, 0x80, 0x98, 0x5a, 0x75, 0xc0, 0x98,
	0xc4, 0x89, 0x00, 0x99, 0xed, 0x7e, 0x40, 0x99,
	0xd5, 0x52, 0x80, 0x99, 0xe7, 0x0a, 0xc0, 0x99,
	0xcc, 0xb3, 0x0f, 0x9a, 0xb8, 0x5f, 0x4f, 0x9a,
	0x67, 0x23, 0x8f, 0x9a, 0x59, 0x12, 0xcf, 0x9a,
	0xea, 0x3a, 0x0f, 0x9b, 0x13, 0xa3, 0x4f, 0x9b,
	0x87, 0x46, 0x80, 0x9b, 0x8b, 0x16, 0xc1, 0x9b,
	0xbc, 0xfb, 0x01, 0x9c, 0x6f, 0xd9, 0x42, 0x9c,
	0x33, 0x92, 0x83, 0x9c, 0x98, 0x0c, 0xc4, 0x9c,
	0x6b, 0x37, 0x04, 0x9d, 0x98, 0x0c, 0x44, 0x9d,
	0x33, 0x92, 0x83, 0x9d, 0x6f, 0xd9, 0xc2, 0x9d,
	0xbc, 0xfb, 0x01, 0x9e, 0x8b, 0x16, 0x41, 0x9e,
	0x87, 0x46, 0x80, 0x9e, 0x13, 0xa3, 0xcf, 0x9e,
	0xea, 0x3a, 0x0f, 0x9f, 0x59, 0x12, 0x4f, 0x9f,
	0x67, 0x23, 0x8f, 0x9f, 0xb8, 0x5f, 0xcf, 0x9f,
	0xcc, 0xb3, 0x0f, 0xa0, 0xe7, 0x0a, 0x40, 0xa0,
	0xd5, 0x52, 0x80, 0xa0, 0xed, 0x7e, 0xc0, 0xa0,
	0xc4, 0x89, 0x00, 0xa1, 0x5a, 0x75, 0x40, 0xa1,
	0xd5, 0x49, 0x80, 0xa1, 0x33, 0x13, 0xc0, 0xa1,
	0x6d, 0xde, 0x0f, 0xa2, 0xaf, 0xb6, 0x4f, 0xa2,
	0x39, 0xa3, 0x8f, 0xa2, 0x3a, 0xa6, 0xcf, 0xa2,
	0xdb, 0xbc, 0x0f, 0xa3, 0x4c, 0xe0, 0x4f, 0xa3,
	0x99, 0x07, 0x80, 0xa3, 0xc6, 0x29, 0xc0, 0xa3,
	0xc0, 0x3f, 0x00, 0xa4, 0xb6, 0x45, 0x40, 0xa4,
	0xaf, 0x3b, 0x80, 0xa4, 0x31, 0x25, 0xc0, 0xa4,
	0x38, 0x08, 0x00, 0xa5, 0xb1, 0xeb, 0x4f, 0xa5,
	0xe8, 0xd5, 0x8f, 0xa5, 0x2c, 0xcb, 0xcf, 0xa5,
	0x09, 0xcd, 0x0f, 0xa6, 0x21, 0xda, 0x4f, 0xa6,
	0xb6, 0xee, 0x8f, 0xa6, 0xa6, 0x05, 0xc0, 0xa6,
	0xaa, 0x19, 0x00, 0xa7, 0x84, 0x26, 0x40, 0xa7,
	0xd9, 0x29, 0x80, 0xa7, 0x99, 0x23, 0xc0, 0xa7,
	0xd6, 0x15, 0x00, 0xa8, 0x27, 0x04, 0x40, 0xa8,
	0xc3, 0xf2, 0x8f, 0xa8, 0x83, 0xe5, 0xcf, 0xa8,
	0x12, 0xdf, 0x0f, 0xa9, 0x66, 0xe0, 0x4f, 0xa9,
	0xab, 0xe8, 0x8f, 0xa9, 0x8f, 0xf5, 0xcf, 0xa9,
	0xe4, 0x03, 0x00, 0xaa, 0x61, 0x10, 0x40, 0xaa,
	0x5f, 0x18, 0x80, 0xaa, 0x67, 0x1a, 0xc0, 0xaa,
	0x6d, 0x16, 0x00, 0xab, 0xbd, 0x0d, 0x40, 0xab,
	0x96, 0x02, 0x80, 0xab, 0x9d, 0xf7, 0xcf, 0xab,
	0x3d, 0xef, 0x0f, 0xac, 0x25, 0xeb, 0x4f, 0xac,
	0xf1, 0xeb, 0x8f, 0xac, 0x20, 0xf1, 0xcf, 0xac,
	0x3e, 0xf9, 0x0f, 0xad, 0x4f, 0x02, 0x40, 0xad,
	0x42, 0x0a, 0x80, 0xad, 0x69, 0x0f, 0xc0, 0xad,
	0xd3, 0x10, 0x00, 0xae, 0x72, 0x0e, 0x40, 0xae,
	0x0e, 0x09, 0x80, 0xae, 0x0c, 0x02, 0xc0, 0xae,
	0x11, 0xfb, 0x0f, 0xaf, 0xa5, 0xf5, 0x4f, 0xaf,
	0xdd, 0xf2, 0x8f, 0xaf, 0x26, 0xf3, 0xcf, 0xaf,
	0x3c, 0xf6, 0x0f, 0xb0, 0x43, 0xfb, 0x4f, 0xb0,
	0xff, 0x00, 0x80, 0xb0, 0x27, 0x06, 0xc0, 0xb0,
	0xa4, 0x09, 0x00, 0xb1, 0xd0, 0x0a, 0x40, 0xb1,
	0x8f, 0x09, 0x80, 0xb1, 0x4c, 0x06, 0xc0, 0xb1,
	0xda, 0x01, 0x00, 0xb2, 0x3d, 0xfd, 0x4f, 0xb2,
	0x75, 0xf9, 0x8f, 0xb2, 0x45, 0xf7, 0xcf, 0xb2,
	0x0f, 0xf7, 0x0f, 0xb3, 0xc8, 0xf8, 0x4f, 0xb3,
	0xff, 0xfb, 0x8f, 0xb3, 0xfc, 0xff, 0xcf, 0xb3,
	0xe9, 0x03, 0x00, 0xb4, 0xfd, 0x06, 0x40, 0xb4,
	0xa2, 0x08, 0x80, 0xb4, 0x8b, 0x08, 0xc0, 0xb4,
	0xc0, 0x06, 0x00, 0xb5, 0x92, 0x03, 0x40, 0xb5,
	0x88, 0xff, 0x8f, 0xb5, 0x3f, 0xfb, 0xcf, 0xb5,
	0x51, 0xf7, 0x0f, 0xb6, 0x3b, 0xf4, 0x4f, 0xb6,
	0x4a, 0xf2, 0x8f, 0xb6, 0x97, 0xf1, 0xcf, 0xb6,
	0x0b, 0xf2, 0x0f, 0xb7, 0x6c, 0xf3, 0x4f, 0xb7,
	0x67, 0xf5, 0x8f, 0xb7, 0xa8, 0xf7, 0xcf, 0xb7,
	0xe2, 0xf9, 0x0f, 0xb8, 0xdd, 0xfb, 0x4f, 0xb8,
	0x76, 0xfd, 0x8f, 0xb8, 0xa2, 0xfe, 0xcf, 0xb8,
	0x67, 0xff, 0x0f, 0xb9, 0xd7, 0xff, 0x4f, 0xb9,
	0x0a, 0x00, 0x80, 0xb9, 0x18, 0x00, 0xc0, 0xb9,
	0x1b, 0x00, 0x00, 0xba, 0x00, 0x04, 0x00, 0x00,
	0x00
};
#endif

#if 0
/* X1 4ch 32 bit 24 MHz system */
const uint8_t nhlt_dmic_cfg[2985] = {
	0x10, 0x32, 0xff, 0xff, 0x10, 0x32, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
	0x03, 0x00, 0x3a, 0x00, 0x03, 0x00, 0x3a, 0x00,
	0x03, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00,
	0x03, 0x09, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0xa0, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
	0xb6, 0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
	0xae, 0xff, 0x0f, 0x00, 0x12, 0xff, 0x0f, 0x00,
	0xfb, 0xfd, 0x0f, 0x00, 0x61, 0xfc, 0x0f, 0x00,
	0x5b, 0xfa, 0x0f, 0x00, 0x2c, 0xf8, 0x0f, 0x00,
	0x43, 0xf6, 0x0f, 0x00, 0x23, 0xf5, 0x0f, 0x00,
	0x47, 0xf5, 0x0f, 0x00, 0xf8, 0xf6, 0x0f, 0x00,
	0x29, 0xfa, 0x0f, 0x00, 0x68, 0xfe, 0x0f, 0x00,
	0xe2, 0x02, 0x00, 0x00, 0x8f, 0x06, 0x00, 0x00,
	0x75, 0x08, 0x00, 0x00, 0xef, 0x07, 0x00, 0x00,
	0xf3, 0x04, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
	0xd3, 0xfa, 0x0f, 0x00, 0x8a, 0xf6, 0x0f, 0x00,
	0xc1, 0xf4, 0x0f, 0x00, 0x51, 0xf6, 0x0f, 0x00,
	0x22, 0xfb, 0x0f, 0x00, 0x11, 0x02, 0x00, 0x00,
	0x29, 0x09, 0x00, 0x00, 0x2c, 0x0e, 0x00, 0x00,
	0x3e, 0x0f, 0x00, 0x00, 0x8e, 0x0b, 0x00, 0x00,
	0xbb, 0x03, 0x00, 0x00, 0xcb, 0xf9, 0x0f, 0x00,
	0xb0, 0xf0, 0x0f, 0x00, 0x71, 0xeb, 0x0f, 0x00,
	0x2e, 0xec, 0x0f, 0x00, 0x56, 0xf3, 0x0f, 0x00,
	0x53, 0xff, 0x0f, 0x00, 0xce, 0x0c, 0x00, 0x00,
	0x9c, 0x17, 0x00, 0x00, 0xf8, 0x1b, 0x00, 0x00,
	0xd1, 0x17, 0x00, 0x00, 0x9d, 0x0b, 0x00, 0x00,
	0x79, 0xfa, 0x0f, 0x00, 0x6d, 0xe9, 0x0f, 0x00,
	0xf8, 0xdd, 0x0f, 0x00, 0x53, 0xdc, 0x0f, 0x00,
	0xf6, 0xe5, 0x0f, 0x00, 0xd5, 0xf8, 0x0f, 0x00,
	0xbb, 0x0f, 0x00, 0x00, 0xa7, 0x23, 0x00, 0x00,
	0xef, 0x2d, 0x00, 0x00, 0x6a, 0x2a, 0x00, 0x00,
	0x05, 0x19, 0x00, 0x00, 0x24, 0xfe, 0x0f, 0x00,
	0x99, 0xe1, 0x0f, 0x00, 0x68, 0xcc, 0x0f, 0x00,
	0xf7, 0xc5, 0x0f, 0x00, 0x8a, 0xd1, 0x0f, 0x00,
	0xe1, 0xec, 0x0f, 0x00, 0x79, 0x10, 0x00, 0x00,
	0x99, 0x31, 0x00, 0x00, 0x78, 0x45, 0x00, 0x00,
	0xbc, 0x44, 0x00, 0x00, 0x15, 0x2e, 0x00, 0x00,
	0x1b, 0x07, 0x00, 0x00, 0x08, 0xdb, 0x0f, 0x00,
	0x84, 0xb7, 0x0f, 0x00, 0x77, 0xa8, 0x0f, 0x00,
	0x1a, 0xb4, 0x0f, 0x00, 0x97, 0xd8, 0x0f, 0x00,
	0x10, 0x0c, 0x00, 0x00, 0x3b, 0x3f, 0x00, 0x00,
	0xe1, 0x61, 0x00, 0x00, 0xf6, 0x67, 0x00, 0x00,
	0xb0, 0x4d, 0x00, 0x00, 0x40, 0x19, 0x00, 0x00,
	0x81, 0xd9, 0x0f, 0x00, 0xca, 0xa1, 0x0f, 0x00,
	0x1f, 0x84, 0x0f, 0x00, 0x6b, 0x8b, 0x0f, 0x00,
	0xa8, 0xb7, 0x0f, 0x00, 0x3a, 0xfd, 0x0f, 0x00,
	0xe6, 0x47, 0x00, 0x00, 0xac, 0x80, 0x00, 0x00,
	0xcf, 0x94, 0x00, 0x00, 0xeb, 0x7b, 0x00, 0x00,
	0x25, 0x3b, 0x00, 0x00, 0x4a, 0xe4, 0x0f, 0x00,
	0xfe, 0x90, 0x0f, 0x00, 0x2e, 0x5b, 0x0f, 0x00,
	0x12, 0x55, 0x0f, 0x00, 0x2c, 0x83, 0x0f, 0x00,
	0x2d, 0xda, 0x0f, 0x00, 0xa3, 0x41, 0x00, 0x00,
	0xd1, 0x9a, 0x00, 0x00, 0xc2, 0xc9, 0x00, 0x00,
	0xf2, 0xbd, 0x00, 0x00, 0xe2, 0x77, 0x00, 0x00,
	0xbc, 0x09, 0x00, 0x00, 0xab, 0x92, 0x0f, 0x00,
	0x0f, 0x36, 0x0f, 0x00, 0x0c, 0x11, 0x0f, 0x00,
	0x8c, 0x31, 0x0f, 0x00, 0x65, 0x91, 0x0f, 0x00,
	0x50, 0x17, 0x00, 0x00, 0x91, 0x9d, 0x00, 0x00,
	0x90, 0xfc, 0x00, 0x00, 0x6e, 0x16, 0x01, 0x00,
	0x25, 0xe0, 0x00, 0x00, 0x89, 0x65, 0x00, 0x00,
	0xc7, 0xc6, 0x0f, 0x00, 0xea, 0x2f, 0x0f, 0x00,
	0xac, 0xcc, 0x0e, 0x00, 0xfa, 0xbb, 0x0e, 0x00,
	0xa9, 0x06, 0x0f, 0x00, 0x25, 0x9c, 0x0f, 0x00,
	0x2c, 0x56, 0x00, 0x00, 0xa9, 0x02, 0x01, 0x00,
	0x27, 0x71, 0x01, 0x00, 0x2c, 0x80, 0x01, 0x00,
	0xdd, 0x26, 0x01, 0x00, 0x2b, 0x78, 0x00, 0x00,
	0xa6, 0x9e, 0x0f, 0x00, 0xf0, 0xd1, 0x0e, 0x00,
	0x85, 0x48, 0x0e, 0x00, 0x8b, 0x29, 0x0e, 0x00,
	0x65, 0x82, 0x0e, 0x00, 0xa4, 0x42, 0x0f, 0x00,
	0x71, 0x3f, 0x00, 0x00, 0x8c, 0x3d, 0x01, 0x00,
	0x57, 0xff, 0x01, 0x00, 0x7a, 0x53, 0x02, 0x00,
	0x9e, 0x20, 0x02, 0x00, 0x73, 0x6b, 0x01, 0x00,
	0xce, 0x55, 0x00, 0x00, 0x49, 0x17, 0x0f, 0x00,
	0x42, 0xf1, 0x0d, 0x00, 0x2b, 0x21, 0x0d, 0x00,
	0x3e, 0xd4, 0x0c, 0x00, 0x22, 0x1f, 0x0d, 0x00,
	0x0f, 0xfb, 0x0d, 0x00, 0x8e, 0x48, 0x0f, 0x00,
	0xd5, 0xd6, 0x00, 0x00, 0xc5, 0x6d, 0x02, 0x00,
	0x44, 0xd8, 0x03, 0x00, 0xd5, 0xec, 0x04, 0x00,
	0x01, 0x93, 0x05, 0x00, 0xed, 0xc4, 0x05, 0x00,
	0x6f, 0x8d, 0x05, 0x00, 0x85, 0x03, 0x05, 0x00,
	0x8d, 0x44, 0x04, 0x00, 0x82, 0x6e, 0x03, 0x00,
	0x5d, 0x9b, 0x02, 0x00, 0x2d, 0xde, 0x01, 0x00,
	0x11, 0x42, 0x01, 0x00, 0xc9, 0xca, 0x00, 0x00,
	0x5b, 0x76, 0x00, 0x00, 0x38, 0x3f, 0x00, 0x00,
	0x4a, 0x1e, 0x00, 0x00, 0x93, 0x0c, 0x00, 0x00,
	0x3b, 0x04, 0x00, 0x00, 0xf9, 0x00, 0x00, 0x00,
	0xd6, 0xff, 0x0f, 0x00, 0x17, 0x02, 0x00, 0x00,
	0x5b, 0x02, 0x00, 0x00, 0x83, 0x03, 0x00, 0x00,
	0x07, 0x05, 0x00, 0x00, 0xe2, 0x06, 0x00, 0x00,
	0x16, 0x09, 0x00, 0x00, 0xa1, 0x0b, 0x00, 0x00,
	0x7b, 0x0e, 0x00, 0x00, 0x9a, 0x11, 0x00, 0x00,
	0xec, 0x14, 0x00, 0x00, 0x59, 0x18, 0x00, 0x00,
	0xc7, 0x1b, 0x00, 0x00, 0x15, 0x1f, 0x00, 0x00,
	0x1d, 0x22, 0x00, 0x00, 0xba, 0x24, 0x00, 0x00,
	0xc3, 0x26, 0x00, 0x00, 0x10, 0x28, 0x00, 0x00,
	0x7e, 0x28, 0x00, 0x00, 0xec, 0x27, 0x00, 0x00,
	0x40, 0x26, 0x00, 0x00, 0x6c, 0x23, 0x00, 0x00,
	0x6a, 0x1f, 0x00, 0x00, 0x40, 0x1a, 0x00, 0x00,
	0x02, 0x14, 0x00, 0x00, 0xd3, 0x0c, 0x00, 0x00,
	0xe2, 0x04, 0x00, 0x00, 0x6b, 0xfc, 0x0f, 0x00,
	0xb7, 0xf3, 0x0f, 0x00, 0x17, 0xeb, 0x0f, 0x00,
	0xe2, 0xe2, 0x0f, 0x00, 0x73, 0xdb, 0x0f, 0x00,
	0x26, 0xd5, 0x0f, 0x00, 0x4f, 0xd0, 0x0f, 0x00,
	0x3a, 0xcd, 0x0f, 0x00, 0x27, 0xcc, 0x0f, 0x00,
	0x42, 0xcd, 0x0f, 0x00, 0xa5, 0xd0, 0x0f, 0x00,
	0x4f, 0xd6, 0x0f, 0x00, 0x28, 0xde, 0x0f, 0x00,
	0xfd, 0xe7, 0x0f, 0x00, 0x82, 0xf3, 0x0f, 0x00,
	0x4f, 0x00, 0x00, 0x00, 0xeb, 0x0d, 0x00, 0x00,
	0xc8, 0x1b, 0x00, 0x00, 0x4e, 0x29, 0x00, 0x00,
	0xdd, 0x35, 0x00, 0x00, 0xd8, 0x40, 0x00, 0x00,
	0xa7, 0x49, 0x00, 0x00, 0xc4, 0x4f, 0x00, 0x00,
	0xbe, 0x52, 0x00, 0x00, 0x42, 0x52, 0x00, 0x00,
	0x1e, 0x4e, 0x00, 0x00, 0x4a, 0x46, 0x00, 0x00,
	0xe5, 0x3a, 0x00, 0x00, 0x3b, 0x2c, 0x00, 0x00,
	0xc1, 0x1a, 0x00, 0x00, 0x14, 0x07, 0x00, 0x00,
	0xf4, 0xf1, 0x0f, 0x00, 0x3b, 0xdc, 0x0f, 0x00,
	0xd6, 0xc6, 0x0f, 0x00, 0xc0, 0xb2, 0x0f, 0x00,
	0xec, 0xa0, 0x0f, 0x00, 0x47, 0x92, 0x0f, 0x00,
	0xa1, 0x87, 0x0f, 0x00, 0xad, 0x81, 0x0f, 0x00,
	0xec, 0x80, 0x0f, 0x00, 0xb1, 0x85, 0x0f, 0x00,
	0x0d, 0x90, 0x0f, 0x00, 0xda, 0x9f, 0x0f, 0x00,
	0xaa, 0xb4, 0x0f, 0x00, 0xda, 0xcd, 0x0f, 0x00,
	0x84, 0xea, 0x0f, 0x00, 0x96, 0x09, 0x00, 0x00,
	0xd1, 0x29, 0x00, 0x00, 0xe0, 0x49, 0x00, 0x00,
	0x55, 0x68, 0x00, 0x00, 0xcf, 0x83, 0x00, 0x00,
	0xf4, 0x9a, 0x00, 0x00, 0x91, 0xac, 0x00, 0x00,
	0x9e, 0xb7, 0x00, 0x00, 0x55, 0xbb, 0x00, 0x00,
	0x32, 0xb7, 0x00, 0x00, 0x0b, 0xab, 0x00, 0x00,
	0x03, 0x97, 0x00, 0x00, 0x9f, 0x7b, 0x00, 0x00,
	0xb2, 0x59, 0x00, 0x00, 0x67, 0x32, 0x00, 0x00,
	0x29, 0x07, 0x00, 0x00, 0xa4, 0xd9, 0x0f, 0x00,
	0xa8, 0xab, 0x0f, 0x00, 0x24, 0x7f, 0x0f, 0x00,
	0x02, 0x56, 0x0f, 0x00, 0x23, 0x32, 0x0f, 0x00,
	0x3c, 0x15, 0x0f, 0x00, 0xcf, 0x00, 0x0f, 0x00,
	0x0a, 0xf6, 0x0e, 0x00, 0xc9, 0xf5, 0x0e, 0x00,
	0x79, 0x00, 0x0f, 0x00, 0x1e, 0x16, 0x0f, 0x00,
	0x45, 0x36, 0x0f, 0x00, 0x0d, 0x60, 0x0f, 0x00,
	0x25, 0x92, 0x0f, 0x00, 0xde, 0xca, 0x0f, 0x00,
	0x33, 0x08, 0x00, 0x00, 0xe1, 0x47, 0x00, 0x00,
	0x77, 0x87, 0x00, 0x00, 0x73, 0xc4, 0x00, 0x00,
	0x56, 0xfc, 0x00, 0x00, 0xc0, 0x2c, 0x01, 0x00,
	0x88, 0x53, 0x01, 0x00, 0xd4, 0x6e, 0x01, 0x00,
	0x2b, 0x7d, 0x01, 0x00, 0x87, 0x7d, 0x01, 0x00,
	0x60, 0x6f, 0x01, 0x00, 0xb9, 0x52, 0x01, 0x00,
	0x1a, 0x28, 0x01, 0x00, 0x95, 0xf0, 0x00, 0x00,
	0xbd, 0xad, 0x00, 0x00, 0x96, 0x61, 0x00, 0x00,
	0x87, 0x0e, 0x00, 0x00, 0x47, 0xb7, 0x0f, 0x00,
	0xc0, 0x5e, 0x0f, 0x00, 0xfc, 0x07, 0x0f, 0x00,
	0x05, 0xb6, 0x0e, 0x00, 0xcb, 0x6b, 0x0e, 0x00,
	0x0f, 0x2c, 0x0e, 0x00, 0x44, 0xf9, 0x0d, 0x00,
	0x7e, 0xd5, 0x0d, 0x00, 0x5f, 0xc2, 0x0d, 0x00,
	0x0a, 0xc1, 0x0d, 0x00, 0x1a, 0xd2, 0x0d, 0x00,
	0x9c, 0xf5, 0x0d, 0x00, 0x14, 0x2b, 0x0e, 0x00,
	0x7c, 0x71, 0x0e, 0x00, 0x55, 0xc7, 0x0e, 0x00,
	0xad, 0x2a, 0x0f, 0x00, 0x3a, 0x99, 0x0f, 0x00,
	0x64, 0x10, 0x00, 0x00, 0x63, 0x8d, 0x00, 0x00,
	0x4f, 0x0d, 0x01, 0x00, 0x3f, 0x8d, 0x01, 0x00,
	0x57, 0x0a, 0x02, 0x00, 0xe5, 0x81, 0x02, 0x00,
	0x6e, 0xf1, 0x02, 0x00, 0xc1, 0x56, 0x03, 0x00,
	0x05, 0xb0, 0x03, 0x00, 0xc3, 0xfb, 0x03, 0x00,
	0xea, 0x38, 0x04, 0x00, 0xd2, 0x66, 0x04, 0x00,
	0x3f, 0x85, 0x04, 0x00, 0x57, 0x94, 0x04, 0x00,
	0xa1, 0x94, 0x04, 0x00, 0xf4, 0x86, 0x04, 0x00,
	0x73, 0x6c, 0x04, 0x00, 0x7a, 0x46, 0x04, 0x00,
	0x91, 0x16, 0x04, 0x00, 0x61, 0xde, 0x03, 0x00,
	0xa1, 0x9f, 0x03, 0x00, 0x0b, 0x5c, 0x03, 0x00,
	0x4e, 0x15, 0x03, 0x00, 0x02, 0xcd, 0x02, 0x00,
	0xa2, 0x84, 0x02, 0x00, 0x80, 0x3d, 0x02, 0x00,
	0xc4, 0xf8, 0x01, 0x00, 0x63, 0xb7, 0x01, 0x00,
	0x21, 0x7a, 0x01, 0x00, 0x92, 0x41, 0x01, 0x00,
	0x16, 0x0e, 0x01, 0x00, 0xe3, 0xdf, 0x00, 0x00,
	0x06, 0xb7, 0x00, 0x00, 0x68, 0x93, 0x00, 0x00,
	0xd3, 0x74, 0x00, 0x00, 0xf9, 0x5a, 0x00, 0x00,
	0x7c, 0x45, 0x00, 0x00, 0xef, 0x33, 0x00, 0x00,
	0xdf, 0x25, 0x00, 0x00, 0xd6, 0x1a, 0x00, 0x00,
	0x62, 0x12, 0x00, 0x00, 0x13, 0x0c, 0x00, 0x00,
	0x83, 0x07, 0x00, 0x00, 0x57, 0x04, 0x00, 0x00,
	0xd8, 0x02, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00,
	0x03, 0x09, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00,
	0xa0, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
	0xb6, 0x03, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
	0xae, 0xff, 0x0f, 0x00, 0x12, 0xff, 0x0f, 0x00,
	0xfb, 0xfd, 0x0f, 0x00, 0x61, 0xfc, 0x0f, 0x00,
	0x5b, 0xfa, 0x0f, 0x00, 0x2c, 0xf8, 0x0f, 0x00,
	0x43, 0xf6, 0x0f, 0x00, 0x23, 0xf5, 0x0f, 0x00,
	0x47, 0xf5, 0x0f, 0x00, 0xf8, 0xf6, 0x0f, 0x00,
	0x29, 0xfa, 0x0f, 0x00, 0x68, 0xfe, 0x0f, 0x00,
	0xe2, 0x02, 0x00, 0x00, 0x8f, 0x06, 0x00, 0x00,
	0x75, 0x08, 0x00, 0x00, 0xef, 0x07, 0x00, 0x00,
	0xf3, 0x04, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
	0xd3, 0xfa, 0x0f, 0x00, 0x8a, 0xf6, 0x0f, 0x00,
	0xc1, 0xf4, 0x0f, 0x00, 0x51, 0xf6, 0x0f, 0x00,
	0x22, 0xfb, 0x0f, 0x00, 0x11, 0x02, 0x00, 0x00,
	0x29, 0x09, 0x00, 0x00, 0x2c, 0x0e, 0x00, 0x00,
	0x3e, 0x0f, 0x00, 0x00, 0x8e, 0x0b, 0x00, 0x00,
	0xbb, 0x03, 0x00, 0x00, 0xcb, 0xf9, 0x0f, 0x00,
	0xb0, 0xf0, 0x0f, 0x00, 0x71, 0xeb, 0x0f, 0x00,
	0x2e, 0xec, 0x0f, 0x00, 0x56, 0xf3, 0x0f, 0x00,
	0x53, 0xff, 0x0f, 0x00, 0xce, 0x0c, 0x00, 0x00,
	0x9c, 0x17, 0x00, 0x00, 0xf8, 0x1b, 0x00, 0x00,
	0xd1, 0x17, 0x00, 0x00, 0x9d, 0x0b, 0x00, 0x00,
	0x79, 0xfa, 0x0f, 0x00, 0x6d, 0xe9, 0x0f, 0x00,
	0xf8, 0xdd, 0x0f, 0x00, 0x53, 0xdc, 0x0f, 0x00,
	0xf6, 0xe5, 0x0f, 0x00, 0xd5, 0xf8, 0x0f, 0x00,
	0xbb, 0x0f, 0x00, 0x00, 0xa7, 0x23, 0x00, 0x00,
	0xef, 0x2d, 0x00, 0x00, 0x6a, 0x2a, 0x00, 0x00,
	0x05, 0x19, 0x00, 0x00, 0x24, 0xfe, 0x0f, 0x00,
	0x99, 0xe1, 0x0f, 0x00, 0x68, 0xcc, 0x0f, 0x00,
	0xf7, 0xc5, 0x0f, 0x00, 0x8a, 0xd1, 0x0f, 0x00,
	0xe1, 0xec, 0x0f, 0x00, 0x79, 0x10, 0x00, 0x00,
	0x99, 0x31, 0x00, 0x00, 0x78, 0x45, 0x00, 0x00,
	0xbc, 0x44, 0x00, 0x00, 0x15, 0x2e, 0x00, 0x00,
	0x1b, 0x07, 0x00, 0x00, 0x08, 0xdb, 0x0f, 0x00,
	0x84, 0xb7, 0x0f, 0x00, 0x77, 0xa8, 0x0f, 0x00,
	0x1a, 0xb4, 0x0f, 0x00, 0x97, 0xd8, 0x0f, 0x00,
	0x10, 0x0c, 0x00, 0x00, 0x3b, 0x3f, 0x00, 0x00,
	0xe1, 0x61, 0x00, 0x00, 0xf6, 0x67, 0x00, 0x00,
	0xb0, 0x4d, 0x00, 0x00, 0x40, 0x19, 0x00, 0x00,
	0x81, 0xd9, 0x0f, 0x00, 0xca, 0xa1, 0x0f, 0x00,
	0x1f, 0x84, 0x0f, 0x00, 0x6b, 0x8b, 0x0f, 0x00,
	0xa8, 0xb7, 0x0f, 0x00, 0x3a, 0xfd, 0x0f, 0x00,
	0xe6, 0x47, 0x00, 0x00, 0xac, 0x80, 0x00, 0x00,
	0xcf, 0x94, 0x00, 0x00, 0xeb, 0x7b, 0x00, 0x00,
	0x25, 0x3b, 0x00, 0x00, 0x4a, 0xe4, 0x0f, 0x00,
	0xfe, 0x90, 0x0f, 0x00, 0x2e, 0x5b, 0x0f, 0x00,
	0x12, 0x55, 0x0f, 0x00, 0x2c, 0x83, 0x0f, 0x00,
	0x2d, 0xda, 0x0f, 0x00, 0xa3, 0x41, 0x00, 0x00,
	0xd1, 0x9a, 0x00, 0x00, 0xc2, 0xc9, 0x00, 0x00,
	0xf2, 0xbd, 0x00, 0x00, 0xe2, 0x77, 0x00, 0x00,
	0xbc, 0x09, 0x00, 0x00, 0xab, 0x92, 0x0f, 0x00,
	0x0f, 0x36, 0x0f, 0x00, 0x0c, 0x11, 0x0f, 0x00,
	0x8c, 0x31, 0x0f, 0x00, 0x65, 0x91, 0x0f, 0x00,
	0x50, 0x17, 0x00, 0x00, 0x91, 0x9d, 0x00, 0x00,
	0x90, 0xfc, 0x00, 0x00, 0x6e, 0x16, 0x01, 0x00,
	0x25, 0xe0, 0x00, 0x00, 0x89, 0x65, 0x00, 0x00,
	0xc7, 0xc6, 0x0f, 0x00, 0xea, 0x2f, 0x0f, 0x00,
	0xac, 0xcc, 0x0e, 0x00, 0xfa, 0xbb, 0x0e, 0x00,
	0xa9, 0x06, 0x0f, 0x00, 0x25, 0x9c, 0x0f, 0x00,
	0x2c, 0x56, 0x00, 0x00, 0xa9, 0x02, 0x01, 0x00,
	0x27, 0x71, 0x01, 0x00, 0x2c, 0x80, 0x01, 0x00,
	0xdd, 0x26, 0x01, 0x00, 0x2b, 0x78, 0x00, 0x00,
	0xa6, 0x9e, 0x0f, 0x00, 0xf0, 0xd1, 0x0e, 0x00,
	0x85, 0x48, 0x0e, 0x00, 0x8b, 0x29, 0x0e, 0x00,
	0x65, 0x82, 0x0e, 0x00, 0xa4, 0x42, 0x0f, 0x00,
	0x71, 0x3f, 0x00, 0x00, 0x8c, 0x3d, 0x01, 0x00,
	0x57, 0xff, 0x01, 0x00, 0x7a, 0x53, 0x02, 0x00,
	0x9e, 0x20, 0x02, 0x00, 0x73, 0x6b, 0x01, 0x00,
	0xce, 0x55, 0x00, 0x00, 0x49, 0x17, 0x0f, 0x00,
	0x42, 0xf1, 0x0d, 0x00, 0x2b, 0x21, 0x0d, 0x00,
	0x3e, 0xd4, 0x0c, 0x00, 0x22, 0x1f, 0x0d, 0x00,
	0x0f, 0xfb, 0x0d, 0x00, 0x8e, 0x48, 0x0f, 0x00,
	0xd5, 0xd6, 0x00, 0x00, 0xc5, 0x6d, 0x02, 0x00,
	0x44, 0xd8, 0x03, 0x00, 0xd5, 0xec, 0x04, 0x00,
	0x01, 0x93, 0x05, 0x00, 0xed, 0xc4, 0x05, 0x00,
	0x6f, 0x8d, 0x05, 0x00, 0x85, 0x03, 0x05, 0x00,
	0x8d, 0x44, 0x04, 0x00, 0x82, 0x6e, 0x03, 0x00,
	0x5d, 0x9b, 0x02, 0x00, 0x2d, 0xde, 0x01, 0x00,
	0x11, 0x42, 0x01, 0x00, 0xc9, 0xca, 0x00, 0x00,
	0x5b, 0x76, 0x00, 0x00, 0x38, 0x3f, 0x00, 0x00,
	0x4a, 0x1e, 0x00, 0x00, 0x93, 0x0c, 0x00, 0x00,
	0x3b, 0x04, 0x00, 0x00, 0xf9, 0x00, 0x00, 0x00,
	0xd6, 0xff, 0x0f, 0x00, 0x17, 0x02, 0x00, 0x00,
	0x5b, 0x02, 0x00, 0x00, 0x83, 0x03, 0x00, 0x00,
	0x07, 0x05, 0x00, 0x00, 0xe2, 0x06, 0x00, 0x00,
	0x16, 0x09, 0x00, 0x00, 0xa1, 0x0b, 0x00, 0x00,
	0x7b, 0x0e, 0x00, 0x00, 0x9a, 0x11, 0x00, 0x00,
	0xec, 0x14, 0x00, 0x00, 0x59, 0x18, 0x00, 0x00,
	0xc7, 0x1b, 0x00, 0x00, 0x15, 0x1f, 0x00, 0x00,
	0x1d, 0x22, 0x00, 0x00, 0xba, 0x24, 0x00, 0x00,
	0xc3, 0x26, 0x00, 0x00, 0x10, 0x28, 0x00, 0x00,
	0x7e, 0x28, 0x00, 0x00, 0xec, 0x27, 0x00, 0x00,
	0x40, 0x26, 0x00, 0x00, 0x6c, 0x23, 0x00, 0x00,
	0x6a, 0x1f, 0x00, 0x00, 0x40, 0x1a, 0x00, 0x00,
	0x02, 0x14, 0x00, 0x00, 0xd3, 0x0c, 0x00, 0x00,
	0xe2, 0x04, 0x00, 0x00, 0x6b, 0xfc, 0x0f, 0x00,
	0xb7, 0xf3, 0x0f, 0x00, 0x17, 0xeb, 0x0f, 0x00,
	0xe2, 0xe2, 0x0f, 0x00, 0x73, 0xdb, 0x0f, 0x00,
	0x26, 0xd5, 0x0f, 0x00, 0x4f, 0xd0, 0x0f, 0x00,
	0x3a, 0xcd, 0x0f, 0x00, 0x27, 0xcc, 0x0f, 0x00,
	0x42, 0xcd, 0x0f, 0x00, 0xa5, 0xd0, 0x0f, 0x00,
	0x4f, 0xd6, 0x0f, 0x00, 0x28, 0xde, 0x0f, 0x00,
	0xfd, 0xe7, 0x0f, 0x00, 0x82, 0xf3, 0x0f, 0x00,
	0x4f, 0x00, 0x00, 0x00, 0xeb, 0x0d, 0x00, 0x00,
	0xc8, 0x1b, 0x00, 0x00, 0x4e, 0x29, 0x00, 0x00,
	0xdd, 0x35, 0x00, 0x00, 0xd8, 0x40, 0x00, 0x00,
	0xa7, 0x49, 0x00, 0x00, 0xc4, 0x4f, 0x00, 0x00,
	0xbe, 0x52, 0x00, 0x00, 0x42, 0x52, 0x00, 0x00,
	0x1e, 0x4e, 0x00, 0x00, 0x4a, 0x46, 0x00, 0x00,
	0xe5, 0x3a, 0x00, 0x00, 0x3b, 0x2c, 0x00, 0x00,
	0xc1, 0x1a, 0x00, 0x00, 0x14, 0x07, 0x00, 0x00,
	0xf4, 0xf1, 0x0f, 0x00, 0x3b, 0xdc, 0x0f, 0x00,
	0xd6, 0xc6, 0x0f, 0x00, 0xc0, 0xb2, 0x0f, 0x00,
	0xec, 0xa0, 0x0f, 0x00, 0x47, 0x92, 0x0f, 0x00,
	0xa1, 0x87, 0x0f, 0x00, 0xad, 0x81, 0x0f, 0x00,
	0xec, 0x80, 0x0f, 0x00, 0xb1, 0x85, 0x0f, 0x00,
	0x0d, 0x90, 0x0f, 0x00, 0xda, 0x9f, 0x0f, 0x00,
	0xaa, 0xb4, 0x0f, 0x00, 0xda, 0xcd, 0x0f, 0x00,
	0x84, 0xea, 0x0f, 0x00, 0x96, 0x09, 0x00, 0x00,
	0xd1, 0x29, 0x00, 0x00, 0xe0, 0x49, 0x00, 0x00,
	0x55, 0x68, 0x00, 0x00, 0xcf, 0x83, 0x00, 0x00,
	0xf4, 0x9a, 0x00, 0x00, 0x91, 0xac, 0x00, 0x00,
	0x9e, 0xb7, 0x00, 0x00, 0x55, 0xbb, 0x00, 0x00,
	0x32, 0xb7, 0x00, 0x00, 0x0b, 0xab, 0x00, 0x00,
	0x03, 0x97, 0x00, 0x00, 0x9f, 0x7b, 0x00, 0x00,
	0xb2, 0x59, 0x00, 0x00, 0x67, 0x32, 0x00, 0x00,
	0x29, 0x07, 0x00, 0x00, 0xa4, 0xd9, 0x0f, 0x00,
	0xa8, 0xab, 0x0f, 0x00, 0x24, 0x7f, 0x0f, 0x00,
	0x02, 0x56, 0x0f, 0x00, 0x23, 0x32, 0x0f, 0x00,
	0x3c, 0x15, 0x0f, 0x00, 0xcf, 0x00, 0x0f, 0x00,
	0x0a, 0xf6, 0x0e, 0x00, 0xc9, 0xf5, 0x0e, 0x00,
	0x79, 0x00, 0x0f, 0x00, 0x1e, 0x16, 0x0f, 0x00,
	0x45, 0x36, 0x0f, 0x00, 0x0d, 0x60, 0x0f, 0x00,
	0x25, 0x92, 0x0f, 0x00, 0xde, 0xca, 0x0f, 0x00,
	0x33, 0x08, 0x00, 0x00, 0xe1, 0x47, 0x00, 0x00,
	0x77, 0x87, 0x00, 0x00, 0x73, 0xc4, 0x00, 0x00,
	0x56, 0xfc, 0x00, 0x00, 0xc0, 0x2c, 0x01, 0x00,
	0x88, 0x53, 0x01, 0x00, 0xd4, 0x6e, 0x01, 0x00,
	0x2b, 0x7d, 0x01, 0x00, 0x87, 0x7d, 0x01, 0x00,
	0x60, 0x6f, 0x01, 0x00, 0xb9, 0x52, 0x01, 0x00,
	0x1a, 0x28, 0x01, 0x00, 0x95, 0xf0, 0x00, 0x00,
	0xbd, 0xad, 0x00, 0x00, 0x96, 0x61, 0x00, 0x00,
	0x87, 0x0e, 0x00, 0x00, 0x47, 0xb7, 0x0f, 0x00,
	0xc0, 0x5e, 0x0f, 0x00, 0xfc, 0x07, 0x0f, 0x00,
	0x05, 0xb6, 0x0e, 0x00, 0xcb, 0x6b, 0x0e, 0x00,
	0x0f, 0x2c, 0x0e, 0x00, 0x44, 0xf9, 0x0d, 0x00,
	0x7e, 0xd5, 0x0d, 0x00, 0x5f, 0xc2, 0x0d, 0x00,
	0x0a, 0xc1, 0x0d, 0x00, 0x1a, 0xd2, 0x0d, 0x00,
	0x9c, 0xf5, 0x0d, 0x00, 0x14, 0x2b, 0x0e, 0x00,
	0x7c, 0x71, 0x0e, 0x00, 0x55, 0xc7, 0x0e, 0x00,
	0xad, 0x2a, 0x0f, 0x00, 0x3a, 0x99, 0x0f, 0x00,
	0x64, 0x10, 0x00, 0x00, 0x63, 0x8d, 0x00, 0x00,
	0x4f, 0x0d, 0x01, 0x00, 0x3f, 0x8d, 0x01, 0x00,
	0x57, 0x0a, 0x02, 0x00, 0xe5, 0x81, 0x02, 0x00,
	0x6e, 0xf1, 0x02, 0x00, 0xc1, 0x56, 0x03, 0x00,
	0x05, 0xb0, 0x03, 0x00, 0xc3, 0xfb, 0x03, 0x00,
	0xea, 0x38, 0x04, 0x00, 0xd2, 0x66, 0x04, 0x00,
	0x3f, 0x85, 0x04, 0x00, 0x57, 0x94, 0x04, 0x00,
	0xa1, 0x94, 0x04, 0x00, 0xf4, 0x86, 0x04, 0x00,
	0x73, 0x6c, 0x04, 0x00, 0x7a, 0x46, 0x04, 0x00,
	0x91, 0x16, 0x04, 0x00, 0x61, 0xde, 0x03, 0x00,
	0xa1, 0x9f, 0x03, 0x00, 0x0b, 0x5c, 0x03, 0x00,
	0x4e, 0x15, 0x03, 0x00, 0x02, 0xcd, 0x02, 0x00,
	0xa2, 0x84, 0x02, 0x00, 0x80, 0x3d, 0x02, 0x00,
	0xc4, 0xf8, 0x01, 0x00, 0x63, 0xb7, 0x01, 0x00,
	0x21, 0x7a, 0x01, 0x00, 0x92, 0x41, 0x01, 0x00,
	0x16, 0x0e, 0x01, 0x00, 0xe3, 0xdf, 0x00, 0x00,
	0x06, 0xb7, 0x00, 0x00, 0x68, 0x93, 0x00, 0x00,
	0xd3, 0x74, 0x00, 0x00, 0xf9, 0x5a, 0x00, 0x00,
	0x7c, 0x45, 0x00, 0x00, 0xef, 0x33, 0x00, 0x00,
	0xdf, 0x25, 0x00, 0x00, 0xd6, 0x1a, 0x00, 0x00,
	0x62, 0x12, 0x00, 0x00, 0x13, 0x0c, 0x00, 0x00,
	0x83, 0x07, 0x00, 0x00, 0x57, 0x04, 0x00, 0x00,
	0xd8, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x00
};

#endif

#if 0
/* Thinkbook 13S */
#endif
