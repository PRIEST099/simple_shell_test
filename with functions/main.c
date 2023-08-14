#include "main.h"

/*
 * this is the main program that uses all the other functions
 *
 * it is better to open the functions in different terminals to view how it works
 *
 * * NOTICE * how the memory allocations now is understandable
 */


int main(int ac, char **av, char **en)
{
    char *lineptr = NULL;
    size_t n = 0, length;

    while (1)
    {
        printf("#cisfun$ ");
        length = getline(&lineptr, &n, stdin);

        if (length == -1)
        {
            printf("\n");
            break;
        }
        if (length == 1)
            continue;

        if (lineptr[length - 1] == '\n')
            lineptr[length - 1] = '\0';
        if (strcmp(lineptr, "exit") == 0)
            break;

        process_input(lineptr, en);

    }

    free(lineptr);
    return 0;
}

