/**
 * @file paths
 * @brief Implementation of path module
 */

/*
 * project: C-Template
 * module: paths
 * created: 2026-04-11
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: rushabh
 */

#ifndef PATHS_H
#define PATHS_H

#include <stddef.h>

int getConfigPath (char *path, size_t maxLength);
int getCachePath (char *path, size_t maxLength);
int getInstallPath (char *path, size_t maxLength);
int getHomePath (char *path, size_t maxLength);
int getCWD (char *path, size_t maxLength);
int changeDir (char *path);

#endif //PATHS_H