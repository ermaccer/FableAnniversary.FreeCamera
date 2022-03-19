#include "eSettingsManager.h"
#include "IniReader.h"
#include <Windows.h>

int  eSettingsManager::keyToggleFreeCam;

void eSettingsManager::Init()
{
	CIniReader reader("");
	keyToggleFreeCam = reader.ReadInteger("Keys", "keyToggleFreeCam", VK_F1);
}
