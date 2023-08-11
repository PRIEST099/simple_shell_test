#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - a super simple shell to handle only programs
 * Return: 0 on success and 1 on failure
 */

extern char *environ[];

int main(void)
{
	pid_t pid;
	char *command = NULL, **args, *helper, *cmdcpy;
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
		{
			break;
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


			helper = strtok(command, " \n");
			i = 0;
			while (helper != NULL)
			{
				args[i] = helper;
				i++;
				helper = strtok(NULL, " \n");
			}
			args[i] = NULL;

			//printf("%s\n\n\n%s\n\n\n", args[0], env[0]);

			execve(args[0], args, environ);
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
