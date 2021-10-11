#pragma once

#ifdef __linux__
#include <subhook.h>
#elif _WIN32
#include <Windows.h>
#include <Detours.h>
#endif

namespace Hooks
{
	void Install();

	class Hook
	{
	private:
		void* func;
		void* hookFunc;
#ifdef __linux__
		subhook::Hook hook;
#endif

	public:
		Hook() {}
		Hook(void* func, void* hookFunc) : func(func), hookFunc(hookFunc) {}

		void install();
	};
};