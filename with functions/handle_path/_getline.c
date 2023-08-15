#include "main.h"

/**
 * _getline - reads string from an imput usidn fd
 * @lineptr: pointer to string to keep read string
 * @n: size of the buffer
 * @fd: file descriptor of the stream
 * Return: the number os read characters
 */

int _getline(char **lineptr, size_t *n, int fd)
{
	int count;
	size_t i = 0, new_size;
	char *new_ptr;

	if (lineptr == NULL | n == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = LINESIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((count = read(fd, &((*lineptr)[i]), 1)) > 0)
	{
		if (i + 1 >= *n)
		{
			new_size = *n * 2;
			new_ptr = (char *)realloc(*lineptr, new_size);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
			*n = new_size;
		}
		if ((*lineptr)[i] == '\n')
			break;
		i++;
	}

	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}

