#pragma once
#include <cstdint>
#include <string>
#include <iostream>

namespace Utils {
	void DebugF(std::string x);

	uintptr_t PreInit(const char* pattern, int pad);
};