#pragma once
#include "util.h"
#include "Level.h"

class DedicatedServer
{
public:
	THISFUNC(bool, isEduMode,  0x00714410);
	THISFUNC(Level*, getLevel, 0x013b0cd0);
};