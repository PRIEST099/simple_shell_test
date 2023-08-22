#include "main.h"

/**
 * main - The main function of the simple shell.
 * @ac: Command line argument count.
 * @av: Argument vector.
 * @en: Environment variables.
 *
 * Return: Always 0 on success.
 */

int main(int ac, char **av, char **en)
{
	char *lineptr = NULL;
	size_t n = 0, length, j;
	long unsigned int i = -1;

	(void)ac;
	(void)av;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		length = _getline(&lineptr, &n, STDIN_FILENO);
		if (length == i)
		{
			printf("\n");
			break;
		}
		if (length == 1)
			continue;

		if (lineptr[length - 1] == '\n')
			lineptr[length - 1] = '\0';
		trim_spaces(lineptr);
		if (_strncmp(lineptr, "exit", 4) == 0)
		{
			if (ext(lineptr))
				continue;
			break;
		}
		if (strncmp(lineptr, "cd", 2) == 0)
		{
			if(cd(lineptr))
				perror("./shell");
			continue;
		}
		if (_strncmp(lineptr, "setenv", 6) == 0 ||
				_strncmp(lineptr, "unsetenv", 8) == 0)
		{
			handle_commands(lineptr, en);
		}
		else
		{
			process_input(lineptr, en);
		}
	}
	for (j = 0; en[j] != NULL; j++)
		free(en[j]);
	free(lineptr);
	return (0);
}
