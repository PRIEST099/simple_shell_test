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
	char *token_start = NULL;
	char *token_end = NULL;

	if (str)
		buffer = str;

	if (!buffer)
		return (NULL);

	while (*buffer && _strchr(delim, *buffer))
		buffer++;

	if (*buffer == '\0')
	{
		buffer = NULL;
		return (NULL);
	}

	token_start = buffer;
	token_end = _strpbrk(buffer, delim);

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
