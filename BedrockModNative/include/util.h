#pragma once
#include <cstdint>

extern uintptr_t baseAddress;

#define THISFUNC(ret, name, addr) inline ret name () { \
static auto func = reinterpret_cast<ret(__thiscall  *)(void*)>(baseAddress + addr); \
return func(this); \
}