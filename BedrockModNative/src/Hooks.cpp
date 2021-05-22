#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "Function.h"
#include "BedrockMod.h"

void hkDedicatedServerStart(void* instance)
{
	g_BedrockMod->javaEnv = std::make_unique<JavaEnv>(".;loader.jar");
	g_BedrockMod->javaEnv->FireEvent("DedicatedServer::Start");
	Function::_DedicatedServer_Start(instance);
}

void hkMinecraftInit(void* instance)
{
	JavaArrayList args(g_BedrockMod->javaEnv->GetEnv());
	args.Add(g_BedrockMod->javaEnv->CreatePointer(instance));
	g_BedrockMod->javaEnv->FireEvent("Minecraft::Init", args);
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
