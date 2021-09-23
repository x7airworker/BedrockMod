#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "Function.h"
#include "BedrockMod.h"


typedef bool(__thiscall* DedicatedServer_isEduMode)(void*);

int __cdecl hkDedicatedServerStart(void* self, void* param1)
{
	DedicatedServer_isEduMode func = reinterpret_cast<DedicatedServer_isEduMode>(GetModuleHandle(0) + 0x00714410);
	std::cout << "IsEduMode: " << func(self) << std::endl;
	return Function::_DedicatedServer_Start(self, param1);
}

void hkMinecraftInit(void* instance)
{
	Function::_Minecraft_Init(instance);
}

void Hooks::Install()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(LPVOID&)Function::_DedicatedServer_Start, &hkDedicatedServerStart);
	DetourAttach(&(LPVOID&)Function::_Minecraft_Init, &hkMinecraftInit);
	DetourTransactionCommit();
}
