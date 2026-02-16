/**
 * @file: invocation.c
 * @brief: Source file for invocation modile
 */

/*
 * project: 01PROJTEMP
 * module: sys_info
 * created: 2026-02-15
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Rushabh Jain
 */

#include "invocation.h"

 invocation_t* initInvocation(int argc, char *argv[])
 {
    invocation_t *localInvocation = (invocation_t*)malloc(sizeof(invocation_t));

    if(localInvocation != NULL)
    {
        //Store argc
        localInvocation->argc = argc;

        //Deep copy argv
        localInvocation->argv = (char**)malloc((argc+1)* sizeof(char*));
    }
    else{
        // Log the error 
        return NULL;
    }
 }