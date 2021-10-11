#include "BedrockMod.h"

#include "Hooks.h"

BedrockMod* g_BedrockMod;

void BedrockMod::Init()
{
	Hooks::Install();
}