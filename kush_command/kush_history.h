
//Node implementation for history
struct Node{
  struct Node* next ;
  char* str ;
};
struct Node* head = NULL;
struct Node* curr = NULL;



void kush_add_hist(char **args) {
  // Check if the command is empty
  if (args[0] == NULL) {
    return;
  }

  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  if (ptr == NULL) {
    fprintf(stderr, "kush: memory allocation error\n");
    return;
  }

  int command_length = 0;
  int i = 0;
  while (args[i] != NULL) {
    command_length += strlen(args[i]);
    i++;
  }

  ptr->str = (char*)malloc((command_length + i) * sizeof(char));
  if (ptr->str == NULL) {
    fprintf(stderr, "kush: memory allocation error\n");
    free(ptr);
    return;
  }

  strcpy(ptr->str, args[0]);
  for (int j = 1; j < i; j++) {
    strcat(ptr->str, " ");
    strcat(ptr->str, args[j]);
  }

  
  ptr->next = NULL;
  if (head == NULL) {
    head = ptr;
  } else {
    curr->next = ptr;
  }
  curr = ptr;
}


int kush_display_hist(char **args){
  struct Node* ptr = head;
  int i = 1;
  while (ptr != NULL){
    printf("%d. %s\n",i++,ptr->str);
    ptr = ptr->next;
  }
  return 1;
}