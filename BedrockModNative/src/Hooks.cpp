#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "Function.h"
#include "BedrockMod.h"


typedef bool(__thiscall* DedicatedServer_isEduMode)(void*);

void __fastcall hkDedicatedServerStart(void* self, void* param1)
{
	DedicatedServer_isEduMode func = reinterpret_cast<DedicatedServer_isEduMode>(GetModuleHandle(0) + 0x00714410);
	/*
	DCCallVM* vm = dcNewCallVM(4096);
	dcMode(vm, DC_CALL_C_X64_WIN64);
	dcReset(vm);
	dcArgPointer(vm, (DCpointer)instance);
	std::cout << "DCCall result: " << dcCallBool(vm, GetModuleHandle(0) + 0x00714410) << std::endl;
	dcFree(vm);*/
	std::cout << "IsEduMode: " << func(self) << std::endl;

	g_BedrockMod->javaEnv = std::make_unique<JavaEnv>(".;loader.jar");
	g_BedrockMod->javaEnv->FireEvent("DedicatedServer::Start");
	Function::_DedicatedServer_Start(self, param1);
}

void hkMinecraftInit(void* instance)
{
	DCCallVM* vm = dcNewCallVM(4096);
	dcMode(vm, DC_CALL_C_X64_WIN64);
	dcReset(vm);
	dcArgPointer(vm, (DCpointer) instance);
	std::cout << "DCCall result: " << dcCallPointer(vm, GetModuleHandle(0) + 0x013b0cd0) << std::endl;
	dcFree(vm);


	//JavaArrayList args(g_BedrockMod->javaEnv->GetEnv());
	//args.Add(g_BedrockMod->javaEnv->CreatePointer(instance));
	//g_BedrockMod->javaEnv->FireEvent("Minecraft::Init", args);

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
