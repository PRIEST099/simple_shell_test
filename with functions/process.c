#include "main.h"

/**
 * process_input - handles the logic for processig user input
 * @lineptr: pointer to the input line
 * @en: array of environment variables
 *
 * Return: NULL
 */

void process_input(char *lineptr, char **en)
{
	char *cpy_lineptr = strdup(lineptr);
	char **argv;
	char *fullpath;
	int counter;

	if (cpy_lineptr == NULL)
	{
		perror("./shell");
		exit(1);
	}
	counter = count_tokens(cpy_lineptr);
	argv = tokenize_input(lineptr, counter);
	fullpath = pathname(en, lineptr, ":");
	if (fullpath == NULL)
	{
		perror("./shell");
	}
	else
	{
		execute_command(argv, en, fullpath);
		free(fullpath);
	}
	free(argv);
	free(cpy_lineptr);
}
