#include "main.h"

void execute_command(char **argv, char **en, char *fullpath)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execve(fullpath, argv, en);
        perror("./shell");
        exit(1);
    }
    else
    {
        wait(NULL);
    }
}

