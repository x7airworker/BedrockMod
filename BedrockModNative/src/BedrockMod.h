#pragma once

#include <memory>
#include <Windows.h>
#include "JavaEnv.h"

class BedrockMod
{
private:
	DWORD threadID;
public:
	std::unique_ptr<void*> minecraft;
	std::unique_ptr<JavaEnv> javaEnv;
	void Init();
};

extern BedrockMod* g_BedrockMod;