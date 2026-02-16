/**
 * @file: invocation.h
 * @brief: Header file for invocation modile
 */

/*
 * project: 01PROJTEMP
 * module: sys_info
 * created: 2026-02-15
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Rushabh Jain
 */
#ifndef INVOCATION_H
#define INVOCATION_H

typedef struct 
{
    int argc;
    char **argv;
    char *cwd;    
} invocation_t;

/**
 * @brief initializes the Invocation
 * @param[in] argc argument count 
 * @param[in] argv argument array
 * @return pointer to invocation structure
 */
invocation_t* initInvocation(int argc, char *argv[]);  

/**
 * @brief Get current directory
 * @return current directory path
 */
char* getCurrentDirectory();

#endif // INVOCATION_H
