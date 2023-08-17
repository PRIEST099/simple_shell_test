#include "main.h"

/**
 * ext - handles the exit command with or without the status
 * @lineptr: pointer to the entered command
 * Return: void
 */

int ext(char *lineptr)
{
	char *_lineptr = strdup(lineptr);
	char *cpy_lineptr = strdup(lineptr);
	char *token = NULL, **argv = NULL;
	int counter = 0, status, i = 0;

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
		printf("Usage: exit [status:optional]\n");
		return (1);
	}
	argv = tokenize_input(lineptr, counter);
	if(_isdigit(argv[1]) != 0)
	{
		free(cpy_lineptr);
		free(argv);
		free(_lineptr);
		printf("Usage: exit [status:optional]\n");
		return (1);
	}
	status = atoi(argv[1]);
	free(argv);
	free(cpy_lineptr);
	free(_lineptr);
	free(lineptr);
	exit(status);
}
