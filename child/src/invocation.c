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


/**
 * @brief Get current directory
 * @param[in] cwd point to char to populate the buffer
 */
static void getCurrentDirectory(char* cwd);

 invocation_t* initInvocation(int argc, char *argv[])
 {
    invocation_t *localInvocation = (invocation_t*)malloc(sizeof(invocation_t));
    char localCwd[MAX_PATH_LEN];

    if(localInvocation != NULL)
    {
        //Store argc
        localInvocation->argc = argc;

        //Deep copy argv
        localInvocation->argv = (char**)malloc((argc+1)* sizeof(char*));
        if (localInvocation->argv != NULL)
        {
            for(int i = 0; i < argc; i++)
            {
                localInvocation->argv[i] = strdup(argv[i]); //Creates a new copy
                if (!localInvocation->argv[i])
                {
                    // If there is any failure to allocate to any of the given input. Free the memory
                    for (int j = 0; j < i; j++)
                    {
                        free(localInvocation->argv[i]);
                    }
                    free(localInvocation->argv);
                    free(localInvocation);
                    // Log the error
                    return NULL;
                }
            }
            localInvocation->argv[argc] = NULL; // Argument array must always have a NULL terminated
        }
        else
        {
            //TODO: Log the error
            free(localInvocation); // Free the space
            return NULL;
        }

        getCurrentDirectory(localCwd);
        localInvocation->cwd = localCwd;

        if(!localInvocation->cwd)
        {
           for (int i = 0; i < argc; i++)
           {
                free(localInvocation->argv[i]);
           }
            
           free(localInvocation->argv);
            free(localInvocation);
            // Log the error
            return NULL;
        }
        
    }
    else
    {
        //TODO: Log the error 
        return NULL;
    }
    return localInvocation;
 }


static void getCurrentDirectory(char* cwd)
 {
    char buffer[MAX_PATH_LEN];

#if defined(_WIN32) || defined(_WIN64)
    if(_getcwd(buffer, sizeof(buffer)) == NULL)
    {
        //Log the error
        cwd = NULL;
    }
#else
    if(getcwd(buffer, sizeof(buffer)) == NULL)
    {
        // Log the error
        cwd = NULL;
    }
#endif
    else{
    // Doing safe copy into the argument
    strncpy(cwd, buffer, sizeof(buffer));
    }
 }