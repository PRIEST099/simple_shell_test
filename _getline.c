#include "shell.h"

/**
* _getline - Take one line from the input prompt.
* @data: program's data struct
*
* Return: read count bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	/* check if no more commands exist in the array */
	/* and checks for logical operators */
	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if, indeed, it exists */
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		/* read from the file descriptor into to the buffer */
		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		/* this split lines for \n or ; */
		i = 0;
		do {
			array_commands[i] = _strdup(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	/*obtains the next command (command 0) and remove it from the array*/
	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (_strlen(data->input_line));
}


/**
* check_logic_ops - it checks for and then split && and || operators
* @array_commands: an array of the cmds.
* @i: Index to be checked
* @array_operators: an array of the logical operators for each prev cmd
*
* Return: Index of the last cmd
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	/* checks for the & in the command line*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* split the line when && was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _strdup(array_commands[i]);
			array_commands[i + 1] = _strdup(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			/* split the line when || was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _strdup(array_commands[i]);
			array_commands[i + 1] = _strdup(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
