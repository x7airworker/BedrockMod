#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "Function.h"
#include "BedrockMod.h"

void hkDedicatedServerStart(void* instance)
{
	g_BedrockMod->javaEnv->FireEvent("DedicatedServer::Start");
	Function::_DedicatedServer_Start(instance);
}

void hkMinecraftInit(void* instance)
{
	g_BedrockMod->minecraft = std::make_unique<void*>(instance);
	g_BedrockMod->javaEnv->FireEvent("Minecraft::Init");
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
