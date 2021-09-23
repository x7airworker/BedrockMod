#pragma once

#include <memory>
#include <Windows.h>

class BedrockMod
{
private:
	DWORD threadID;
public:
	void Init();
};

extern BedrockMod* g_BedrockMod;