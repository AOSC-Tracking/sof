#!/usr/bin/env python3
# SPDX-License-Identifier: BSD-3-Clause
#
# Copyright (c) 2019, Intel Corporation. All rights reserved.
#
# Author: Marcin Maka <marcin.maka@linux.intel.com>

""" Parses manifests included in sof binary and prints extracted metadata
    in readable form.
"""

# pylint: disable=too-few-public-methods
# pylint: disable=too-many-arguments
# pylint: disable=too-many-instance-attributes

import sys
import argparse
import struct

# Public keys signatures recognized by parse_css_manifest()
# - add a new one as array of bytes and append entry to KNOWN_KEYS below.

APL_INTEL_PROD_KEY = bytes([0x1f, 0xf4, 0x58, 0x74, 0x64, 0xd4, 0xae, 0x90,
                            0x03, 0xb6, 0x71, 0x0d, 0xb5, 0xaf, 0x6d, 0xd6,
                            0x96, 0xce, 0x28, 0x95, 0xd1, 0x5b, 0x40, 0x59,
                            0xcd, 0xdf, 0x0c, 0x55, 0xd2, 0xc1, 0xbd, 0x58,
                            0xc3, 0x0d, 0x83, 0xe2, 0xac, 0xfa, 0xe0, 0xcc,
                            0x54, 0xf6, 0x5f, 0x72, 0xc2, 0x11, 0x05, 0x93,
                            0x1d, 0xb7, 0xe4, 0x4f, 0xa4, 0x95, 0xf5, 0x84,
                            0x77, 0x07, 0x24, 0x6e, 0x72, 0xce, 0x57, 0x41,
                            0xf2, 0x0b, 0x49, 0x49, 0x0c, 0xe2, 0x76, 0xf8,
                            0x19, 0xc7, 0x9f, 0xe1, 0xca, 0x77, 0x20, 0x1b,
                            0x5d, 0x1d, 0xed, 0xee, 0x5c, 0x54, 0x1d, 0xf6,
                            0x76, 0x14, 0xce, 0x6a, 0x24, 0x80, 0xc9, 0xce,
                            0x2e, 0x92, 0xe9, 0x35, 0xc7, 0x1a, 0xe9, 0x97,
                            0x7f, 0x25, 0x2b, 0xa8, 0xf3, 0xc1, 0x4d, 0x6b,
                            0xae, 0xd9, 0xcd, 0x0c, 0xbb, 0x08, 0x6d, 0x2b,
                            0x01, 0x44, 0xe2, 0xb9, 0x44, 0x4e, 0x4d, 0x5c,
                            0xdf, 0x8a, 0x89, 0xa5, 0x3c, 0x27, 0xa0, 0x54,
                            0xde, 0xc5, 0x5b, 0xde, 0x58, 0x10, 0x8c, 0xaa,
                            0xc4, 0x37, 0x5b, 0x73, 0x58, 0xfb, 0xe3, 0xcf,
                            0x57, 0xf5, 0x65, 0xd3, 0x19, 0x06, 0xed, 0x36,
                            0x47, 0xb0, 0x91, 0x67, 0xec, 0xc1, 0xe1, 0x7b,
                            0x4f, 0x85, 0x66, 0x61, 0x31, 0x99, 0xfc, 0x98,
                            0x7a, 0x56, 0x70, 0x95, 0x85, 0x52, 0xa0, 0x30,
                            0x37, 0x92, 0x11, 0x9e, 0x7f, 0x33, 0x44, 0xd3,
                            0x81, 0xfd, 0x14, 0x74, 0x51, 0x1c, 0x01, 0x14,
                            0xc8, 0x4b, 0xf6, 0xd6, 0xeb, 0x67, 0xef, 0xfc,
                            0x0a, 0x5f, 0xcc, 0x31, 0x73, 0xf8, 0xa9, 0xe3,
                            0xcb, 0xb4, 0x8b, 0x91, 0xa1, 0xf0, 0xb9, 0x6e,
                            0x1f, 0xea, 0xd3, 0xa3, 0xe4, 0x0f, 0x96, 0x74,
                            0x3c, 0x17, 0x5b, 0x68, 0x7c, 0x87, 0xfc, 0x90,
                            0x10, 0x89, 0x23, 0xca, 0x5d, 0x17, 0x5b, 0xc1,
                            0xb5, 0xc2, 0x49, 0x4e, 0x2a, 0x5f, 0x47, 0xc2])

