#include "main.h"

/**
 * execute_command - Executes the command with the full path
 * @argv: The array of command arguments
 * @en: The array of environment variables
 * @fullpath: The full path to the executable
 *
 * Return: void
 */
void execute_command(char **argv, char **en, char *fullpath)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(fullpath, argv, en);
		perror("./shell");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
