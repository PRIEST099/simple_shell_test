#include "main.h"

/**
 * _isspace - Check if a character is a whitespace character.
 * @c: The character to be checked.
 *
 * Return: 1 if @c is a whitespace character, 0 otherwise.
 */

int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
	    || c == '\f' || c == '\v');
}

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

	token = _strtok(lineptr, " \n");
	while (token != NULL)
	{
		counter++;
		token = _strtok(NULL, " \n");
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
	char *end;

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		perror("./shell");
		exit(1);
	}
	token = _strtok(lineptr, " \n");
	while (token != NULL)
	{
		/* Trim leading spaces */
		while (*token && _isspace(*token))
			token++;
		/* Trim trailing spaces */
		end = token + _strlen(token) - 1;

		while (end > token && _isspace(*end))
			end--;

		*(end + 1) = '\0';

		if (*token)
		{
			argv[i] = token;
			i++;
		}
		token = _strtok(NULL, " \n");
	}
	argv[i] = NULL;
	return (argv);
}