CNL_INTEL_PROD_KEY = bytes([0x41, 0xa0, 0x3e, 0x14, 0x1e, 0x7e, 0x29, 0x72,
                            0x89, 0x97, 0xc2, 0xa7, 0x7d, 0xbc, 0x1d, 0x25,
                            0xf4, 0x9a, 0xa8, 0xb7, 0x89, 0x10, 0x73, 0x31,
                            0x58, 0xbd, 0x46, 0x55, 0x78, 0xcf, 0xd9, 0xe1,
                            0x7d, 0xfa, 0x24, 0x23, 0xfa, 0x5c, 0x7c, 0xc9,
                            0x3d, 0xc8, 0xb5, 0x74, 0x87, 0xa, 0x8c, 0xe7,
                            0x33, 0xc2, 0x71, 0x26, 0xb1, 0x4d, 0x32, 0x45,
                            0x23, 0x17, 0xcb, 0xa6, 0xa2, 0xd0, 0xcc, 0x9e,
                            0x2b, 0xa6, 0x9, 0x42, 0x52, 0xf1, 0xe6, 0xbd,
                            0x73, 0x92, 0x2a, 0xfb, 0x7f, 0xc4, 0x8d, 0x5,
                            0xec, 0x69, 0x7f, 0xd4, 0xa2, 0x6c, 0x46, 0xd4,
                            0x5d, 0x92, 0x1d, 0x17, 0x75, 0x39, 0x16, 0x4c,
                            0x61, 0xa8, 0xda, 0x93, 0xd6, 0x26, 0x23, 0xa,
                            0xc8, 0x2d, 0xcc, 0x81, 0xf4, 0xcc, 0x85, 0x42,
                            0xaa, 0xa3, 0x15, 0x8, 0x62, 0x8f, 0x72, 0x9b,
                            0x5f, 0x90, 0x2f, 0xd5, 0x94, 0xdc, 0xad, 0xf,
                            0xa9, 0x8, 0x8c, 0x2e, 0x20, 0xf4, 0xdf, 0x12,
                            0xf, 0xe2, 0x1e, 0xeb, 0xfb, 0xf7, 0xe9, 0x22,
                            0xef, 0xa7, 0x12, 0x3d, 0x43, 0x3b, 0x62, 0x8e,
                            0x2e, 0xeb, 0x78, 0x8, 0x6e, 0xd0, 0xb0, 0xea,
                            0x37, 0x43, 0x16, 0xd8, 0x11, 0x5a, 0xb5, 0x5,
                            0x60, 0xf2, 0x91, 0xa7, 0xaa, 0x7d, 0x7, 0x17,
                            0xb7, 0x5b, 0xec, 0x45, 0xf4, 0x4a, 0xaf, 0x5c,
                            0xa3, 0x30, 0x62, 0x8e, 0x4d, 0x63, 0x2, 0x2,
                            0xed, 0x4b, 0x1f, 0x1b, 0x9a, 0x2, 0x29, 0x9,
                            0xc1, 0x7a, 0xc5, 0xeb, 0xc7, 0xdb, 0xa1, 0x6f,
                            0x61, 0x31, 0xfa, 0x7b, 0x3b, 0xe0, 0x6a, 0x1c,
                            0xee, 0x55, 0xed, 0xf0, 0xf9, 0x7a, 0xaf, 0xaa,
                            0xc7, 0x76, 0xf5, 0xfb, 0x6a, 0xbc, 0x65, 0xde,
                            0x42, 0x3e, 0x1c, 0xdf, 0xcc, 0x69, 0x75, 0x1,
                            0x38, 0x8, 0x66, 0x20, 0xea, 0x6, 0x91, 0xb8,
                            0xcd, 0x1d, 0xfa, 0xfd, 0xe8, 0xa0, 0xba, 0x91])

ICL_INTEL_PROD_KEY = bytes([0x63, 0xdf, 0x54, 0xe3, 0xc1, 0xe5, 0xd9, 0xd2,
                            0xb8, 0xb5, 0x13, 0xb3, 0xec, 0xc2, 0x64, 0xb5,
                            0x16, 0xb4, 0xfc, 0x56, 0x92, 0x67, 0x17, 0xc7,
                            0x91, 0x7b, 0x3d, 0xb0, 0x22, 0xbf, 0x7f, 0x92,
                            0x39, 0x35, 0xcc, 0x64, 0x1c, 0xad, 0x8, 0x75,
                            0xe7, 0x67, 0xb, 0x8, 0xf8, 0x57, 0xdb, 0x9c,
                            0xde, 0xab, 0xe, 0xbd, 0x27, 0x5f, 0x5, 0x51,
                            0xcf, 0x6e, 0x3e, 0xc9, 0xdd, 0xe6, 0x51, 0x14,
                            0x57, 0xe1, 0x8a, 0x23, 0xae, 0x7a, 0xa5, 0x5f,
                            0xdc, 0x16, 0x13, 0x1b, 0x28, 0x3b, 0xab, 0xf1,
                            0xc3, 0xb5, 0x73, 0xc0, 0x72, 0xd8, 0x86, 0x7a,
                            0x76, 0x3a, 0x2, 0xbe, 0x2f, 0x3e, 0xfe, 0x93,
                            0x83, 0xa1, 0xd, 0xa0, 0xfc, 0x26, 0x7f, 0x6b,
                            0x2e, 0x5a, 0xfd, 0xac, 0x6b, 0x53, 0xd3, 0xb8,
                            0xff, 0x5e, 0xc7, 0x5, 0x25, 0xff, 0xe7, 0x78,
                            0x9c, 0x45, 0xe4, 0x17, 0xbd, 0xf4, 0x52, 0x4e,
                            0x3c, 0xa2, 0xa, 0x4d, 0x54, 0xb5, 0x40, 0x30,
                            0xb3, 0x48, 0xba, 0x6c, 0xfa, 0x63, 0xc0, 0x65,
                            0x2e, 0xde, 0x9, 0x2e, 0xa1, 0x95, 0x85, 0xc0,
                            0x78, 0xd9, 0x98, 0x64, 0x3c, 0x29, 0x2e, 0x48,
                            0x66, 0x1e, 0xaf, 0x1d, 0xa0, 0x7c, 0x15, 0x3,
                            0x7f, 0x9e, 0x5f, 0x38, 0xf5, 0xc1, 0xe1, 0xe9,
                            0xbe, 0x77, 0xa2, 0x9c, 0x83, 0xf2, 0x25, 0x54,
                            0x22, 0xfe, 0x29, 0x66, 0x5, 0xc2, 0xc9, 0x6b,
                            0x8b, 0xa6, 0xa3, 0xf9, 0xb1, 0x6b, 0xaf, 0xe7,
                            0x14, 0x77, 0xff, 0x17, 0xc9, 0x7c, 0x7c, 0x4e,
                            0x83, 0x28, 0x2a, 0xe5, 0xc3, 0xcc, 0x6e, 0x25,
                            0xa, 0x62, 0xbb, 0x97, 0x44, 0x86, 0x7c, 0xa2,
                            0xd4, 0xf1, 0xd4, 0xf8, 0x8, 0x17, 0xf4, 0x6c,
                            0xcc, 0x95, 0x99, 0xd4, 0x86, 0x37, 0x4, 0x9f,
                            0x5, 0x76, 0x1b, 0x44, 0x55, 0x75, 0xd9, 0x32,
                            0x35, 0xf1, 0xec, 0x4d, 0x93, 0x73, 0xe6, 0xc4])

