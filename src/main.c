#include "shell-lite.h"

char buff[SIZE];

int main(int argc, char **argv){

    if(argc != 1){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }
    printf("[+]Entered shell-lite\n");
    while(1){
        printf("shell-lite>> ");

        if(fgets(buff, sizeof(buff), stdin) == NULL){
            break;
        }

        buff[strcspn(buff, "\n")] = '\0';

	//exit the shell-lite
        if(strcmp(buff,"exit")==0){
            printf("[+]Exiting shell-lite\n");
            break;
        }
	
	//catch the newline
        if(buff[0]=='\0'){
            continue;
        }

        // tokenizes the inputs
        char *args[10];
        int i = 0;

        char *token = strtok(buff, " ");
        while (token != NULL && i < 9) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        //creates the child process and executes the process
        pid_t pid = fork();

        if(pid < 0){
            perror("fork");
        }
        else if(pid == 0){
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
        else {
            wait(NULL);
        }
    }

    return 0;
}
