#include "main.h"

/**
 * count_tokens - Counts the number of input arguments.
 * @lineptr: The input string to be tokenized.
 *
 * Return: the number of tokens
 */

int count_tokens(char *lineptr)
{
	char *token;
	int counter = 0;

	token = strtok(lineptr, " \n");
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, " \n");
	}
	return (counter);
}

/**
 * tokenize_input - Tokenizes the input string
 * @lineptr: The input string to be tokenized
 * @count: The number of tokens to be expected
 *
 * Return: Array of token strings.
 */

char **tokenize_input(char *lineptr, int count)
{
	char **argv;
	int i = 0;
	char *token;

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		perror("./shell");
		exit(1);
	}
	token = strtok(lineptr, " \n");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	return (argv);
}