KNOWN_KEYS = {APL_INTEL_PROD_KEY : 'APL Intel prod key',
              CNL_INTEL_PROD_KEY : 'CNL Intel prod key',
              ICL_INTEL_PROD_KEY : 'ICL Intel prod key'}

def parse_params():
    """ Parses parameters
    """
    parser = argparse.ArgumentParser(description='SOF Binary Info Utility')
    parser.add_argument('-v', '--verbose', help='increase output verbosity',
                        action='store_true')
    parser.add_argument('--headers', help='display headers only',
                        action='store_true')
    parser.add_argument('--full_bytes', help='display full byte arrays',
                        action='store_true')
    parser.add_argument('--no_colors', help='disable colors in output',
                        action='store_true')
    parser.add_argument('sof_ri_path', help='path to fw binary file to parse')
    parsed_args = parser.parse_args()

    return parsed_args

# Helper Functions

def change_color(color):
    """ Prints escape code to change text color
    """
    color_code = {'red':91, 'green':92, 'yellow':93, 'blue':94,
                  'magenta':95, 'cyan':96, 'white':98, 'none':0}
    return '\033[{}m'.format(color_code[color])

def uint_to_string(uint, both=False):
    """ Prints uint in readable form
    """
    if both:
        return hex(uint) + ' (' + repr(uint) + ')'
    return hex(uint)

def date_to_string(date):
    """ Prints BCD date in readable form
    """
    return date[2:6]+'/'+date[6:8]+'/'+date[8:10]

def chararr_to_string(chararr, max_len):
    """ Prints array of characters (null terminated or till max_len)
        in readable form
    """
    out = ''
    for i in range(0, max_len):
        if chararr[i] == 0:
            return out
        out += '{:c}'.format(chararr[i])
    return out

def mod_type_to_string(mod_type):
    """ Prints module type in readable form
    """
    out = '('
    # type
    if (mod_type & 0xf) == 0:
        out += ' builtin'
    elif (mod_type & 0xf) == 1:
        out += ' loadable'
    # Module that may be instantiated by fw on startup
    if ((mod_type >> 4) & 0x1) == 1:
        out += ' auto_start'
    # Module designed to run with low latency scheduler
    if ((mod_type >> 5) & 0x1) == 1:
        out += ' LL'
    # Module designed to run with edf scheduler
    if ((mod_type >> 6) & 0x1) == 1:
        out += ' DP'
    out += ' )'
    return out

def seg_flags_to_string(flags):
    """ Prints module segment flags in readable form
    """
    out = '('
    if flags & 0x1 == 0x1:
        out = out + ' contents'
    if flags & 0x2 == 0x2:
        out = out + ' alloc'
    if flags & 0x4 == 0x4:
        out = out + ' load'
    if flags & 0x8 == 0x8:
        out = out + ' readonly'
    if flags & 0x10 == 0x10:
        out = out + ' code'
    if flags & 0x20 == 0x20:
        out = out + ' data'
    out = out + ' type=' + repr((flags>>8)&0xf)
    out = out + ' pages=' + repr((flags>>16)&0xffff)
    out = out + ' )'
    return out

# Parsers

