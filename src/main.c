#include "shell-lite.h"

char buff[SIZE];

int main(int argc, char **argv){

    if(argc != 1){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }



    while(1){
        printf("shell-lite>> ");

        if(fgets(buff, sizeof(buff), stdin) == NULL){
            break; //EOF
        }

        // Removes the newline
        buff[strcspn(buff, "\n")] = '\0';

        printf("You entered: %s\n", buff);
    }

    return 0;
}
