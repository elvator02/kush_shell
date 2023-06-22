#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"kush_command/kush_color_emoji.h"
#include"kush_command/kush_echo.h"
#include"kush_command/kush_help.h"
#include"kush_command/kush_cd.h"
#include"kush_command/kush_history.h"
#include"kush_command/kush_alias_unalias.h"
#include"kush_command/kush_exit.h"
#include"kush_command/kush_type.h"
#include"kush_command/kush_builtin.h"


int kush_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("kush");
    }// excecvp takes list of arguments considering the path variables
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("kush");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}


int kush_execute(char** args) {
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }
  // Checking if alias exist and the recursively calling the execute
  char** aliased_args = kush_find_alias(args);
  if (aliased_args != args) {
    return kush_execute(aliased_args);
  }

  for (i = 0; i < kush_total_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return kush_launch(args);
}



const int slBuffsize = 64;
char **kush_split_line(char *line)
{
    int buffsize = slBuffsize;
    int pos = 0;
    char** tokens = malloc(sizeof(char*)*buffsize);
    char* token;

    if (!tokens) {
    fprintf(stderr, "kush: allocation error\nPlease try again...\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, " ");
  while(token != NULL){
    tokens[pos] = token;
    pos++;

    if(pos >= buffsize){
     buffsize += slBuffsize;
      tokens = realloc(tokens, sizeof(char*)*buffsize);
      if (!tokens) {
        fprintf(stderr, "kush: allocation error\nPlease try again...\n");
        exit(EXIT_FAILURE);

    }
  }

  token = strtok(NULL, " ");

}
tokens[pos]= NULL;
return tokens;
}


const int rlBuffsize = 1024;
char* kush_read_line(void)
{   
    int buffsize = rlBuffsize;
    int pos = 0;
    char *buffer = malloc(sizeof(char)*buffsize);  
    int chr;

    if (!buffer) {
    fprintf(stderr, "kush: allocation error\nPlease try again...\n");
    exit(EXIT_FAILURE);
  }

    while(1){
       chr = getchar();//getting the input char by char
   
       if(chr == '\n'){
        buffer[pos] = '\0';//giving null char at end
        return buffer;
       }
        else {
            buffer[pos]= chr;
        }
       pos++;
       
       //reallocation of buffer size if the input is too long
       if(pos >= buffsize){
        buffsize += rlBuffsize;
        buffer = realloc(buffer, buffsize);
        if (!buffer) {
        fprintf(stderr, "kush: allocation error\nPlease try again...\n");
        exit(EXIT_FAILURE);
       }
    }
  }
}




void kushloop(void){
char*line;
char **args;
int status;

do{
    printf(">>");
    line = kush_read_line();
    args = kush_split_line(line);// makes the line into arra of strings
    kush_add_hist(args);
    status = kush_execute(args);// returns 0 or 1 for the loop to continue

    free(line);
    free(args);
}while(status);
 
}


int main(int argc, char **argv){
   
   kushloop();

   return 0;


}
