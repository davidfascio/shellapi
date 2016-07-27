
#include "Shell.h"
#include "sh_context.h"

//******************************************************************************
// Local Variables 
//******************************************************************************
SHELL_CONTEXT shell_ContextControl;
//******************************************************************************
// API Function 
//******************************************************************************
int Shell_Setup(SHELL_COMMAND_PTR shell_CommandsControl){
    
    printf("\nShell (build: %s )\n", __DATE__ );
    printf("Copyright (c) 2015 Eneri S.A de C.V.\n");       
    
    // MEMALLOC PROCESS
    
    shell_ContextControl.command_list_ptr = shell_CommandsControl;
    
    // POINT TO STDIO
    
    shell_ContextControl.command_fp = stdin;
    
    if (shell_ContextControl.cmd_line){
        
        printf("shell> %s\n", shell_ContextControl.cmd_line);
    } else {
        
        printf("shell> ");
    }       
   
    return 0;
}

int Shell_Task(void){
    
    int shell_index;
    int return_code;
    
    
    if (!shell_ContextControl.exit) {
      
      if ((!shell_ContextControl.exit) && (shell_ContextControl.cmd_line[0] != '\0'))  {
          
          if (shell_ContextControl.command_fp != stdin)  {
              
              printf("%s\n", shell_ContextControl.cmd_line);
          }
          
          if (shell_ContextControl.cmd_line[0] != '#') {        
        
            if (strcmp(shell_ContextControl.cmd_line, "!") == 0)  {
                
               strncpy(shell_ContextControl.cmd_line, shell_ContextControl.history, sizeof(shell_ContextControl.cmd_line));
            } else if (strcmp(shell_ContextControl.cmd_line, "\340H") == 0)  {
                
               strncpy(shell_ContextControl.cmd_line, shell_ContextControl.history, sizeof(shell_ContextControl.cmd_line));
            } else  {
                
               strncpy(shell_ContextControl.history, shell_ContextControl.cmd_line, sizeof(shell_ContextControl.history));
            }
            
            shell_ContextControl.argc = Shell_parse_command_line(shell_ContextControl.cmd_line, shell_ContextControl.argv);            
         
            if (shell_ContextControl.argc > 0) { 
                
                strlwr(shell_ContextControl.argv[0]);
                
                for (shell_index = 0; shell_ContextControl.command_list_ptr[shell_index].command != NULL; shell_index++){
                    
                    if(strcmp(shell_ContextControl.argv[0], shell_ContextControl.command_list_ptr[shell_index].command) == 0){
                        
                        return_code = shell_ContextControl.command_list_ptr[shell_index].Shell_Function(shell_ContextControl.argc, shell_ContextControl.argv);
                        break;
                    }
                }
                
                if (shell_ContextControl.command_list_ptr[shell_index].command == NULL)  {
                    
                    printf("Invalid command.  Type 'help' for a list of commands.\n");
               } 
            }
         }
      }
      
      if (!shell_ContextControl.exit){
          printf("shell> ");
          fflush(stdout);
          
          do{
              if (!fgets(shell_ContextControl.cmd_line, sizeof(shell_ContextControl.cmd_line), shell_ContextControl.command_fp)){
                  
                  if (shell_ContextControl.command_fp != stdin)  {
                    fclose(shell_ContextControl.command_fp);
                    shell_ContextControl.command_fp = stdin;
                    shell_ContextControl.history[0] = 0;
                    shell_ContextControl.cmd_line[0] = 0;                    
                    printf("\n");
                    
                  } else  {
                      
                      shell_ContextControl.exit = TRUE;
                  
                  break;
               }
                  
              }
              
          } while((shell_ContextControl.cmd_line[0] == '\0') && (shell_ContextControl.command_fp != stdin));
      }
    } else{
    
        printf("Terminating shell.\n");
    }
    return SHELL_EXIT_SUCCESS;
}

int Shell(SHELL_COMMAND_PTR shell_CommandsControl){
    
    int shell_index;
    int return_code;
    
    printf("\nShell (build: %s )\n", __DATE__ );
    printf("Copyright (c) 2015 Eneri S.A de C.V.\n");       
    
    // MEMALLOC PROCESS
    
    shell_ContextControl.command_list_ptr = shell_CommandsControl;
    
    // POINT TO STDIO
    
    shell_ContextControl.command_fp = stdin;
    
    if (shell_ContextControl.cmd_line){
        
        printf("shell> %s\n", shell_ContextControl.cmd_line);
    } else {
        
        printf("shell> ");
    }   
    
    while (!shell_ContextControl.exit) {
      
      if ((!shell_ContextControl.exit) && (shell_ContextControl.cmd_line[0] != '\0'))  {
          
          if (shell_ContextControl.command_fp != stdin)  {
              
              printf("%s\n", shell_ContextControl.cmd_line);
          }
          
          if (shell_ContextControl.cmd_line[0] != '#') {        
        
            if (strcmp(shell_ContextControl.cmd_line, "!") == 0)  {
                
               strncpy(shell_ContextControl.cmd_line, shell_ContextControl.history, sizeof(shell_ContextControl.cmd_line));
            } else if (strcmp(shell_ContextControl.cmd_line, "\340H") == 0)  {
                
               strncpy(shell_ContextControl.cmd_line, shell_ContextControl.history, sizeof(shell_ContextControl.cmd_line));
            } else  {
                
               strncpy(shell_ContextControl.history, shell_ContextControl.cmd_line, sizeof(shell_ContextControl.history));
            }
            
            shell_ContextControl.argc = Shell_parse_command_line(shell_ContextControl.cmd_line, shell_ContextControl.argv);            
         
            if (shell_ContextControl.argc > 0) { 
                
                strlwr(shell_ContextControl.argv[0]);
                
                for (shell_index = 0; shell_ContextControl.command_list_ptr[shell_index].command != NULL; shell_index++){
                    
                    if(strcmp(shell_ContextControl.argv[0], shell_ContextControl.command_list_ptr[shell_index].command) == 0){
                        
                        return_code = shell_ContextControl.command_list_ptr[shell_index].Shell_Function(shell_ContextControl.argc, shell_ContextControl.argv);
                        break;
                    }
                }
                
                if (shell_ContextControl.command_list_ptr[shell_index].command == NULL)  {
                    
                    printf("Invalid command.  Type 'help' for a list of commands.\n");
               } 
            }
         }
      }
      
      if (!shell_ContextControl.exit){
          printf("shell> ");
          fflush(stdout);
          
          do{
              if (!fgets(shell_ContextControl.cmd_line, sizeof(shell_ContextControl.cmd_line), shell_ContextControl.command_fp)){
                  
                  if (shell_ContextControl.command_fp != stdin)  {
                    fclose(shell_ContextControl.command_fp);
                    shell_ContextControl.command_fp = stdin;
                    shell_ContextControl.history[0] = 0;
                    shell_ContextControl.cmd_line[0] = 0;                    
                    printf("\n");
                    
                  } else  {
                      
                      shell_ContextControl.exit = TRUE;
                  
                  break;
               }
                  
              }
              
          } while((shell_ContextControl.cmd_line[0] == '\0') && (shell_ContextControl.command_fp != stdin));
      }
    }

    
    printf("Terminating shell.\n");
    
    return SHELL_EXIT_SUCCESS;
}