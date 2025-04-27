#pragma once

#include "Luna/Runtime/Base.hpp"
#include <Luna/Runtime/Result.hpp>
using namespace Luna;

struct Emulator
{
    byte_t* rom_data = nullptr;
    usize rom_data_size = 0;

    //! `true` if the emulation is paused.
    bool pause = false;
    //! The cycles counter.
    u64 clock_cycles = 0;
    //! The clock speed scale value.
    f32 clock_speed_scale = 1.0;

    RV init(const void* cartridge_data, usize cartridge_data_size);
    void close();
    ~Emulator()
    {
        close();
    }

    void update(f64 delta_time);
    //! Advances clock and updates all hardware states (except CPU).
    //! This is called from CPU instructions.
    //! @param[in] mcycles The number of machine cycles to tick.
    void tick(u32 mcycles);
};