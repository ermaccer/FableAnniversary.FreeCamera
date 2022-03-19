#include "pch.h"
#include "PcMouse.h"
#include <Windows.h>
#include <iostream>
#include "eSettingsManager.h"

CCamera* mouseLookCam = nullptr;

bool CPCMouseLook::m_bEnableFreeCamera = false;
bool CPCMouseLook::m_bDisableHUD = false;

void CPCMouseLook::Update()
{	
	CCamera* cam = (CCamera*)(*(int*)(this + 80) + 4);
	mouseLookCam = cam;

	if (!m_bEnableFreeCamera)
		((void(__thiscall*)(CPCMouseLook*))0x1B8C140)(this);

	if (GetAsyncKeyState(eSettingsManager::keyToggleFreeCam) & 1)
		m_bEnableFreeCamera ^= 1;
}