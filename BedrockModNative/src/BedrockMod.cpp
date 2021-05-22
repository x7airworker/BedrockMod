#include "BedrockMod.h"

#include "Function.h"
#include "Hooks.h"
#include <iostream>
#include <Windows.h>

BedrockMod* g_BedrockMod;

DWORD Thread(LPVOID param)
{
	g_BedrockMod->javaEnv = std::make_unique<JavaEnv>(".;loader.jar");
	Function::Initialize();
	Hooks::Install();
	return 0;
}

void BedrockMod::Init()
{
	CreateThread(0, 0, Thread, 0, 0, &threadID);
}