#include "main.h"

/*
 * this is not betty style but an explaination os what this file does
 *
 * it executes the command with the fullpath
 *
 */

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