def parse_extended_manifest(reader):
    """ Parses extended manifest from sof binary
    """
    ext_mft = ExtendedManifest()
    hdr = Component('ext_mft_hdr', 'Header', 0)
    ext_mft.add_comp(hdr)

    # Try to detect signature first
    sig = reader.read_bytes(4).decode()
    if sig != '$AE1':
        reader.set_offset(0)
        reader.info('info: Extended Manifest not found (sig = '+sig+')')
        reader.ext_mft_length = 0
        hdr.add_a(Auint('length', reader.ext_mft_length))
        return ext_mft

    reader.info('Extended Manifest (' + sig + ')', -4)
    hdr.add_a(Astring('sig', sig))

    # Next dword is the total length of the extended manifest
    # (need to use it for further parsing)
    reader.ext_mft_length = reader.read_dw()
    hdr.add_a(Auint('length', reader.ext_mft_length))
    hdr.add_a(Astring('ver', '{}.{}'.format(reader.read_w(), reader.read_w())))
    hdr.add_a(Auint('entries', reader.read_dw()))

    reader.ff_data(reader.ext_mft_length-16)
    return ext_mft

def parse_cse_manifest(reader, add_module_entries):
    """ Parses CSE manifest form sof binary
    """
    cse_mft = CseManifest(reader.get_offset())

    # Try to detect signature first
    sig = reader.read_bytes(4).decode()
    if sig != '$CPD':
        reader.error('CSE Manifest NOT found ' + sig + ')', -4)
        sys.exit(1)
    reader.info('CSE Manifest (' + sig + ')', -4)

    # Read the header
    hdr = Component('cse_mft_hdr', 'Header', reader.get_offset())
    cse_mft.add_comp(hdr)
    hdr.add_a(Astring('sig', sig))
    # read number of entries
    nb_entries = reader.read_dw()
    hdr.add_a(Adec('nb_entries', nb_entries))
    # read version (1byte for header ver and 1 byte for entry ver)
    ver = reader.read_w()
    hdr.add_a(Ahex('header_version', ver))
    header_length = reader.read_b()
    hdr.add_a(Ahex('header_length', header_length))
    hdr.add_a(Ahex('checksum', reader.read_b()))
    hdr.add_a(Astring('partition_name', reader.read_bytes(4).decode()))

    reader.set_offset(cse_mft.file_offset + header_length)
    # Read entries
    nb_index = 0
    while nb_index < nb_entries:
        entry_name = reader.read_bytes(12).decode()
        entry_offset = reader.read_dw()
        entry_length = reader.read_dw()
        # reserved field
        reader.read_dw()

        hdr_entry = Component('cse_hdr_entry', 'Entry', reader.get_offset())
        hdr_entry.add_a(Astring('entry_name', entry_name))
        hdr_entry.add_a(Ahex('entry_offset', entry_offset))
        hdr_entry.add_a(Ahex('entry_length', entry_length))
        hdr.add_comp(hdr_entry)

        if '.man' in entry_name:
            entry = CssManifest(entry_name, entry_offset)
            cur_off = reader.set_offset(reader.ext_mft_length + entry_offset)
            parse_css_manifest(entry, reader,
                               reader.ext_mft_length + entry_offset + entry_length)
            reader.set_offset(cur_off)
        elif '.met' in entry_name:
            cur_off = reader.set_offset(reader.ext_mft_length + entry_offset)
            entry = parse_mft_extension(reader, 0)
            entry.name = '{} ({})'.format(entry_name, entry.name)
            reader.set_offset(cur_off)
        else:
            # override offset with precise one
            cur_off = reader.set_offset(reader.ext_mft_length + 0x2000)
            entry = parse_adsp_manifest(reader, entry_name, add_module_entries)
            reader.set_offset(cur_off)
        cse_mft.add_comp(entry)

        nb_index += 1

    return cse_mft

def parse_css_manifest(css_mft, reader, limit):
    """ Parses CSS manifest from sof binary
    """
    ver, = struct.unpack('I', reader.get_data(0, 4))
    if ver == 4:
        reader.info('CSS Manifest type 4')
        return parse_css_manifest_4(css_mft, reader, limit)

    reader.error('CSS Manifest NOT found or NOT recognized!')
    sys.exit(1)

