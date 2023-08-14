#include "main.h"

/**
 * main - the main function of simple shell
 * @ac: command line argument count
 * @av: argument vector
 * @en: environment variables
 *
 * Return: always 0 on success
 */

itn main(int ac, char **av, char **en)
{
	char *lineptr = NULL;
	size_t n = 0, length;

	while (1)
	{
		printf("#cisfun$ ");
		length = getline(&lineptr, &n, stdin);
		if (length == -1)
		{
			printf("\n");
			break;
		}
		if (length == 1)
			continue;

		if (lineptr[length - 1] == '\n')
			lineptr[length - 1] = '\0';
		if (strcmp(lineptr, "exit") == 0)
			break;
		process_input(lineptr, en);
	}
	free(lineptr);
	return (0);
}
