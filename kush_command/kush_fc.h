

int kush_launch(char **args);
int kush_execute(char** args);
char **kush_split_line(char *line);
int kush_fc(char** args) {
if(args[1] != NULL ){
    if(strcmp(args[1],"l") == 0){
        struct Node* ptr = head;
        int i = 1;
        while (ptr != NULL){
        printf("%d. %s\n",i++,ptr->str);
        ptr = ptr->next;
  }
  return 1;
    }}else{
    if (head == NULL) {
        fprintf(stderr, "kush: history is empty\n");
        return 1;
    }

    char* file_path = "/tmp/hist.txt";
    
       char* editor = "nano";  // since we are using path name for text editor
    

    struct Node* ptr = head;
    struct Node* prev_prev = NULL;

    while (ptr->next != NULL) {
        prev_prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        fprintf(stderr, "kush: history is empty\n");
        return 1;
    }

    if (prev_prev == NULL) {
        fprintf(stderr, "kush: no previous command in history\n");
        return 1;
    }

    FILE* file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "kush: unable to open file: %s\n", file_path);
        return 1;
    }
    
    fprintf(file, "%s\n", prev_prev->str);
    fclose(file);

    pid_t pid = fork();
    if (pid == 0) {
        execlp(editor, editor, file_path, NULL);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("kush");
    }

    file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "kush: unable to open file: %s\n", file_path);
        return 1;
    }

    char line[1024] ;

    while (fgets(line, sizeof(line), file) != NULL) {
         int len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';  
            }
        char** args = kush_split_line(line);
        int status = kush_execute(args);
    }

    fclose(file);
    }
    return 1;
}