def parse_css_manifest_4(css_mft, reader, size_limit):
    """ Parses CSS manifest type 4 from sof binary
    """

    # CSS Header
    hdr = Component('css_mft_hdr', 'Header', reader.get_offset())
    css_mft.add_comp(hdr)

    hdr.add_a(Auint('type', reader.read_dw()))
    header_len_dw = reader.read_dw()
    hdr.add_a(Auint('header_len_dw', header_len_dw))
    hdr.add_a(Auint('header_version', reader.read_dw()))
    hdr.add_a(Auint('reserved0', reader.read_dw(), 'red'))
    hdr.add_a(Ahex('mod_vendor', reader.read_dw()))
    hdr.add_a(Adate('date', hex(reader.read_dw())))
    size = reader.read_dw()
    hdr.add_a(Auint('size', size))
    hdr.add_a(Astring('header_id', reader.read_bytes(4).decode()))
    hdr.add_a(Auint('padding', reader.read_dw()))
    hdr.add_a(Aversion('fw_version', reader.read_w(), reader.read_w(),
                       reader.read_w(), reader.read_w()))
    hdr.add_a(Auint('svn', reader.read_dw()))
    reader.read_bytes(18*4)
    modulus_size = reader.read_dw()
    hdr.add_a(Adec('modulus_size', modulus_size))
    exponent_size = reader.read_dw()
    hdr.add_a(Adec('exponent_size', exponent_size))
    modulus = reader.read_bytes(modulus_size * 4)
    hdr.add_a(Amodulus('modulus', modulus, KNOWN_KEYS.get(modulus, 'Other')))
    hdr.add_a(Abytes('exponent', reader.read_bytes(exponent_size * 4)))
    hdr.add_a(Abytes('signature', reader.read_bytes(modulus_size * 4)))

    # Move right after the header
    reader.set_offset(css_mft.file_offset + header_len_dw*4)

    # Anything packed here is
    #   either an 'Extension' beginning with
    #     dw0 - extension type
    #     dw1 - extension length (in bytes)
    #   that could be parsed if extension type is recognized
    #
    #   or series of 0xffffffff that should be skipped
    ext_idx = 0
    while reader.get_offset() < size_limit:
        ext_type = reader.read_dw()
        if ext_type == 0xffffffff:
            continue
        reader.set_offset(reader.get_offset() - 4)
        css_mft.add_comp(parse_mft_extension(reader, ext_idx))
        ext_idx += 1

    return css_mft

def parse_mft_extension(reader, ext_id):
    """ Parses mft extension from sof binary
    """
    ext_type = reader.read_dw()
    ext_len = reader.read_dw()
    if ext_type == 15:
        begin_off = reader.get_offset()
        ext = PlatFwAuthExtension(ext_id, reader.get_offset()-8)
        ext.add_a(Astring('name', reader.read_bytes(4).decode()))
        ext.add_a(Auint('vcn', reader.read_dw()))
        ext.add_a(Abytes('bitmap', reader.read_bytes(16), 'red'))
        ext.add_a(Auint('svn', reader.read_dw()))
        read_len = reader.get_offset() - begin_off
        reader.ff_data(ext_len - read_len)
    elif ext_type == 17:
        ext = AdspMetadataFileExt(ext_id, reader.get_offset()-8)
        ext.add_a(Auint('adsp_imr_type', reader.read_dw(), 'red'))
        # skip reserved part
        reader.read_bytes(16)
        reader.read_dw()
        reader.read_dw()
        #
        ext.add_a(Auint('version', reader.read_dw()))
        ext.add_a(Abytes('sha_hash', reader.read_bytes(32)))
        ext.add_a(Auint('base_offset', reader.read_dw()))
        ext.add_a(Auint('limit_offset', reader.read_dw()))
        ext.add_a(Abytes('attributes', reader.read_bytes(16)))
    else:
        ext = MftExtension(ext_id, 'Other Extension', reader.get_offset()-8)
        reader.ff_data(ext_len-8)
    ext.add_a(Auint('type', ext_type))
    ext.add_a(Auint('length', ext_len))
    return ext

def parse_adsp_manifest_hdr(reader):
    """ Parses ADSP manifest hader from sof binary
    """
    # Verify signature
    try:
        sig = reader.read_bytes(4).decode()
    except UnicodeDecodeError:
        print('\n' + reader.offset_to_string() + \
              '\terror: Failed to decode signature, wrong position?')
        sys.exit(1)
    if sig != '$AM1':
        reader.error('ADSP Manifest NOT found!', -4)
        sys.exit(1)
    reader.info('ADSP Manifest (' + sig + ')', -4)

    hdr = Component('adsp_mft_hdr', 'ADSP Manifest Header',
                    reader.get_offset() -4)
    hdr.add_a(Astring('sig', sig))

    hdr.add_a(Auint('size', reader.read_dw()))
    hdr.add_a(Astring('name', chararr_to_string(reader.read_bytes(8), 8)))
    hdr.add_a(Auint('preload', reader.read_dw()))
    hdr.add_a(Auint('fw_image_flags', reader.read_dw()))
    hdr.add_a(Auint('feature_mask', reader.read_dw()))
    hdr.add_a(Aversion('build_version', reader.read_w(), reader.read_w(),
                       reader.read_w(), reader.read_w()))

    hdr.add_a(Adec('num_module_entries', reader.read_dw()))
    hdr.add_a(Ahex('hw_buf_base_addr', reader.read_dw()))
    hdr.add_a(Auint('hw_buf_length', reader.read_dw()))
    hdr.add_a(Ahex('load_offset', reader.read_dw()))

    return hdr

