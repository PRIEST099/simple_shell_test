#include "main.h"

/**
 * _setenv - Set or modify an environment variable
 * @en: Pointer to the environment array
 * @variable: Name of the variable to set/modify
 * @value: Value to assign to the variable
 * @av: Pointer to input array
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char **en, const char *variable, const char *value, char **av)
{
	size_t i;
	char *new_env = NULL;

	if (variable == NULL || value == NULL)
	{
		_perror(av[0], errno, variable);
		return (-1);
	}
	for (i = 0; en[i] != NULL; i++)
	{
		if (_strncmp(en[i], variable, _strlen(variable)) == 0)
		{
			free(en[i]);
			new_env = malloc(_strlen(variable) + _strlen(value) + 2);
			if (new_env == NULL)
			{
				_perror(av[0], errno, new_env);
				return (-1);
			}
			_strcpy(new_env, variable);
			_strcat(new_env, "=");
			_strcat(new_env, value);
			en[i] = new_env;
			return (0);
		}
	}

	new_env = malloc(_strlen(variable) + _strlen(value) + 2);
	if (new_env == NULL)
	{
		_perror(av[0], errno, new_env);
		return (-1);
	}
	_strcpy(new_env, variable);
	_strcat(new_env, "=");
	_strcat(new_env, value);
	en[i] = new_env;
	en[i + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @en: Pointer to the environment array
 * @variable: Name of the variable to remove
 * @av: Pointer to input array
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char **en, const char *variable, char **av)
{
	size_t i, j;

	if (variable == NULL)
	{
		_perror(av[0], errno, variable);
		return (-1);
	}
	for (i = 0; en[i] != NULL; i++)
	{
		if (_strncmp(en[i], variable, _strlen(variable)) == 0)
		{
			free(en[i]);
			for (j = i; en[j] != NULL; j++)
				en[j] = en[j + 1];
			return (0);
		}
	}
	_perror(av[0], errno, variable);
	return (-1);
}

/**
 * handle_commands - Process shell commands
 * @lineptr: Pointer to the command line input
 * @en: Pointer to the environment array
 * @av: Pointer to input array
 *
 */
void handle_commands(char *lineptr, char **en, char **av)
{
	char *_lineptr = _strdup(lineptr);
	char *command = _strtok(lineptr, " \n");
	char *err = NULL;

	if (command == NULL || _lineptr == NULL)
	return;
	if (_strcmp(command, "setenv") == 0)
	{
		char *variable = _strtok(NULL, " \n");
		char *value = _strtok(NULL, " \n");

		if (variable != NULL && value != NULL)
		{
			_setenv(en, variable, value, av);
		}
		else
		{
	fprintf(stderr, "%s: %d: %s: not found\n", av[0], errno, command);
		}
	}
	else if (_strcmp(command, "unsetenv") == 0)
	{
		char *variable = _strtok(NULL, " \n");

		if (variable != NULL)
		{
			_unsetenv(en, variable, av);
		}
		else
		{
	fprintf(stderr, "%s: %d: %s: not found\n", av[0], errno, command);
		}
	}
	else if (_strcmp(command, "cd") == 0)
	{
		err = _strtok(NULL, " \n\t");
		if (cd(_lineptr, av))
		fprintf(stderr, "%s: %d: can't cd to %s\n", av[0], errno, err);
	}
	free(_lineptr);
}
