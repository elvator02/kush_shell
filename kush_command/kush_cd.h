
int kush_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "kush: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("kush");
    }
  }
  return 1;
}
