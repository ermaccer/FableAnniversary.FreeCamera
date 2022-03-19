#include "framework.h"

int GetEntryPoint()
{
	static int addr = reinterpret_cast<int>(GetModuleHandle(nullptr));
	return addr;
}

int _addr(int addr)
{
    return GetEntryPoint() - 0x400000 + addr;
}
