#include "main.h"

/**
 * trim_spaces - removes spaces at the start and end of a string
 * @lineptr: string to trim
 * Return: null
 */

void trim_spaces(char *lineptr)
{
	int start = 0, end = 0, length = 0, i;

	if (lineptr == NULL)
		return;
	while (lineptr[start] == ' ' || lineptr[start] == '\t')
		start++;

	while (lineptr[length] != '\0')
	{
		if (lineptr[length] != ' ')
			end = length;
		length++;
	}

	for (i = 0; i <= end - start; i++)
		lineptr[i] = lineptr[start + i];
	lineptr[end - start + 1] = '\0';
}
