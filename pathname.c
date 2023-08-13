#include "main.h"

char *pathname(char **en, char *lineptr, char *delim)
{
	char *value, *token;
	size_t length;
	char *combine = NULL;
	int i, found = 0;
	int access_value;
	char *path = "PATH=";
	char *delim2 = ":";
	char *token2 = strtok(lineptr, delim);

	if (lineptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; en[i] != NULL; i++)
	{
		if (strstr(en[i], path) == en[i])
		{
			char *copy = strdup(en[i]);
			value = copy + strlen(path);
			token = strtok(value, delim2);

			while (token != NULL)
			{
				if (found)
					break;

				length  = strlen(token) + strlen(token2) + 2;
				combine = malloc(sizeof(char) * length);

				if (combine == NULL)
				{
					path = "PATH=";
					printf("combine is null\n\n\n");
					return (NULL);
				}

				strcpy(combine, token);
				strcat(combine, "/");
				strcat(combine, token2);
				access_value = access(combine, X_OK);
				if (access_value == 0)
				{
					path = "PATH=";
					found = 1;
					return (combine);
				}
				else
				{
					free(combine);
					found = 0;
					path = "PATH=";
					token = strtok(NULL, delim2);
				}
			}

		}
	}


	return (NULL);
}
