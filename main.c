/* 
 * File:   main.c
 * Author: fascio
 *
 * Created on 20 de octubre de 2015, 16:05
 */

#include <stdio.h>
#include <stdlib.h>
#include "Shell.h"

/*
 * 
 */
int suma(int argc, char * argv[]);
int resta(int argc, char * argv[]);

int suma(int argc, char * argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("La suma de %d y %d es %d\n", a , b, a + b);
}
int resta(int argc, char * argv[]){
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("La resta de %d y %d es %d\n", a , b, a - b);
}
SHELL_COMMAND my_Commands[] = { 
                                {"suma",suma},
                                {"resta",resta},
                                {NULL,NULL}
                              };
void Shell_Console(char * bufferConsole){
    printf(bufferConsole);
}
int main(int argc, char** argv) {

    //Shell(my_Commands);
    Shell_Setup(my_Commands);
    
    while(1){
        
        Shell_Task();
    }
    return (EXIT_SUCCESS);
}

