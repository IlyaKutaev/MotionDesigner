#include <stdafx.h>
#include "FreeMemory.h"
#define NOMINMAX
#include <windows.h>

std::string FreeMemory::LockMemory()
{
	std::string versiontxt = "MotionDesigner ";
	int blockcount = 0;
	auto size = GetMemorySize();

	if (size > AppVersion::pad_ultimate)
	{
		app_version = pad_ultimate;
		blockcount = 75;
		versiontxt.append("Ultimate");
	}
	else if (size > AppVersion::pad_professional)
	{
		app_version = pad_professional;
		blockcount = 125;
		versiontxt.append("Professional");
	}
	else if (size > AppVersion::pad_extended)
	{
		app_version = pad_extended;
		blockcount = 187;
		versiontxt.append("Extended");
	}
	else if (size > AppVersion::pad_home)
	{
		app_version = pad_home;
		blockcount = 260;
		versiontxt.append("Home");
	}
	else
	{
		app_version = pad_lite;
		blockcount = 200;
		versiontxt.append("Lite");
	}

	int block = 16 * 1024 * 1024;

	for (int i = 0; i < blockcount; i++)
	{
		intdata b;
		b.data = new char[block];
		idata << b;
	}

	return versiontxt;
}

size_t FreeMemory::GetMemorySize()
{
	size_t mem = 0;

	size_t lim = 1024 * 1024;
	lim *= 1024;

	typedef BOOL(WINAPI *PGMSE)(LPMEMORYSTATUSEX);
	PGMSE pGMSE = (PGMSE)GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), ("GlobalMemoryStatusEx"));
	if (pGMSE != 0)
	{
		MEMORYSTATUSEX mi;
		memset(&mi, 0, sizeof(MEMORYSTATUSEX));
		mi.dwLength = sizeof(MEMORYSTATUSEX);
		if (pGMSE(&mi) == TRUE)
			mem = mi.ullTotalPhys / lim;
		else
			pGMSE = 0;
	}
	if (pGMSE == 0)
	{
		MEMORYSTATUS mi;
		memset(&mi, 0, sizeof(MEMORYSTATUS));
		mi.dwLength = sizeof(MEMORYSTATUS);
		GlobalMemoryStatus(&mi);
		mem = mi.dwTotalPhys / 1048576;
	}

	return mem;
}

bool FreeMemory::FreeMyMemory()
{
	if (idata.isEmpty()) return false;
	delete idata.last().data;
	idata.removeLast();

	return true;
}
