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

void hkMinecraftInit(Minecraft* instance)
{
	Function::_Minecraft_Init(instance);
}

void hkMinecraftUpdate(Minecraft* instance)
{
	Function::_Minecraft_Update(instance);
	std::cout << "Seed: " << instance->getLevel()->getSeed() << std::endl;
}

void Hooks::Install()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(LPVOID&)Function::_DedicatedServer_Start, &hkDedicatedServerStart);
	DetourAttach(&(LPVOID&)Function::_Minecraft_Init, &hkMinecraftInit);
	DetourAttach(&(LPVOID&)Function::_Minecraft_Update, &hkMinecraftUpdate);
	DetourTransactionCommit();
}
