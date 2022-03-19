#include "pch.h"
#include "InputProcess.h"
#include "PcMouse.h"
#include <iostream>

static CInputProcessControlFreeCamera freeCam;
void CInputProcessCameraLookAround::Update(DirectInputState* keyState, int unk)
{
	if (!CPCMouseLook::m_bEnableFreeCamera)
		((void(__thiscall*)(CInputProcess*, DirectInputState*, int))_addr(0x1CC4900))(this, keyState, unk);
	else
	{
		if (mouseLookCam)
		{
			freeCam.cam = mouseLookCam;
			freeCam.Update(keyState, unk);
		}

	}

}


void CInputProcessControlFreeCamera::Update(DirectInputState* keyState, int unk)
{
	((void(__thiscall*)(CInputProcess*, DirectInputState*, int))_addr(0x1CC03B0))(this, keyState, unk);
}
