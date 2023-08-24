#include "main.h"

/**
 * process_input - handles the logic for processing user input
 * @lineptr: pointer to the input line
 * @en: array of environment variables
 * @av: Pointer to input array
 *
 * Return: void
 */
void process_input(char *lineptr, char **en, char **av)
{
	char *cpy_lineptr = _strdup(lineptr);
	char **argv;
	char *fullpath;
	int counter;

	if (cpy_lineptr == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0],
				errno, lineptr);
		exit(1);
	}

	counter = count_tokens(cpy_lineptr);
	argv = tokenize_input(lineptr, counter, av);
	fullpath = pathname(en, lineptr, ":");

	if (fullpath == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0],
				errno, lineptr);
	}
	else
	{
		execute_command(argv, en, fullpath, av);
		free(fullpath);
	}

	free(argv);
	free(cpy_lineptr);
}
