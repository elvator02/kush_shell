//implementing builtin by simply using if else satements
int kush_builtin(char **args) {

   if (args[1] == NULL) {
    fprintf(stderr, "kush: expected argument to \"execute\"\n");
    return 1;
  }  

  if (strcmp(args[1], "echo") == 0) {
    
    printf("Custom echo function\n");
    return 1;
  } 
  else if (strcmp(args[1], "cd") == 0) {
    
    printf("Custom cd function\n");
    return 1;
  } 
  else if (strcmp(args[1], "help") == 0) {
    
    printf("Custom help function\n");
    return 1;
  } 
  

  return 1; 
}