#include "Function.h"
#include <Windows.h>
#include "Helper.h"

namespace Function
{
	DedicatedServer_Start _DedicatedServer_Start;
	Minecraft_Init _Minecraft_Init;

	void Initialize()
	{
		baseAddress = (uintptr_t)GetModuleHandle(0);
		_DedicatedServer_Start = reinterpret_cast<DedicatedServer_Start>(baseAddress + 0x710f30);
		_Minecraft_Init = reinterpret_cast<Minecraft_Init>(baseAddress + 0x13af3f0);
	}
};
