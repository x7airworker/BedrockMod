#include "util.h"
#include "mem.h"

namespace Utils 
{
	void Utils::DebugF(std::string x)
	{
		std::cout << "[DEBUG]" << x << std::endl;
	}

	uintptr_t PreInit(const char* pattern, int pad)
	{
		uintptr_t ptr = Mem::FindSig(pattern);
		if (ptr == 0) {
			Utils::DebugF("FATAL: Sig failure for update");
		}
		ptr += pad;

		return ptr;
	}
}