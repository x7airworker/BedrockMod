#include "mem.h"

#ifdef __linux__
#include <dlfcn.h>
#elif _WIN32
#include <Windows.h>
#endif


uintptr_t Mem::FindMLvlPtr(uintptr_t baseAddr, std::vector<unsigned int> offsets) {
	uintptr_t addr = baseAddr;
	for (int I = 0; I < offsets.size(); I++) {
		addr = *(uintptr_t*)(addr);
		if ((uintptr_t*)(addr) == nullptr)
			return addr;
		addr += offsets[I];
	}
	return addr;
}

auto Mem::getModuleBase() -> long long {
	return (long long)GetModuleHandleA(nullptr);
}

auto Mem::getModuleBaseHandle() -> void* {
	return GetModuleHandleA(nullptr);
}

auto Mem::getBaseModuleSize() -> long long {
	return (long long) GetModuleHandle(0);
}

auto Mem::getBaseModuleEnd() -> long long {
	return getModuleBase() + getBaseModuleSize();
}

void Mem::SetThisModule(void* mod) {
	thisMod = mod;
}
auto Mem::GetThisModule() -> void* {
	return thisMod;
}

auto Mem::FindSig(const char* pattern) -> uintptr_t {
	return FindSig(getModuleBase(), getBaseModuleEnd(), pattern);
}
struct SearchedSig {
	std::string pattern;
	uintptr_t result;
	SearchedSig(std::string pattern, uintptr_t result) {
		this->pattern = pattern;
		this->result = result;
	}
};

std::vector<SearchedSig> alreadySearched = std::vector<SearchedSig>();
auto Mem::FindSig(long long rangeStart, long long rangeEnd, const char* pattern) -> uintptr_t {
	for (int i = 0; i < alreadySearched.size(); i++) {
		if (alreadySearched[i].pattern == std::string(pattern)) {
			return alreadySearched[i].result;
		}
	}
	const char* pat = pattern;
	long long firstMatch = 0;
	for (long long pCur = rangeStart; pCur < rangeEnd; pCur++) {
		if (!*pat) return firstMatch;
		if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
			if (!firstMatch) firstMatch = pCur;
			if (!pat[2]) {
				alreadySearched.push_back(SearchedSig(std::string(pattern), firstMatch));
				return firstMatch;
			};
			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
			else pat += 2;
		}
		else {
			pat = pattern;
			firstMatch = 0;
		}
	}
	return 0;
}