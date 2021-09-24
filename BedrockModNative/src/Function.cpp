#include "Function.h"
#include <Windows.h>
#include "bedrock.h"

namespace Function
{
	DedicatedServer_Start _DedicatedServer_Start;
	Minecraft_Init _Minecraft_Init;
	Minecraft_Update _Minecraft_Update;

	void Initialize()
	{
		baseAddress = (uintptr_t)GetModuleHandle(0);
		_DedicatedServer_Start = reinterpret_cast<DedicatedServer_Start>(baseAddress + 0x710f30);
		_Minecraft_Init = reinterpret_cast<Minecraft_Init>(baseAddress + 0x13af3f0);
		_Minecraft_Update = reinterpret_cast<Minecraft_Update>(baseAddress + 0x013af490);
	}
};
