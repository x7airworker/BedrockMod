#include "Hooks.h"
#include <windows.h>
#include <detours.h>
#include <iostream>
#include "BedrockMod.h"
#include "bedrock.h"

void hkMinecraftInit(Minecraft* instance)
{
	instance->init();
}

void hkMinecraftUpdate(Minecraft* instance)
{
	instance->update();
}

void hkNetworkHandlerSend(NetworkHandler* handler, NetworkIdentifier* i, Packet* packet, unsigned char flags)
{
	std::cout << "Sended packet: " << packet->getId() << std::endl;
	handler->send(handler, i, packet, flags);
}

void Hooks::Install()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(LPVOID&)Minecraft::holder_init, &hkMinecraftInit);
	DetourAttach(&(LPVOID&)Minecraft::holder_update, &hkMinecraftUpdate);
	DetourAttach(&(LPVOID&)NetworkHandler::holder_send, &hkNetworkHandlerSend);
	DetourTransactionCommit();
}
