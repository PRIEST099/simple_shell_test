#include "main.h"

void process_input(char *lineptr, char **en)
{
    char *cpy_lineptr = strdup(lineptr);
    if (cpy_lineptr == NULL)
    {
        perror("./shell");
        exit(1); // Exit the program due to memory allocation failure
    }

    char **argv;
    int counter = count_tokens(cpy_lineptr);
    argv = tokenize_input(lineptr, counter);

    char *fullpath = pathname(en, lineptr, " :");
    if (fullpath != NULL)
    {
        execute_command(argv, en, fullpath);
        free(fullpath);
    }

    free(argv);
    free(cpy_lineptr);
}

