#include "BedrockMod.h"

#include "Hooks.h"
#include <iostream>
#include <Windows.h>

BedrockMod* g_BedrockMod;

void BedrockMod::Init()
{
	Hooks::Install();
}