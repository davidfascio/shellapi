#include "Shell.h"
#include "sh_context.h"
#include <ctype.h>

int Shell_parse_command_line(char * command_line_ptr, char * argv []){
    
    
    int     parse_index;
    int     argc = 0;
    char *  sptr = command_line_ptr;
    
    for (parse_index = 0; parse_index < SHELL_CONTEXT_MAX_ARGS; parse_index++){
        
        while (*sptr && !isgraph(*sptr)) sptr++;
        
        if(!*sptr){
            argv[parse_index] = NULL;
        } else {
            
            argc++;
            argv[parse_index] = sptr;
            
            while (*sptr && isgraph(*sptr)) sptr++;
            if(*sptr) *sptr++ = '\0';
        }
            
    }
    
    return argc;
}
