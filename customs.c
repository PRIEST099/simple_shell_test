#include "main.h"

/**
 * ext - handles the exit command with or without the status
 * @lineptr: pointer to the entered command
 * @av: Pointer to input array
 *
 * Return: void
 */

int ext(char *lineptr, char **av)
{
	char *_lineptr = _strdup(lineptr);
	char *cpy_lineptr = _strdup(lineptr);
	char **argv = NULL;
	int counter = 0, status;

	if (_lineptr == NULL || cpy_lineptr == NULL)
	{
		free(lineptr);
		exit(-1);
	}
	counter = count_tokens(cpy_lineptr);
	if (counter == 1)
	{
		free(cpy_lineptr);
		free(_lineptr);
		free(lineptr);
		exit(0);
	}
	else if (counter != 2)
	{
		free(cpy_lineptr);
		free(_lineptr);
		return (1);
	}
	argv = tokenize_input(lineptr, counter, av);
	if (_isdigit(argv[1]) != 0)
	{
		free(cpy_lineptr);
		free(argv);
		free(_lineptr);
		return (1);
	}
	status = _atoi(argv[1]);
	free(argv);
	free(cpy_lineptr);
	free(_lineptr);
	free(lineptr);
	exit(status);
}
