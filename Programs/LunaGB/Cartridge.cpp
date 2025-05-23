#include "Cartridge.hpp"
#include "Emulator.hpp"
#include "Luna/Runtime/Log.hpp"

static const c8* ROM_TYEPS[] = {
    "ROM ONLY",
    "MBC1",
    "MBC1+RAM",
    "MBC1+RAM+BATTERY",
    "0x04 ???",
    "MBC2",
    "MBC2+BATTERY",
    "0x07 ???",
    "ROM+RAM",
    "ROM+RAM+BATTERY",
    "0x0A ???",
    "MMM01",
    "MMM01+RAM",
    "MMM01+RAM+BATTERY",
    "0x0E ???",
    "MBC3+TIMER+BATTERY",
    "MBC3+TIMER+RAM+BATTERY",
    "MBC3",
    "MBC3+RAM",
    "MBC3+RAM+BATTERY",
    "0x14 ???",
    "0x15 ???",
    "0x16 ???",
    "0x17 ???",
    "0x18 ???",
    "MBC5",
    "MBC5+RAM",
    "MBC5+RAM+BATTERY",
    "MBC5+RUMBLE",
    "MBC5+RUMBLE+RAM",
    "MBC5+RUMBLE+RAM+BATTERT",
    "0x1F ???",
    "MBC6",
    "0x21 ???",
    "MBC7+SENSOR+RUMBLE+RAM+BATTERY",
};

const c8* get_cartridge_type_name(u8 type)
{
    if (type <= 0x22)
        return ROM_TYEPS[type];

    return "UNKNOWN";
}

static const c8* RAM_SIZE_TYPES[] = {
    "0",
    "-",
    "8 KB (1 bank)",
    "32 KB (4 banks of 8 KB each)",
    "128 KB (16 banks of 8 KB each)",
    "64 KB (8 banks of 8 KB each)",
};

const c8* get_cartridge_ram_size_name(u8 ram_size_code)
{
    if (ram_size_code <= 0x05)
        return RAM_SIZE_TYPES[ram_size_code];

    return "UNKNOWN";
}

const c8* get_cartridge_lic_code_name(u8 lic_code)
{
    switch(lic_code)
    {
        case 0x00 : return "None";
        case 0x01 : return "Nintendo R&D1";
        case 0x08 : return "Capcom";
        case 0x13 : return "Electronic Arts";
        case 0x18 : return "Hudson Soft";
        case 0x19 : return "b-ai";
        case 0x20 : return "kss";
        case 0x22 : return "pow";
        case 0x24 : return "PCM Complete";
        case 0x25 : return "san-x";
        case 0x28 : return "Kemco Japan";
        case 0x29 : return "seta";
        case 0x30 : return "Viacom";
        case 0x31 : return "Nintendo";
        case 0x32 : return "Bandai";
        case 0x33 : return "Ocean/Acclaim";
        case 0x34 : return "Konami";
        case 0x35 : return "Hector";
        case 0x37 : return "Taito";
        case 0x38 : return "Hudson";
        case 0x39 : return "Banpresto";
        case 0x41 : return "Ubi Soft";
        case 0x42 : return "Atlus";
        case 0x44 : return "Malibu";
        case 0x46 : return "angel";
        case 0x47 : return "Bullet-Proof";
        case 0x49 : return "irem";
        case 0x50 : return "Absolute";
        case 0x51 : return "Acclaim";
        case 0x52 : return "Activision";
        case 0x53 : return "American sammy";
        case 0x54 : return "Konami";
        case 0x55 : return "Hi tech entertainment";
        case 0x56 : return "LJN";
        case 0x57 : return "Matchbox";
        case 0x58 : return "Mattel";
        case 0x59 : return "Milton Bradley";
        case 0x60 : return "Titus";
        case 0x61 : return "Virgin";
        case 0x64 : return "LucasArts";
        case 0x67 : return "Ocean";
        case 0x69 : return "Electronic Arts";
        case 0x70 : return "Infogrames";
        case 0x71 : return "Interplay";
        case 0x72 : return "Broderbund";
        case 0x73 : return "sculptured";
        case 0x75 : return "sci";
        case 0x78 : return "THQ";
        case 0x79 : return "Accolade";
        case 0x80 : return "misawa";
        case 0x83 : return "lozc";
        case 0x86 : return "Tokuma Shoten Intermedia";
        case 0x87 : return "Tsukuda Original";
        case 0x91 : return "Chunsoft";
        case 0x92 : return "Video system";
        case 0x93 : return "Ocean/Acclaim";
        case 0x95 : return "Varie";
        case 0x96 : return "Yonezawa/s’pal";
        case 0x97 : return "Kaneko";
        case 0x99 : return "Pack in soft";
        case 0xA4 : return "Konami (Yu-Gi-Oh!)";
        default: break;
    }
    return "UNKNOWN";
}

u8 cartridge_read(Emulator* emu, u16 addr)
{
    if (addr <= 0x7FFF)
    {
        return emu->rom_data[addr];
    }
    log_error("LunaGB", "Unsupported cartridge read address: 0x%04X", (u32)addr);
    return 0xFF;
}

void cartridge_write(Emulator* emu, u16 addr, u8 data)
{
    log_error("LunaGB", "Unsupported cartridge write address: 0x%04X", (u32)addr);
}