def parse_adsp_manifest_mod_entry(index, reader):
    """ Parses ADSP manifest module entry from sof binary
    """
    # Verify Mod Entry signature
    try:
        sig = reader.read_bytes(4).decode()
    except UnicodeDecodeError:
        print(reader.offset_to_string() + \
              '\terror: Failed to decode ModuleEntry signature')
        sys.exit(1)
    if sig != '$AME':
        reader.error('ModuleEntry signature NOT found!')
        sys.exit(1)
    reader.info('Module Entry signature found (' + sig + ')', -4)

    mod = Component('mod_entry_'+repr(index), 'Module Entry',
                    reader.get_offset() -4)
    mod.add_a(Astring('sig', sig))

    mod.add_a(Astring('mod_name',
                      chararr_to_string(reader.read_bytes(8), 8)))
    mod.add_a(Astring('uuid', reader.read_uuid()))
    me_type = reader.read_dw()
    mod.add_a(Astring('type',
                      hex(me_type) + ' ' + mod_type_to_string(me_type)))
    mod.add_a(Abytes('hash', reader.read_bytes(32)))
    mod.add_a(Ahex('entry_point', reader.read_dw()))
    mod.add_a(Adec('cfg_offset', reader.read_w()))
    mod.add_a(Adec('cfg_count', reader.read_w()))
    mod.add_a(Auint('affinity_mask', reader.read_dw()))
    mod.add_a(Adec('instance_max_count', reader.read_w()))
    mod.add_a(Auint('instance_stack_size', reader.read_w()))
    for i in range(0, 3):
        seg_flags = reader.read_dw()
        mod.add_a(Astring('seg_'+repr(i)+' flags',
                          hex(seg_flags) + ' ' + seg_flags_to_string(seg_flags)))
        mod.add_a(Ahex('seg_'+repr(i)+' v_base_addr', reader.read_dw()))
        mod.add_a(Ahex('seg_'+repr(i)+' file_offset', reader.read_dw()))

    return mod

def parse_adsp_manifest(reader, name, add_module_entries):
    """ Parses ADSP manifest from sof binary
    """
    adsp_mft = AdspManifest(name, reader.get_offset())
    adsp_mft.add_comp(parse_adsp_manifest_hdr(reader))
    num_module_entries = adsp_mft.cdir['adsp_mft_hdr'].adir['num_module_entries'].val
    for i in range(0, num_module_entries):
        mod_entry = parse_adsp_manifest_mod_entry(i, reader)
        if add_module_entries:
            adsp_mft.add_comp(mod_entry)

    return adsp_mft

def parse_fw_bin(path, verbose, add_module_entries):
    """ Parses sof binary
    """
    reader = BinReader(path, verbose)

    parsed_bin = FwBin()
    parsed_bin.add_a(Astring('file_name', reader.file_name))
    parsed_bin.add_a(Auint('file_size', reader.file_size))
    parsed_bin.add_comp(parse_extended_manifest(reader))
    parsed_bin.add_comp(parse_cse_manifest(reader, add_module_entries))

    if verbose:
        print('Parsing finished')
    return parsed_bin

class BinReader():
    """ sof binary reader
    """
    def __init__(self, path, verbose):
        self.verbose = verbose
        if self.verbose:
            print('Reading SOF ri image ' + path)
        self.file_name = path
        # read the content
        self.data = open(path, 'rb').read()
        self.file_size = len(self.data)
        if self.verbose:
            print('File size ' + uint_to_string(self.file_size, True))
        self.cur_offset = 0

    def get_offset(self):
        """ Retrieve the offset, the reader is at
        """
        return self.cur_offset

    def ff_data(self, delta_offset):
        """ Forwards the read pointer by specified number of bytes
        """
        self.cur_offset += delta_offset

    def set_offset(self, offset):
        """ Set current reader offset
        """
        old_offset = self.cur_offset
        self.cur_offset = offset
        return old_offset

    def get_data(self, beg, length):
        """ Retrieves the data from beg to beg+length.
            This one is good to peek the data w/o advancing the read pointer
        """
        return self.data[self.cur_offset +beg : self.cur_offset +beg +length]

    def read_bytes(self, count):
        """ Reads the specified number of bytes from the stream
        """
        bts = self.get_data(0, count)
        self.ff_data(count)
        return bts

    def read_dw(self):
        """ Reads a dword from the stream
        """
        dword, = struct.unpack('I', self.get_data(0, 4))
        self.ff_data(4)
        return dword

    def read_w(self):
        """ Reads a word from the stream
        """
        word, = struct.unpack('H', self.get_data(0, 2))
        self.ff_data(2)
        return word

    def read_b(self):
        """ Reads a byte from the stream
        """
        byte, = struct.unpack('B', self.get_data(0, 1))
        self.ff_data(1)
        return byte

    def read_uuid(self):
        """ Reads a UUID from the stream and returns as string
        """
        out = '{:08x}'.format(self.read_dw())
        out += '-'+'{:04x}'.format(self.read_w())
        out += '-'+'{:04x}'.format(self.read_w())
        out += '-'+'{:02x}'.format(self.read_b()) + \
               '{:02x}'.format(self.read_b()) + '-'
        for _ in range(0, 6):
            out += '{:02x}'.format(self.read_b())
        return out

    def offset_to_string(self, delta=0):
        """ Retrieves readable representation of the current offset value
        """
        return uint_to_string(self.cur_offset+delta)

    def info(self, loginfo, off_delta=0, verb_info=True):
        """ Prints 'info' log to the output, respects verbose mode
        """
        if verb_info and not self.verbose:
            return
        print(self.offset_to_string(off_delta) + '\t' + loginfo)

    def error(self, logerror, off_delta=0):
        """ Prints 'error' log to the output
        """
        print(self.offset_to_string(off_delta) + '\terror: ' + logerror)

