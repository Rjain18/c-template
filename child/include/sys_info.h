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

#ifndef SYS_INFO_H
#define SYS_INFO_H

// Include necessary headers based on the platform
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

/**
 * @brief gets platform information
 */
void get_platform_info ();

#endif // SYS_INFO_H
