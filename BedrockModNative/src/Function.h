#pragma once

namespace Function
{
	typedef int(__thiscall* DedicatedServer_Start)(void*);
	extern DedicatedServer_Start _DedicatedServer_Start;

	typedef void(__thiscall* Minecraft_Init)(void*);
	extern Minecraft_Init _Minecraft_Init;

	typedef void(__thiscall* Minecraft_Update)(void*);
	extern Minecraft_Update _Minecraft_Update;

	void Initialize();
};