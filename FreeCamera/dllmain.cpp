// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "PcMouse.h"
#include "InputProcess.h"
#include "eSettingsManager.h"
#include <iostream>

using namespace Memory::VP;
void Init()
{
	eSettingsManager::Init();
#ifdef _DEBUG
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
#endif // _DEBUG

	InjectHook(_addr(0x1C83C48), &CPCMouseLook::Update);
	Patch(_addr(0x2EE8598), &CInputProcessCameraLookAround::Update);
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}