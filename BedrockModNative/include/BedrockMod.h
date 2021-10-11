#pragma once

#include <memory>

class BedrockMod
{
private:
	unsigned long threadID;
public:
	void Init();
};

extern BedrockMod* g_BedrockMod;