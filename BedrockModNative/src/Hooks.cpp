#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "Function.h"
#include "BedrockMod.h"
#include "bedrock.h"

int hkDedicatedServerStart(DedicatedServer* instance)
{
	std::cout << "IsEduMode: " << instance->isEduMode() << std::endl;
	std::cout << "0x" << std::hex << instance << std::endl;
	return Function::_DedicatedServer_Start(instance);
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
