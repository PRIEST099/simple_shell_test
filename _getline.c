#include "main.h"

/**
 * _allocate_buffer - Allocate memory for the line buffer
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the size of the buffer
 *
 * Return: 0 on success, -1 on failure
 */
static int _allocate_buffer(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFSIZ;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1); /* Memory allocation error */
	}
	return (0);
}

/**
 * _read_char - Read a character from the file descriptor
 * @fd: File descriptor to read from
 * @ch: Pointer to store the read character
 *
 * Return: 1 on success, 0 on end of file, -1 on error
 */
static int _read_char(int fd, char *ch)
{
	ssize_t bytesRead = read(fd, ch, 1);

	if (bytesRead == -1)
	{
		if (bytesRead == 0)
			return (0); /* End of file */
		else
			return (-1); /* Read error */
	}

	return (1);
}

/**
 * _getline - Read a line from a file descriptor
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the size of the buffer
 * @fd: File descriptor to read from
 *
 * Return: Number of bytes read, or -1 on error or end of file
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t pos = 0;
	char *buffer;
	char ch;
	char *newBuffer;

	if (lineptr == NULL || n == NULL)
		return (-1); /* Invalid arguments */
	if (_allocate_buffer(lineptr, n) == -1)
		return (-1); /* Memory allocation error */
	buffer = *lineptr;

	while (1)
	{

		if (_read_char(fd, &ch) != 1)
			break;

		if (pos >= *n - 1)
		{
			*n *= 2;

			newBuffer = (char *)realloc(*lineptr, *n);

			if (newBuffer == NULL)
				return (-1); /* Memory allocation error */
			buffer = newBuffer;
			*lineptr = newBuffer;
		}

		buffer[pos++] = ch;

		if (ch == '\n')
			break;
	}

	buffer[pos] = '\0';

	return (pos);
}
