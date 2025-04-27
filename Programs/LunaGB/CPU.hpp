#pragma once

#include <Luna/Runtime/Base.hpp>
using namespace Luna;

struct Emulator;

struct CPU
{
    //! A register.
    u8 a;
    //! F register.
    u8 f;
    //! B register.
    u8 b;
    //! C register.
    u8 c;
    //! D register.
    u8 d;
    //! E register.
    u8 e;
    //! H register.
    u8 h;
    //! L register.
    u8 l;
    //! SP register (Stack Pointer).
    u16 sp;
    //! PC register (Program Counter/Pointer).
    u16 pc;
    //! CPU is halted;
    bool halted;

    u16 af() const { return (((u16)a) << 8) | (u16)f; }
    u16 bc() const { return (((u16)b) << 8) + (u16)c; }
    u16 de() const { return (((u16)d) << 8) + (u16)e; }
    u16 hl() const { return (((u16)h) << 8) + (u16)l; }
};