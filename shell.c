#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *checkdir(char *c) {
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found\n");  // debugging
        return c;  // Return the original string on error
    }

    int c_length = strlen(c);
    int path_length = strlen(path);

    // Calculate the maximum possible length for the full path
    // considering the token and the command length
    int max_path_length = path_length + c_length + 2;

    char *full_path = malloc(sizeof(char) * max_path_length);
    if (full_path == NULL) {
        printf("Malloc error\n");  // debugging
        return c;  // Return the original string on error
    }

    char *helper = strdup(path);
    if (helper == NULL) {
        free(full_path);
        return c;  // Return the original string on error
    }

    char *token = strtok(helper, ":");
    while (token != NULL) {
        snprintf(full_path, max_path_length, "%s/%s", token, c);
        printf("%s\n", full_path);  // debugging

        if (access(full_path, X_OK) == 0) {
            free(helper);
            return full_path;  // Return the full path if the executable is found
        }

        token = strtok(NULL, ":");  // Get the next token
    }

    free(helper);
    free(full_path);
    return c;  // Return the original string if executable is not found in any directory
}

/**
 * main - a super simple shell to handle only programs
 * Return: 0 on success and 1 on failure
 */



int main(int ac, char **av, char **en)
{
	pid_t pid;
	char *command = NULL, **args, *helper, *cmdcpy;
	char *full_path;
	size_t size = 0, len;
	int counter = 0, i = 0;


	while (1)
	{
		printf("#cisfun$ ");
		len = getline(&command, &size, stdin);
		if (len == -1)
		{
			printf("\n");
			break;
		}

		if (command[len - 1] == '\n')
			command[len - 1] = '\0';

		if (strcmp(command, "exit") == 0)
			break;

		full_path = checkdir(command);
		if (full_path == NULL)
		{
			printf("Error\n");
			perror("./shell");
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			cmdcpy = strdup(command);
			helper = strtok(cmdcpy, " \n");
			counter = 0;
			while(helper != NULL)
			{
				counter++;
				helper = strtok(NULL, " \n");
			}
			args = (char **)malloc(sizeof(char *) * (counter + 1));

			cmdcpy = strdup(command);


			helper = strtok(command, " \n");
			i = 0;
			while (helper != NULL)
			{
				args[i] = helper;
				i++;
				helper = strtok(NULL, " \n");
			}
			args[i] = NULL;

			//printf("%s\n\n\n%s\n\n\n%s\n\n\n", args[0], args[1], full_path);

			execve(full_path, args, en);
			perror("./shell");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	free(command);
	return (0);
}
