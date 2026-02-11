/**
 * @file: sys_info.c
 * @brief: Source file for sys_info module
 */

/*
 * project: 01PROJTEMP
 * module: sys_info
 * created: 2026-02-09
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Rushabh Jain
 */

#include "sys_info.h"

void
get_platform_info ()
{
#if defined(_WIN32) || defined(_WIN64)
	OSVERSIONINFOEX osvi;
	ZeroMemory (&osvi, sizeof (OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFOEX);

	if (GetVersionEx ((OSVERSIONINFO *)&osvi))
		{
			printf ("Platform: Windows\n");
			printf ("Version: %lu.%lu\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
			printf ("Build: %lu\n", osvi.dwBuildNumber);
		}

	SYSTEM_INFO si;
	GetSystemInfo (&si);
	printf ("Architecture: ");
	switch (si.wProcessorArchitecture)
		{
		case PROCESSOR_ARCHITECTURE_AMD64:
			printf ("x64\n");
			break;
		case PROCESSOR_ARCHITECTURE_INTEL:
			printf ("x86\n");
			break;
		case PROCESSOR_ARCHITECTURE_ARM:
			printf ("ARM\n");
			break;
		case PROCESSOR_ARCHITECTURE_ARM64:
			printf ("ARM64\n");
			break;
		default:
			printf ("Unknown\n");
		}
#else
	struct utsname buffer;

	if (uname (&buffer) == 0)
		{
			printf ("Platform: %s\n", buffer.sysname);
			printf ("Node: %s\n", buffer.nodename);
			printf ("Release: %s\n", buffer.release);
			printf ("Version: %s\n", buffer.version);
			printf ("Architecture: %s\n", buffer.machine);
		}
	else
		{
			printf ("uname() failed\n");
		}
#endif
}