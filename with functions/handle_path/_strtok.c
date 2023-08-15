#include "main.h"

/**
 * _strtok - tokenize a string
 * @str: pointer to a string
 * @delim: delimiters
 *
 * Return: token_start (Success) and NULL (fail)
 */

char *_strtok(char *str, const char *delim)
{
	static char *buffer;

	if (str)
		buffer = str;

	if (!buffer)
		return (NULL);

	char *token_start = buffer;
	char *token_end = strpbrk(buffer, delim);

	if (token_end)
	{
		*token_end = '\0';
		buffer = token_end + 1;
	}

	else
	{
		buffer = NULL;
	}

	return (token_start);
}
