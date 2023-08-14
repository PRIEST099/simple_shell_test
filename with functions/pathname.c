#include "main.h"

char *pathname(char **en, char *lineptr, char *delim)
{
    char *value, *token;
    size_t length;
    char *combine = NULL;
    char *copy = NULL;
    int i, found = 0;
    int access_value;
    char *path = "PATH=";
    char *delim2 = ":";
    char *token2 = strtok(lineptr, delim);

    if (lineptr == NULL)
    {
        return NULL;
    }

    if (*lineptr == '/' || *lineptr == '.')
	    return (strdup(lineptr));

    for (i = 0; en[i] != NULL; i++)
    {
        if (strstr(en[i], path) == en[i])
        {
            copy = strdup(en[i]);
            value = copy + strlen(path);
            token = strtok(value, delim2);

            while (token != NULL)
            {
                if (found)
                    break;

                length = strlen(token) + strlen(token2) + 2;
                combine = malloc(sizeof(char) * length);

                if (combine == NULL)
                {
                    free(copy); // Free the copied string if an error occurs
                    perror("./shell");
                    return NULL;
                }

                strcpy(combine, token);
                strcat(combine, "/");
                strcat(combine, token2);
                access_value = access(combine, X_OK);
                if (access_value == 0)
                {
                    found = 1;
                }
                else
                {
                    free(combine); /* Free the allocated memory */
                    combine = NULL; /* and again assigning NULL to it so that if it is free at any point, 
				       it does not cause double frees

				       freeing a null string is valid */
                    token = strtok(NULL, delim2);
                }
            }
            free(copy); // Free the copied string
        }
    }
    return combine; // Return the last assigned value of combine
}
