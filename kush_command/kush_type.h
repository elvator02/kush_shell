
int kush_total_builtins();



int kush_type(char **args) {
    
  if (args[1] == NULL) {
    fprintf(stderr, "kush: expected argument to \"type\"\n");
    return 1;
  }

  const char *cmd = args[1];
  
  for (int i = 0; i < kush_total_builtins(); i++) {
    if (strcmp(cmd, builtin_str[i]) == 0) {
    printf("%s is a built-in command.\n", builtin_str[i]);
    return 1;
    }
  }
    
  printf("%s is an external program or command.\n", cmd);
  

  return 1;
}