# Data Model

class Attribute():
    """ Attribute: base class with global formatting options
    """
    no_colors = False
    full_bytes = True

class Auint(Attribute):
    """ Attribute : unsigned integer
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        if Attribute.no_colors:
            return uint_to_string(self.val)
        return '{}{}{}'.format(change_color(self.color),
                               uint_to_string(self.val),
                               change_color('none'))

class Ahex(Attribute):
    """ Attribute : unsigned integer printed as hex
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        if Attribute.no_colors:
            return hex(self.val)
        return '{}{}{}'.format(change_color(self.color), hex(self.val),
                               change_color('none'))

class Adec(Attribute):
    """ Attribute: integer printed as dec
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return repr(self.val)

class Abytes(Attribute):
    """ Attribute: array of bytes
    """
    def __init__(self, name, val, color='none'):
        self.name = name
        self.val = val
        self.color = color

    def __str__(self):
        length = len(self.val)
        if Attribute.no_colors:
            out = ''
        else:
            out = '{}'.format(change_color(self.color))
        if Attribute.full_bytes or length <= 16:
            out += ' '.join(['{:02x}'.format(b) for b in self.val])
        else:
            out += ' '.join('{:02x}'.format(b) for b in self.val[:8])
            out += ' ... '
            out += ' '.join('{:02x}'.format(b) for b in self.val[length-8:length])
        if not Attribute.no_colors:
            out += '{}'.format(change_color('none'))
        return out

class Adate(Attribute):
    """ Attribute: Date in BCD format
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return date_to_string(self.val)

class Astring(Attribute):
    """ Attribute: String
    """
    def __init__(self, name, val):
        self.name = name
        self.val = val

    def __str__(self):
        return self.val

class Aversion(Attribute):
    """ Attribute: version
    """
    def __init__(self, name, major, minor, hotfix, build):
        self.name = name
        self.val = '{:d}.{:d}.{:d}.{:d}'.format(major, minor, hotfix, build)

    def __str__(self):
        return self.val

class Amodulus(Abytes):
    """ Attribute: modulus from RSA public key
    """
    def __init__(self, name, val, val_type):
        super().__init__(name, val)
        self.val_type = val_type

    def __str__(self):
        out = super().__str__()
        if not Attribute.full_bytes:
            if Attribute.no_colors:
                out += ' ({})'.format(self.val_type)
            else:
                out += ' {}({}){}'.format(change_color('red'), self.val_type,
                                          change_color('none'))
        return out

class Component():
    """ A component of sof binary
    """
    def __init__(self, uid, name, file_offset):
        self.uid = uid
        self.name = name
        self.file_offset = file_offset
        self.attribs = []
        self.adir = {}
        self.max_attr_name_len = 0
        self.components = []
        self.cdir = {}

    def add_a(self, attrib):
        """ Adds an attribute
        """
        self.max_attr_name_len = max(self.max_attr_name_len,
                                     len(attrib.name))
        self.attribs.append(attrib)
        self.adir[attrib.name] = attrib

    def add_comp(self, comp):
        """ Adds a nested component
        """
        self.components.append(comp)
        self.cdir[comp.uid] = comp

    def get_comp(self, comp_uid):
        """ Retrieves a nested component by id
        """
        for comp in self.components:
            if comp.uid == comp_uid:
                return comp
        return None

    def dump_info(self, pref):
        """ Prints out the content (name, all attributes, and nested comps)
        """
        print(pref + self.name)
        for attrib in self.attribs:
            print("{:}  {:<{:}} {:}".format(pref, attrib.name,
                                            self.max_attr_name_len, attrib))
        self.dump_comp_info(pref)

    def dump_attrib_info(self, pref, attr_name):
        """ Prints out a single attribute
        """
        attrib = self.adir[attr_name]
        print("{:}  {:<{:}} {:}".format(pref, attrib.name,
                                        self.max_attr_name_len, attrib))

    def dump_comp_info(self, pref, name_filter=''):
        """ Prints out all nested components (filtered by name set to 'filter')
        """
        for comp in self.components:
            if comp.name == name_filter:
                continue
            print()
            comp.dump_info(pref + '  ')

class ExtendedManifest(Component):
    """ Extended manifest
    """
    def __init__(self):
        super(ExtendedManifest, self).__init__('ext_mft',
                                               'Extended Manifest', 0)

    def dump_info(self, pref):
        hdr = self.cdir['ext_mft_hdr']
        if hdr.adir['length'].val == 0:
            return
        out = '{}{}'.format(pref, self.name)
        out += ' ver {}'.format(hdr.adir['ver'])
        out += ' entries {}'.format(hdr.adir['entries'])
        print(out)
        self.dump_comp_info(pref, name_filter='Header')

