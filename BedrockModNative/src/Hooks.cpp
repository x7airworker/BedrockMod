#include "Hooks.h"
#include <iostream>
#include "BedrockMod.h"
#include "bedrock.h"

#ifdef __linux__
#define IMPL_TRAMPOLINE(NAME) subhook::ScopedHookRemove remove(&NAME)
#else
#define IMPL_TRAMPOLINE(NAME)
#endif

Hooks::Hook minecraftInitHook;
Hooks::Hook minecraftUpdateHook;
Hooks::Hook networkHandlerSendHook;

void __thiscall hkMinecraftInit(Minecraft* instance)
{
	std::cout << "Before remove" << std::endl;
	IMPL_TRAMPOLINE(minecraftInitHook);

	instance->init();
}

void __thiscall hkMinecraftUpdate(Minecraft* instance)
{
	IMPL_TRAMPOLINE(minecraftUpdateHook);

	instance->update();
}

void __thiscall hkNetworkHandlerSend (NetworkHandler* handler, NetworkIdentifier* i, Packet* packet, unsigned char flags)
{
	IMPL_TRAMPOLINE(networkHandlerSendHook);
	std::cout << "Sended packet: " << packet->getId() << std::endl;
	handler->send(handler, i, packet, flags);
}

void Hooks::Install()
{
	minecraftInitHook = Hook((void*) &Minecraft::holder_init,(void*) &hkMinecraftInit);
	minecraftInitHook.install();
	minecraftUpdateHook = Hook((void*)&Minecraft::holder_update, (void*)&hkMinecraftUpdate);
	minecraftUpdateHook.install();
	networkHandlerSendHook = Hook((void*)&NetworkHandler::holder_send, (void*)&hkNetworkHandlerSend);
	networkHandlerSendHook.install();
}

void Hooks::Hook::install()
{
#ifdef _WIN32
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach((PVOID*)func, (PVOID)hookFunc);
	DetourTransactionCommit();
#elif __linux__
	hook = subhook::Hook();
	hook.Install((void*)func, (void*)hookFunc);
#endif
}