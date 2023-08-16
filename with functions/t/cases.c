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
		exit(-1);
	token = _strtok(cpy_lineptr, " ");
	while (token != NULL)
	{
		counter++;
		token = _strtok(NULL, " ");
	}
	if (counter == 1)
	{
		free(cpy_lineptr);
		free(_lineptr);
		exit(0);
	}
	else if (counter != 2)
	{
		free(cpy_lineptr);
		free(_lineptr);
		printf("Usage: exit [status:optional]\n");
		return (1);
	}
	argv = malloc(sizeof(char *) * counter);
	if (argv == NULL)
	{
		free(cpy_lineptr);
		free(_lineptr);
		exit(-1);
	}
	token = _strtok(_lineptr, " ");
	while (i < counter)
	{
		argv[i++] = token;
		token = _strtok(NULL, " ");
	}
	status = atoi(argv[1]);
	free(cpy_lineptr);
	free(_lineptr);
	free(argv);
	free(token);
	exit(status);
}

