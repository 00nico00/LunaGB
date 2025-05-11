#include "Instructions.hpp"
#include "Emulator.hpp"

void x00_nop(Emulator* emu)
{
    // Do nothing
    emu->tick(1);
}

void x01_ld_bc_d16(Emulator* emu)
{
    emu->cpu.bc(read_d16(emu));
    emu->tick(3);
}

void x02_ld_mbc_a(Emulator* emu)
{
    emu->bus_write(emu->cpu.bc(), emu->cpu.a);
    emu->tick(2);
}

void x06_ld_b_d8(Emulator* emu)
{
    emu->cpu.b = read_d8(emu);
    emu->tick(2);
}

void x08_ld_a16_sp(Emulator* emu)
{
    u16 addr = read_d16(emu);
    emu->tick(2);
    emu->bus_write(addr, (u8)(emu->cpu.sp & 0xFF));
    emu->tick(1);
    emu->bus_write(addr + 1, (u8)(emu->cpu.sp >> 8));
    emu->tick(1);
}

void x0a_ld_a_mbc(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(emu->cpu.bc());
    emu->tick(2);
}

void x0e_ld_c_d8(Emulator* emu)
{
    emu->cpu.c = read_d8(emu);
    emu->tick(2);
}

void x11_ld_de_d16(Emulator* emu)
{
    emu->cpu.de(read_d16(emu));
    emu->tick(3);
}

void x12_ld_mde_a(Emulator* emu)
{
    emu->bus_write(emu->cpu.de(), emu->cpu.a);
    emu->tick(2);
}

void x16_ld_d_d8(Emulator* emu)
{
    emu->cpu.d = read_d8(emu);
    emu->tick(2);
}

void x1a_ld_a_mde(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(emu->cpu.de());
    emu->tick(2);
}

void x1e_ld_e_d8(Emulator* emu)
{
    emu->cpu.e = read_d8(emu);
    emu->tick(2);
}

void x21_ld_hl_d16(Emulator* emu)
{
    emu->cpu.hl(read_d16(emu));
    emu->tick(3);
}

void x22_ldi_mhl_a(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.a);
    emu->cpu.hl(emu->cpu.hl() + 1);
    emu->tick(2);
}

void x26_ld_h_d8(Emulator* emu)
{
    emu->cpu.h = read_d8(emu);
    emu->tick(2);
}

void x2a_ldi_a_mhl(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(emu->cpu.hl());
    emu->cpu.hl(emu->cpu.hl() + 1);
    emu->tick(2);
}

void x2e_ld_l_d8(Emulator* emu)
{
    emu->cpu.l = read_d8(emu);
    emu->tick(2);
}

void x31_ld_sp_d16(Emulator* emu)
{
    emu->cpu.sp = read_d16(emu);
    emu->tick(3);
}

void x32_ldd_mhl_a(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.a);
    emu->cpu.hl(emu->cpu.hl() - 1);
    emu->tick(2);
}

void x36_ld_mhl_d8(Emulator* emu)
{
    u8 data = read_d8(emu);
    emu->tick(1);
    emu->bus_write(emu->cpu.hl(), data);
    emu->tick(2);
}

void x3a_ldd_a_mhl(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(emu->cpu.hl());
    emu->cpu.hl(emu->cpu.hl() - 1);
    emu->tick(2);
}

void x3e_ld_a_d8(Emulator* emu)
{
    emu->cpu.a = read_d8(emu);
    emu->tick(2);
}

void x40_ld_b_b(Emulator* emu)
{
    emu->cpu.b = emu->cpu.b;
    emu->tick(1);
}

void x41_ld_b_c(Emulator* emu)
{
    emu->cpu.b = emu->cpu.c;
    emu->tick(1);
}

void x42_ld_b_d(Emulator* emu)
{
    emu->cpu.b = emu->cpu.d;
    emu->tick(1);
}

void x43_ld_b_e(Emulator* emu)
{
    emu->cpu.b = emu->cpu.e;
    emu->tick(1);
}

void x44_ld_b_h(Emulator* emu)
{
    emu->cpu.b = emu->cpu.h;
    emu->tick(1);
}

void x45_ld_b_l(Emulator* emu)
{
    emu->cpu.b = emu->cpu.l;
    emu->tick(1);
}

