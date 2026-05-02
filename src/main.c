#include "shell-lite.h"

int main(int argc, char **argv){

    if(argc != 1){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }



    while(1){
        printf("shell-lite>> ");

        if(fgets(input, sizeof(input), stdin) == NULL){
            break; //EOF
        }

        // Removes the newline
        input[strcspn(input, "\n")] = '\0';

        printf("You entered: %s\n", input);
    }

    return 0;
}
