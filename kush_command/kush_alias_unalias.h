
//linked list for alias command with value (usage 'alias your_command shell_command')
struct Node_alias{
  struct Node_alias* next ;
  char* cmd ;
  char** value;
};
struct Node_alias* head_alias = NULL;
struct Node_alias* curr_alias = NULL;


char** store_value(char** args) {
  int count = 0;
  while (args[count + 2] != NULL) {
    count++;
  }

  char** temp = malloc((count + 1) * sizeof(char*));
  if (temp == NULL) {
    perror("kush: allocation error");
    exit(EXIT_FAILURE);
  }

  int i;
  for (i = 0; i < count; i++) {
    temp[i] = strdup(args[i + 2]);// dynamically copying strings
    
  }
  temp[count] = NULL;

  return temp;
}

void kush_print_alias(char **args){
  struct Node_alias* ptr = head_alias;
  int i = 1;
  while (ptr != NULL) {
    printf("%d. %s", i++, ptr->cmd);

    // Print each value in the array
    int j = 0;
    while (ptr->value[j] != NULL) {
      printf(" %s", ptr->value[j]);
      j++;
    }

    printf("\n");
    ptr = ptr->next;
  }
}



int kush_alias(char **args) {
  
  if(args[1] == NULL){
    kush_print_alias(args);
    return 1;
  }
  
  
  if (args[2] == NULL) {
    fprintf(stderr, "kush: expected argument to \"alias\"\n");
    return 1;
  }

  if (head_alias == NULL) {
    head_alias = (struct Node_alias *)malloc(sizeof(struct Node_alias));
    head_alias->cmd = (char*)malloc(sizeof(char) * (strlen(args[1]) + 1));
    head_alias->cmd = strdup(args[1]);
    head_alias->value = store_value(args);
    head_alias->next = NULL;
    curr_alias = head_alias;
  } else {
    struct Node_alias *ptr = (struct Node_alias *)malloc(sizeof(struct Node_alias));
    ptr->cmd = (char*)malloc(sizeof(char) * (strlen(args[1]) + 1));
    ptr->cmd = strdup(args[1]);
    ptr->value = store_value(args);
    ptr->next = NULL;
    curr_alias->next = ptr;
    curr_alias = ptr;
  }

  return 1;
}

//finding the alias name before execution 
char** kush_find_alias(char **args){
  struct Node_alias* ptr = head_alias;
  while (ptr != NULL){
    if(strcmp(args[0], ptr->cmd) == 0){
      return ptr->value;
    }
    ptr = ptr->next;
  }
  return args;
}


// implementing unalias by
//removing the linked list for that alias 
int kush_unalias(char** args) {
  if (args[1] == NULL) {
    fprintf(stderr, "kush: expected argument to \"unalias\"\n");
    return 1;
  }

  struct Node_alias* prev = NULL;
  struct Node_alias* curr = head_alias;

  while (curr != NULL) {
    if (strcmp(args[1], curr->cmd) == 0) {
      if (prev == NULL) {
        // Removing the head node
        head_alias = curr->next;
      } else {
        prev->next = curr->next;
      }
      free(curr->cmd);
      for (int i = 0; curr->value[i] != NULL; i++) {
        free(curr->value[i]);
      }
      free(curr->value);
      free(curr);

      printf("Alias '%s' removed\n", args[1]);
      return 1;
    }

    prev = curr;
    curr = curr->next;
  }

  printf("Alias '%s' not found\n", args[1]);
  return 1;
}