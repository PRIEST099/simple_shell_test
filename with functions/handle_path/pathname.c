#include "main.h"

/**
 * pathname - search a command path
 * @en: pointer to system environment
 * @lineptr: pointer to entered command (no args)
 * @delim: delimiters
 *
 * Return: combine on success and NULL on fail
 */

char *pathname(char **en, char *lineptr, char *delim)
{
	char *token1, *token2 = _strtok(lineptr, delim);
	char *value, *combine = NULL, *cpy_en = NULL;
	char *path = "PATH=";
	size_t i;

	if (lineptr == NULL)
		return (NULL);
	if (*lineptr == '/' || *lineptr == '.')
		return (strdup(lineptr));

	for (i = 0; en[i] != NULL; i++)
	{
		if (strstr(en[i], path) == en[i])
		{
			cpy_en = strdup(en[i]);
			value = cpy_en + strlen(path);
			combine = handle_token(value, token1, token2);

			if (combine == NULL)
			{
				free(cpy_en);
				return (NULL);
			}

			break;
		}
	}

	free(cpy_en);
	return (combine);
}

/**
 * handle_token - handle stdin tokens and append to the path
 * @value: pointer to the actual path needed
 * @token1: pointer to the path token
 * @token2: pointer to the stdin command (no args)
 *
 * Return: combine2 on success and NUll on fail
 */

char *handle_token(char *value, char *token1, char *token2)
{
	size_t length;
	char *combine1 = NULL, *combine2 = NULL;
	int access_value, found = 0;

	token1 = _strtok(value, ":");
	while (token1 != NULL)
	{
		length = strlen(token1) + strlen(token2) + 2;
		combine1 = malloc(sizeof(char *) + length);

		if (combine1 == NULL)
			return (NULL);

		strcpy(combine1, token1);
		strcat(combine1, "/");
		strcat(combine1, token2);
		access_value = access(combine1, X_OK);

		if (access_value == 0)
		{
			found = 1;
			combine2 = combine1;
			break;
		}

		else
		{
			free(combine1);
			combine1 = NULL;
		}

		token1 = _strtok(NULL, ":");

		if (!found)
			free(combine1);

	}

	return (combine2);
}
