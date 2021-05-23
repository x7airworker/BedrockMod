#pragma once

namespace Function
{
	typedef void(__thiscall* DedicatedServer_Start)(void*,void*);
	extern DedicatedServer_Start _DedicatedServer_Start;

	typedef void(__thiscall* Minecraft_Init)(void*);
	extern Minecraft_Init _Minecraft_Init;

	void Initialize();
};