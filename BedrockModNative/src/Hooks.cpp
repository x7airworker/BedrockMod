#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "BedrockMod.h"
#include "bedrock.h"

void hkMinecraftInit(Minecraft* instance)
{
	instance->init();
}

void hkMinecraftUpdate(Minecraft* instance)
{
	instance->update();
	std::cout << "Seed: " << instance->getLevel()->getSeed() << std::endl;
}

void Hooks::Install()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(LPVOID&)Minecraft::holder_init, &hkMinecraftInit);
	DetourAttach(&(LPVOID&)Minecraft::holder_update, &hkMinecraftUpdate);
	DetourTransactionCommit();
}