void x46_ld_b_mhl(Emulator* emu)
{
    emu->cpu.b = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x47_ld_b_a(Emulator* emu)
{
    emu->cpu.b = emu->cpu.a;
    emu->tick(1);
}

void x48_ld_c_b(Emulator* emu)
{
    emu->cpu.c = emu->cpu.b;
    emu->tick(1);
}

void x49_ld_c_c(Emulator* emu)
{
    emu->cpu.c = emu->cpu.c;
    emu->tick(1);
}

void x4a_ld_c_d(Emulator* emu)
{
    emu->cpu.c = emu->cpu.d;
    emu->tick(1);
}

void x4b_ld_c_e(Emulator* emu)
{
    emu->cpu.c = emu->cpu.e;
    emu->tick(1);
}

void x4c_ld_c_h(Emulator* emu)
{
    emu->cpu.c = emu->cpu.h;
    emu->tick(1);
}

void x4d_ld_c_l(Emulator* emu)
{
    emu->cpu.c = emu->cpu.l;
    emu->tick(1);
}

void x4e_ld_c_mhl(Emulator* emu)
{
    emu->cpu.c = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x4f_ld_c_a(Emulator* emu)
{
    emu->cpu.c = emu->cpu.a;
    emu->tick(1);
}

void x50_ld_d_b(Emulator* emu)
{
    emu->cpu.d = emu->cpu.b;
    emu->tick(1);
}

void x51_ld_d_c(Emulator* emu)
{
    emu->cpu.d = emu->cpu.c;
    emu->tick(1);
}

void x52_ld_d_d(Emulator* emu)
{
    emu->cpu.d = emu->cpu.d;
    emu->tick(1);
}

void x53_ld_d_e(Emulator* emu)
{
    emu->cpu.d = emu->cpu.e;
    emu->tick(1);
}

void x54_ld_d_h(Emulator* emu)
{
    emu->cpu.d = emu->cpu.h;
    emu->tick(1);
}

void x55_ld_d_l(Emulator* emu)
{
    emu->cpu.d = emu->cpu.l;
    emu->tick(1);
}

void x56_ld_d_mhl(Emulator* emu)
{
    emu->cpu.d = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x57_ld_d_a(Emulator* emu)
{
    emu->cpu.d = emu->cpu.a;
    emu->tick(1);
}

void x58_ld_e_b(Emulator* emu)
{
    emu->cpu.e = emu->cpu.b;
    emu->tick(1);
}

void x59_ld_e_c(Emulator* emu)
{
    emu->cpu.e = emu->cpu.c;
    emu->tick(1);
}

void x5a_ld_e_d(Emulator* emu)
{
    emu->cpu.e = emu->cpu.d;
    emu->tick(1);
}

void x5b_ld_e_e(Emulator* emu)
{
    emu->cpu.e = emu->cpu.e;
    emu->tick(1);
}

void x5c_ld_e_h(Emulator* emu)
{
    emu->cpu.e = emu->cpu.h;
    emu->tick(1);
}

void x5d_ld_e_l(Emulator* emu)
{
    emu->cpu.e = emu->cpu.l;
    emu->tick(1);
}

void x5e_ld_e_mhl(Emulator* emu)
{
    emu->cpu.e = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x5f_ld_e_a(Emulator* emu)
{
    emu->cpu.e = emu->cpu.a;
    emu->tick(1);
}

void x60_ld_h_b(Emulator* emu)
{
    emu->cpu.h = emu->cpu.b;
    emu->tick(1);
}

void x61_ld_h_c(Emulator* emu)
{
    emu->cpu.h = emu->cpu.c;
    emu->tick(1);
}

void x62_ld_h_d(Emulator* emu)
{
    emu->cpu.h = emu->cpu.d;
    emu->tick(1);
}

void x63_ld_h_e(Emulator* emu)
{
    emu->cpu.h = emu->cpu.e;
    emu->tick(1);
}

void x64_ld_h_h(Emulator* emu)
{
    emu->cpu.h = emu->cpu.h;
    emu->tick(1);
}

void x65_ld_h_l(Emulator* emu)
{
    emu->cpu.h = emu->cpu.l;
    emu->tick(1);
}

void x66_ld_h_mhl(Emulator* emu)
{
    emu->cpu.h = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x67_ld_h_a(Emulator* emu)
{
    emu->cpu.h = emu->cpu.a;
    emu->tick(1);
}

void x68_ld_l_b(Emulator* emu)
{
    emu->cpu.l = emu->cpu.b;
    emu->tick(1);
}

void x69_ld_l_c(Emulator* emu)
{
    emu->cpu.l = emu->cpu.c;
    emu->tick(1);
}

void x6a_ld_l_d(Emulator* emu)
{
    emu->cpu.l = emu->cpu.d;
    emu->tick(1);
}

void x6b_ld_l_e(Emulator* emu)
{
    emu->cpu.l = emu->cpu.e;
    emu->tick(1);
}

void x6c_ld_l_h(Emulator* emu)
{
    emu->cpu.l = emu->cpu.h;
    emu->tick(1);
}

void x6d_ld_l_l(Emulator* emu)
{
    emu->cpu.l = emu->cpu.l;
    emu->tick(1);
}

void x6e_ld_l_mhl(Emulator* emu)
{
    emu->cpu.l = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x6f_ld_l_a(Emulator* emu)
{
    emu->cpu.l = emu->cpu.a;
    emu->tick(1);
}

void x70_ld_mhl_b(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.b);
    emu->tick(2);
}

void x71_ld_mhl_c(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.c);
    emu->tick(2);
}

void x72_ld_mhl_d(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.d);
    emu->tick(2);
}

void x73_ld_mhl_e(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.e);
    emu->tick(2);
}

void x74_ld_mhl_h(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.h);
    emu->tick(2);
}

void x75_ld_mhl_l(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.l);
    emu->tick(2);
}

