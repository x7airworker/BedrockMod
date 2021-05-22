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