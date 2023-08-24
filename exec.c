#include "main.h"

/**
 * execute_command - Executes the command with the full path
 * @argv: The array of command arguments
 * @en: The array of environment variables
 * @fullpath: The full path to the executable
 * @av: Pointer to input array
 *
 * Return: void
 */
void execute_command(char **argv, char **en, char *fullpath, char **av)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(fullpath, argv, en);
		_perror(av[0], errno, (char *)argv);
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
