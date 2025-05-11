#pragma once

#include "Luna/Runtime/Base.hpp"
#include "Emulator.hpp"
using namespace Luna;

struct Emulator;

using instruction_func_t = void(Emulator* emu);

//! A map of all instruction functions by their opcodes.
extern instruction_func_t* instructions_map[256];

//! Combines one 16-bit value from two 8-bit values.
inline constexpr u16 make_u16(u8 low, u8 high) { return ((u16)low) | (((u16)high) << 8); }

//! Reads 16-bit immediate data.
inline u16 read_d16(Emulator* emu)
{
    u16 r = make_u16(emu->bus_read(emu->cpu.pc), emu->bus_read(emu->cpu.pc + 1));
    emu->cpu.pc += 2;
    return r;
}

//! Reads 8-bit immediate data.
inline u8 read_d8(Emulator* emu)
{
    u8 r = emu->bus_read(emu->cpu.pc);
    emu->cpu.pc++;
    return r;
}