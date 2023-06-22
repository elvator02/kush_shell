//define colours
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

//define emojis by their unicodes
#define GRIN_SMILE_FACE "\xF0\x9F\x98\x81" //will work in shells which have property to show emojis(use vscode editor)
#define RED_HEART "\033[31m\u2764\033[0m\n"

int kush_color(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "kush: expected argument to \"color\"\n");
  } else {
    if (strcmp(args[1], "red") == 0) {
      printf("%s", COLOR_RED);
      printf("color set to red\n");
    }
    if (strcmp(args[1], "green") == 0) {
      printf("%s", COLOR_GREEN);
      printf("color set to green\n");
    }
    if (strcmp(args[1], "cyan") == 0) {
      printf("%s", COLOR_CYAN);
      printf("color set to cyan\n");
    }
    if (strcmp(args[1], "yellow") == 0) {
      printf("%s", COLOR_YELLOW);
      printf("color set to yellow\n");
    }
    if (strcmp(args[1], "blue") == 0) {
      printf("%s", COLOR_BLUE);
      printf("color set to blue\n");
    }
    if (strcmp(args[1], "reset") == 0) {
      printf("%s", COLOR_RESET);
      printf("color has been set to default\n");
    }
    if (strcmp(args[1], "heart") == 0) {
      printf("%s", RED_HEART);
    }
  }
  return 1;
}
