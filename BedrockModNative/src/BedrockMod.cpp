#include "BedrockMod.h"

#include "Function.h"
#include "Hooks.h"
#include <iostream>
#include <Windows.h>

BedrockMod* g_BedrockMod;

void BedrockMod::Init()
{
	Function::Initialize();
	Hooks::Install();
}

DWORD Thread(LPVOID param)
{
	g_BedrockMod->javaEnv = std::make_unique<JavaEnv>(".;loader.jar");
	return 0;
}

void BedrockMod::OnReady()
{
	CreateThread(0, 0, Thread, 0, 0, &threadID);
}