class CseManifest(Component):
    """ CSE Manifest
    """
    def __init__(self, offset):
        super(CseManifest, self).__init__('cse_mft', 'CSE Manifest', offset)

    def dump_info(self, pref):
        hdr = self.cdir['cse_mft_hdr']
        print('{}{} ver {} checksum {} partition name {}'.
              format(pref,
                     self.name, hdr.adir['header_version'],
                     hdr.adir['checksum'], hdr.adir['partition_name']))
        self.dump_comp_info(pref, name_filter='Header')

class CssManifest(Component):
    """ CSS Manifest
    """
    def __init__(self, name, offset):
        super(CssManifest, self).__init__('css_mft', name, offset)

    def dump_info(self, pref):
        hdr = self.cdir['css_mft_hdr']
        out = '{}{} (CSS Manifest)'.format(pref, self.name)
        out += ' type {}'.format(hdr.adir['type'])
        out += ' ver {}'.format(hdr.adir['header_version'])
        out += ' date {}'.format(hdr.adir['date'])
        print(out)
        print('{}  Rsvd0 {}'.
              format(pref, hdr.adir['reserved0']))
        print('{}  Modulus size (dwords) {}'.
              format(pref, hdr.adir['modulus_size']))
        print('{}    {}'.format(pref, hdr.adir['modulus']))
        print('{}  Exponent size (dwords) {}'.
              format(pref,
                     hdr.adir['exponent_size']))
        print('{}    {}'.format(pref, hdr.adir['exponent']))
        print('{}  Signature'.format(pref))
        print('{}    {}'.format(pref, hdr.adir['signature']))
        # super().dump_info(pref)
        self.dump_comp_info(pref, name_filter='Header')

class MftExtension(Component):
    """ Manifest Extension
    """
    def __init__(self, ext_id, name, offset):
        super(MftExtension, self).__init__('mft_ext'+repr(ext_id), name,
                                           offset)

    def dump_info(self, pref):
        print('{}{} type {} length {}'.
              format(pref, self.name,
                     self.adir['type'], self.adir['length']))

class PlatFwAuthExtension(MftExtension):
    """ Platform FW Auth Extension
    """
    def __init__(self, ext_id, offset):
        super(PlatFwAuthExtension,
              self).__init__(ext_id, 'Plat Fw Auth Extension', offset)

    def dump_info(self, pref):
        out = '{}{}'.format(pref, self.name)
        out += ' name {}'.format(self.adir['name'])
        out += ' vcn {}'.format(self.adir['vcn'])
        out += ' bitmap {}'.format(self.adir['bitmap'])
        out += ' svn {}'.format(self.adir['svn'])
        print(out)

class AdspMetadataFileExt(MftExtension):
    """ ADSP Metadata File Extension
    """
    def __init__(self, ext_id, offset):
        super(AdspMetadataFileExt,
              self).__init__(ext_id, 'ADSP Metadata File Extension',
                             offset)

    def dump_info(self, pref):
        out = '{}{}'.format(pref, self.name)
        out += ' ver {}'.format(self.adir['version'])
        out += ' base offset {}'.format(self.adir['base_offset'])
        out += ' limit offset {}'.format(self.adir['limit_offset'])
        print(out)
        print('{}  IMR type {}'.format(pref, self.adir['adsp_imr_type']))
        print('{}  Attributes'.format(pref))
        print('{}    {}'.format(pref, self.adir['attributes']))

class AdspManifest(Component):
    """ ADSP Manifest
    """
    def __init__(self, name, offset):
        super(AdspManifest, self).__init__('adsp_mft', name, offset)

    def dump_info(self, pref):
        hdr = self.cdir['adsp_mft_hdr']
        out = '{}{} (ADSP Manifest)'.format(pref, self.name)
        out += ' name {}'.format(hdr.adir['name'])
        out += ' build ver {}'.format(hdr.adir['build_version'])
        out += ' feature mask {}'.format(hdr.adir['feature_mask'])
        out += ' image flags {}'.format(hdr.adir['fw_image_flags'])
        print(out)
        print('{}  HW buffers base address {} length {}'.
              format(pref,
                     hdr.adir['hw_buf_base_addr'],
                     hdr.adir['hw_buf_length']))
        print('{}  Load offset {}'.format(pref,
                                          hdr.adir['load_offset']))
        self.dump_comp_info(pref, 'ADSP Manifest Header')

class FwBin(Component):
    """ Parsed sof binary
    """
    def __init__(self):
        super(FwBin, self).__init__('bin', 'SOF Binary', 0)

    def dump_info(self, pref):
        """ Print out the content
        """
        print('SOF Binary {} size {}'.format(
            self.adir['file_name'], self.adir['file_size']))
        self.dump_comp_info(pref)

def main(args):
    """ main function
    """
    Attribute.no_colors = args.no_colors
    Attribute.full_bytes = args.full_bytes

    fw_bin = parse_fw_bin(args.sof_ri_path, args.verbose, not args.headers)
    fw_bin.dump_info('')

if __name__ == "__main__":
    ARGS = parse_params()
    main(ARGS)
