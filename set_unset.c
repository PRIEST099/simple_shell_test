#include "main.h"

/**
 * _setenv - Set or modify an environment variable
 * @en: Pointer to the environment array
 * @variable: Name of the variable to set/modify
 * @value: Value to assign to the variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char **en, const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		perror("./shell");
		return (-1);
	}

	size_t i;

	for (i = 0; en[i] != NULL; i++)
	{
		if (_strncmp(en[i], variable, _strlen(variable)) == 0)
		{
			char *new_env = malloc(_strlen(variable) + _strlen(value) + 2);

			if (new_env == NULL)
			{
				perror("malloc");
				return (-1);
			}
			_strcpy(new_env, variable);
			_strcat(new_env, "=");
			_strcat(new_env, value);
			en[i] = new_env;
			return (0);
		}
	}

	char *new_env = malloc(_strlen(variable) + _strlen(value) + 2);

	if (new_env == NULL)
	{
		perror("malloc");
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
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char **en, const char *variable)
{
	if (variable == NULL)
	{
		perror("./shell");
		return (-1);
	}

	size_t i, j;

	for (i = 0; en[i] != NULL; i++)
	{
		if (_strncmp(en[i], variable, _strlen(variable)) == 0)
		{
			for (j = i; en[j] != NULL; j++)
			{
				en[j] = en[j + 1];
			}
			return (0);
		}
	}

	perror("./shell");
	return (-1);
}

/**
 * handle_commands - Process shell commands
 * @lineptr: Pointer to the command line input
 * @en: Pointer to the environment array
 */
void handle_commands(char *lineptr, char **en)
{
	char *command = _strtok(lineptr, " \n");

	if (command == NULL)
	{
		return;
	}

	if (_strcmp(command, "setenv") == 0)
	{
		char *variable = _strtok(NULL, " \n");
		char *value = _strtok(NULL, " \n");

		if (variable != NULL && value != NULL)
		{
			_setenv(en, variable, value);
		}
		else
		{
			perror("./shell");
		}
	}
	else if (_strcmp(command, "unsetenv") == 0)
	{
		char *variable = _strtok(NULL, " \n");

		if (variable != NULL)
		{
			_unsetenv(en, variable);
		}
		else
		{
			perror("./shell");
		}
	}
}
