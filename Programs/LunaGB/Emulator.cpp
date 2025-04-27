#include "Emulator.hpp"
#include "Cartridge.hpp"
#include "Luna/Runtime/Error.hpp"
#include "Luna/Runtime/Memory.hpp"
#include <Luna/Runtime/Log.hpp>

RV Emulator::init(const void* cartridge_data, usize cartridge_data_size)
{
    luassert(cartridge_data && cartridge_data_size);
    rom_data = reinterpret_cast<byte_t*>(memalloc(cartridge_data_size));
    memcpy(rom_data, cartridge_data, cartridge_data_size);
    rom_data_size = cartridge_data_size;

    // Check cartridge data
    CartridgeHeader* header = get_cartridge_header(rom_data);
    u8 checksum = 0;
    for (u16 adress = 0x0134; adress <= 0x014C; adress++)
    {
        checksum = checksum - rom_data[adress] - 1;
    }
    if (checksum != header->checksum)
    {
        return set_error(BasicError::bad_data(),
                         "The cartridge checksum dismatched. Expected: %u, computed: %u",
                         (u32)header->checksum, (u32)checksum);
    }

    // Print cartridge load info
    c8 title[16];
    snprintf(title, 16, "%s", header->title);
    log_info("LunaGB", "Cartridge Loaded.");
    log_info("LunaGB", "Title    : %s", title);
    log_info("LunaGB", "Type     : %2.2X (%s)", (u32)header->cartridge_type, get_cartridge_type_name(header->cartridge_type));
    log_info("LunaGB", "ROM Size : %u KB", (u32)(32 << header->rom_size));
    log_info("LunaGB", "RAM Size : %2.2X (%s)", (u32)header->ram_size, get_cartridge_ram_size_name(header->ram_size));
    log_info("LunaGB", "LIC Code : %2.2X (%s)", (u32)header->lic_code, get_cartridge_lic_code_name(header->lic_code));
    log_info("LunaGB", "ROM Ver. : %2.2X", (u32) header->version);

    return ok;
}

void Emulator::close()
{
    if (rom_data)
    {
        memfree(rom_data);
        rom_data = nullptr;
        rom_data_size = 0;
        log_info("LunaGB", "Cartridge Unloaded.");
    }
}

void Emulator::update(f64 delta_time)
{
    u64 frame_cycles = (u64) ((f32) (4194304.0 * delta_time) * clock_speed_scale);
    u64 end_cycles = clock_cycles + frame_cycles;
    while (clock_cycles < end_cycles)
    {
        /*TODO: step emulator and advance clock_cycles*/
    }
}

void Emulator::tick(u32 mcycles)
{
    u32 tick_cycles = mcycles * 4; // real clock cycle
    for (u32 i = 0; i < tick_cycles; ++i)
    {
        ++clock_cycles;
    }
}