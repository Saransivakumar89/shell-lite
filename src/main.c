#include "shell-lite.h"

#define SIZE 1024
#define MAX_ARGS 64

int main(void)
{
    char buff[SIZE];

    printf("[+] Entered shell-lite\n");

    while (1)
    {
        printf("shell-lite>> ");
        fflush(stdout);

        if (fgets(buff, sizeof(buff), stdin) == NULL)
            break;

        buff[strcspn(buff, "\n")] = '\0';

        if (buff[0] == '\0')
            continue;

        if (strcmp(buff, "exit") == 0)
        {
            printf("[+] Exiting shell-lite\n");
            break;
        }

        char *args[MAX_ARGS];
        int i = 0;

        char *token = strtok(buff, " ");

        while (token != NULL && i < MAX_ARGS - 1)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        // built-in cd
        if (strcmp(args[0], "cd") == 0)
        {
            if (args[1] == NULL)
            {
                fprintf(stderr, "cd: missing argument\n");
            }
            else if (chdir(args[1]) != 0)
            {
                perror("cd");
            }

            continue;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            execvp(args[0], args);

            perror("execvp");
            exit(EXIT_FAILURE);
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}
