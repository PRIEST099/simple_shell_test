#include "main.h"

int count_tokens(char *lineptr)
{
    int counter = 0;
    char *token = strtok(lineptr, " \n");
    while (token != NULL)
    {
        counter++;
        token = strtok(NULL, " \n");
    }
    return counter;
}

char **tokenize_input(char *lineptr, int count)
{
    char **argv = malloc(sizeof(char *) * (count + 1));
    if (argv == NULL)
    {
        perror("./shell");
        exit(1);
    }

    int i = 0;
    char *token = strtok(lineptr, " \n");
    while (token != NULL)
    {
        argv[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }
    argv[i] = NULL;
    return argv;
}

