#include "main.h"

/**
 * _isdigit - checks is a string is a number of not
 * @status: number to check
 * Return: 0 on success and 1 on failure
 */

int _isdigit(char *status)
{
	if (status == NULL || *status == '\0')
		return (1);
	while (*status != '\0')
	{
		if ((*status < '0' || *status > '9')
				&& *status != '.' && *status != '-')
		{
			return (1);
		}
		status++;
	}
	return (0);
}
