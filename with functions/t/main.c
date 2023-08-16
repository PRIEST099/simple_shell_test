#include "main.h"

/**
 * main - the main function of simple shell
 * @ac: command line argument count
 * @av: argument vector
 * @en: environment variables
 *
 * Return: always 0 on success
 */

int main(int ac, char **av, char **en)
{
	char *lineptr = NULL;
	size_t n = 0, length;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		length = _getline(&lineptr, &n, STDIN_FILENO);
		if (length == -1)
		{
			printf("\n");
			break;
		}
		if (length == 1)
			continue;

		if (lineptr[length - 1] == '\n')
			lineptr[length - 1] = '\0';
		if (strncmp(lineptr, "exit", 4) == 0)
		{
			if (ext(lineptr))
				continue;
			break;
		}
		process_input(lineptr, en);
	}
	free(lineptr);
	return (0);
}
