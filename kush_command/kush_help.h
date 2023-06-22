
int kush_cd(char **args);
int kush_help(char **args);
int kush_exit(char **args);
int kush_color(char **args);
int kush_display_hist(char **args);
int kush_echo(char **args);
int kush_alias(char **args);
int kush_unalias(char **args);
int kush_type(char **args);
int kush_builtin(char **args);

char* builtin_str[] = {
   "cd",
   "help",
   "exit",
   "color",
   "history",
   "echo",
   "alias",
   "unalias",
   "type",
   "builtin",

};

int(*builtin_func[]) (char**) = {
    &kush_cd,
    &kush_help,
    &kush_exit,
    &kush_color,
    &kush_display_hist,
    &kush_echo,
    &kush_alias,
    &kush_unalias,
    &kush_type,
    &kush_builtin
};

int kush_total_builtins(){
    return sizeof(builtin_str)/ sizeof(char*);
}


int kush_help(char **args)
{
  int i;
  printf("Hey, hope yo doin good\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n\n");

  for (i = 0; i < kush_total_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("\nUse the man command for information on other programs.\n\n");
  printf("for colors, use the command 'color [name of color]'\n");
  printf("eg- color red -> sets color to red.\n");
  printf("provided colors are blue red yellow cyan green and to reset use 'color reset'.\n\n");
  printf("for alias, use the command 'alias yourcommand value'\n");
  printf("eg - alias listt ls -> now when you type listt in shell it will work same as ls.\n");
  printf("to see all you aliases creatd, use the command 'alias'\n\n");
  printf("for unalias, use the command 'unalias yourcommand'\n\n");
  printf("for type, use the command 'type command_name'\n\n");
  printf("for history use the command 'history'\n\n");
  printf("for echo, use the command 'echo write_anything...'\n\n");
  printf("for custom builtin, use the command 'builtin command'\n");
  printf("write your custom command in kush_builtin.h\n\n");
  return 1;
}
