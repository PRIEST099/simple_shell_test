#include "main.h"

/**
 * execute_command - Executes the command with the full path
 * @argv: The array of command arguments
 * @en: The array of environment variables
 * @fullpath: The full path to the executable
 *
 * This function forks a child process and uses execve to execute
 * the command specified by @fullpath with the given arguments and
 * environment variables. It waits for the child process to finish
 * execution before returning.
 */
void execute_command(char **argv, char **en, char *fullpath)
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        if (execve(fullpath, argv, en) == -1)
        {
            perror("./shell");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}
