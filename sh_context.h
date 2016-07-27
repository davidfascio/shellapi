/* 
 * File:   sh_context.h
 * Author: fascio
 *
 * Created on 20 de octubre de 2015, 16:57
 */

#ifndef __SH_CONTEXT_H__
#define	__SH_CONTEXT_H__

//******************************************************************************
// Includes
//******************************************************************************
#include <stdio.h>
#include <stdlib.h>

#include "Shell.h"

//******************************************************************************
// Defines
//******************************************************************************

#define SHELL_CONTEXT_MAX_ARGS                          (5)
#define SHELL_CONTEXT_MAX_CMDLEN                        (20)

//******************************************************************************
// Struct data types
//******************************************************************************

typedef unsigned int boolean;

typedef struct shell_context_struct {
    
    char *          argv[SHELL_CONTEXT_MAX_ARGS];
    int             argc;
    char            cmd_line[SHELL_CONTEXT_MAX_CMDLEN];
    char            history[SHELL_CONTEXT_MAX_CMDLEN];
    SHELL_COMMAND_PTR command_list_ptr;
    FILE *          command_fp;
    boolean         exit;
    
} SHELL_CONTEXT, * SHELL_CONTEXT_PTR;

#endif	/* __SH_CONTEXT_H__ */

