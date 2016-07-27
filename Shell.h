/* 
 * File:   Shell.h
 * Author: fascio
 *
 * Created on 20 de octubre de 2015, 16:13
 */

#ifndef __SHELL_H__
#define	__SHELL_H__

//******************************************************************************
// Includes
//******************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//******************************************************************************
// Error Define
//******************************************************************************
#define TRUE                                        (1)
#define FALSE                                       (0)

#define SHELL_EXIT_SUCCESS                          (0)


//******************************************************************************
// Struct data types
//******************************************************************************
typedef int (*SHELL_FUNC)(int argc, char * argv[]);

typedef struct shell_command_struct {    
    char * command;
    SHELL_FUNC Shell_Function;
} SHELL_COMMAND, * SHELL_COMMAND_PTR;


//******************************************************************************
// API Function Prototypes
//******************************************************************************
int Shell_Setup(SHELL_COMMAND_PTR shell_CommandsControl);
int Shell_Task(void);

int Shell(SHELL_COMMAND_PTR shell_CommandsControl);

extern int Shell_parse_command_line(char * command_line_ptr, char * argv []);

#endif	/* __SHELL_H__ */

