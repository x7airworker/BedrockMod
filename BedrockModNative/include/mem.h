#pragma once

#include <vector>
#include <string>

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define getBits( x )	(INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )	(getBits(x[0]) << 4 | getBits(x[1]))

#define PI 3.14159265359

class Mem {
	static inline void* thisMod;
public:
	static uintptr_t FindMLvlPtr(uintptr_t, std::vector<unsigned int>);
	static auto FindSig(const char* pattern)->uintptr_t;
	static auto FindSig(long long rangeStart, long long rangeEnd, const char* pattern)->uintptr_t;
	static auto getModuleBase() -> long long;
	static auto getModuleBaseHandle()->void*;
	static auto getBaseModuleSize() -> long long;
	static auto getBaseModuleEnd() -> long long;
	static void SetThisModule(void*);
	static auto GetThisModule()->void*;
};