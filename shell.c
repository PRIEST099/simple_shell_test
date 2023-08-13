#include "main.h"

int main(int ac, char **av, char **en)
{
    char *lineptr = NULL, *token, *cpy_lineptr, *fullpath;
    size_t n = 0, length;
    char *delim = " \n";
    pid_t pid;
    char **argv;
    int status = 0, i;
    int counter = 0;

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

        cpy_lineptr = strdup(lineptr);
        if (cpy_lineptr == NULL)
        {
            perror("./shell");
            exit(1);  // Exit the program due to memory allocation failure
        }


  token = strtok(cpy_lineptr, delim);
                 while (token != NULL)
                 {
                         counter++;
                         token = strtok(NULL, delim);
                 }

                argv = malloc(sizeof(char *) * (counter + 1));
                if (argv == NULL)
                {
                        free(lineptr);
                        free(argv);
                        perror("./shell");
                        exit(1);
                }

                i = 0;
                token = strtok(lineptr, delim);
                while (token != NULL)
                {
                        argv[i] = token;
                        i++;
                        token = strtok(NULL, delim);
                }
                argv[i] = NULL;
                fullpath = pathname(en, lineptr, delim);
                if (fullpath == NULL)
                {
                        perror("./shell");
			free(argv);
			free(cpy_lineptr);
                        continue;
                }

                pid = fork();
                if (pid == 0)
                {
                        execve(fullpath, argv, en);
                        perror("./shell");
                }
                else
                {
                        wait(NULL);
                }

                free(argv);
		free(cpy_lineptr); /* Free the duplicated lineptr */
		free(fullpath);
		fullpath = NULL;

    }

    free(lineptr); // Free the main input buffer
    return 0;
}