void x77_ld_mhl_a(Emulator* emu)
{
    emu->bus_write(emu->cpu.hl(), emu->cpu.a);
    emu->tick(2);
}

void x78_ld_a_b(Emulator* emu)
{
    emu->cpu.a = emu->cpu.b;
    emu->tick(1);
}

void x79_ld_a_c(Emulator* emu)
{
    emu->cpu.a = emu->cpu.c;
    emu->tick(1);
}

void x7a_ld_a_d(Emulator* emu)
{
    emu->cpu.a = emu->cpu.d;
    emu->tick(1);
}

void x7b_ld_a_e(Emulator* emu)
{
    emu->cpu.a = emu->cpu.e;
    emu->tick(1);
}

void x7c_ld_a_h(Emulator* emu)
{
    emu->cpu.a = emu->cpu.h;
    emu->tick(1);
}

void x7d_ld_a_l(Emulator* emu)
{
    emu->cpu.a = emu->cpu.l;
    emu->tick(1);
}

void x7e_ld_a_mhl(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(emu->cpu.hl());
    emu->tick(2);
}

void x7f_ld_a_a(Emulator* emu)
{
    emu->cpu.a = emu->cpu.a;
    emu->tick(1);
}

void xe0_ldh_m8_a(Emulator* emu)
{
    u8 addr = read_d8(emu);
    emu->tick(1);
    emu->bus_write(0xFF00 + (u16)addr, emu->cpu.a);
    emu->tick(2);
}

//! LD (C), A : Stores A to memory at 0xFF00 + C.
void xe2_ld_mc_a(Emulator* emu)
{
    emu->bus_write(0xFF00 + (u16)emu->cpu.c, emu->cpu.a);
    emu->tick(2);
}

void xea_ld_a16_a(Emulator* emu)
{
    u16 addr = read_d16(emu);
    emu->tick(2);
    emu->bus_write(addr, emu->cpu.a);
    emu->tick(2);
}

void xf0_ldh_a_m8(Emulator* emu)
{
    u8 addr = read_d8(emu);
    emu->tick(1);
    emu->cpu.a = emu->bus_read(0xFF00 + (u16)addr);
    emu->tick(2);
}

void f2_ld_a_mc(Emulator* emu)
{
    emu->cpu.a = emu->bus_read(0xFF00 + (u16)emu->cpu.c);
    emu->tick(2);
}

void xfa_ld_a_a16(Emulator* emu)
{
    u16 addr = read_d16(emu);
    emu->tick(2);
    emu->cpu.a = emu->bus_read(addr);
    emu->tick(2);
}

//! LD HL, SP + r8 : Loads SP + r8 to HL.
void f8_ld_hl_sp_r8(Emulator* emu)
{
    emu->cpu.reset_fz();
    emu->cpu.reset_fn();
    u16 v1 = emu->cpu.sp;
    i16 v2 = (i16)((i8)read_d8(emu));
    emu->tick(1);
    u16 r = v1 + v2;
    u16 check = v1 ^ v2 ^ r;
    if (check & 0x10)
        emu->cpu.set_fh();
    else
        emu->cpu.reset_fh();
    if (check & 0x100)
        emu->cpu.set_fc();
    else
        emu->cpu.reset_fc();
}

void xf9_ld_sp_hl(Emulator* emu)
{
    emu->cpu.sp = emu->cpu.hl();
    emu->tick(2);
}

instruction_func_t* instructions_map[256] = {
    x00_nop, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};