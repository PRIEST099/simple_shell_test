#include "main.h"

/**
 * changeDirectory - Change the current directory
 * @newDir: Directory to change to
 *  Return: 0 on success, 1 on failure
 */

int changeDirectory(const char *newDir)
{
	char *directory_buf = NULL;

	if (chdir(newDir) == 0)
	{
		directory_buf = getcwd(NULL, 0);
		if (directory_buf)
		{
			setenv("PWD", directory_buf, 1);
			free(directory_buf);
			return (0);
		}
	}
	return (1);
}

/**
 * changeToHomeDirectory - Handle changing to the home directory
 * @old_pwd: Pointer to store the old working directory
 * Return: 0 on success, 1 on failure
 */

int changeToHomeDirectory(char **old_pwd)
{
	char *directory_buf = getenv("HOME");

	*old_pwd = getcwd(NULL, 0);
	return (changeDirectory(directory_buf));
}

/**
 * changeToNamedDirectory - Handle changing to a directory by name
 * @dir_name: Directory name to change to
 * @old_pwd: old working directory
 * Return: 0 on success, 1 on failure
 */

int changeToNamedDirectory(const char *dir_name, char **old_pwd)
{
	char *current_dir = getcwd(NULL, 0);
	char *new_dir = NULL;
	int status;

	if (*dir_name == '/')
	{
		new_dir = _strdup(dir_name);
	}
	else
	{
		new_dir = (char *)malloc(_strlen(current_dir) + _strlen(dir_name) + 2);
		if (new_dir)
		{
			_strcpy(new_dir, current_dir);
			_strcat(new_dir, "/");
			_strcat(new_dir, dir_name);
		}
		else
		{
			free(current_dir);
			return (1);
		}
	}
	*old_pwd = current_dir;
	status = changeDirectory(new_dir);
	free(new_dir);
	return (status);
}

/**
 * changeToPreviousDirectory - Handle changing to the previous directory
 * @old_pwd: Pointer to the old working directory
 * Return: 0 on success, 1 on failure
 */

int changeToPreviousDirectory(char **old_pwd)
{
	char *current_dir = getcwd(NULL, 0);

	changeDirectory(*old_pwd);
	*old_pwd = current_dir;
	return (0);
}

/**
 * cd - Handle the 'cd' command
 * @lineptr: Command string entered
 * Return: 0 on success, 1 on failure
 */

int cd(char *lineptr)
{
	char *cpy_lineptr = _strdup(lineptr);
	char *_lineptr = _strdup(lineptr);
	int counter = 0;
	char **argv = NULL;
	char *old_pwd = getenv("OLDPWD");
	int status = 1;

	if (cpy_lineptr == NULL || _lineptr == NULL)
		return (1);
	counter = count_tokens(_lineptr);
	if (counter < 2)
	{
		status = changeToHomeDirectory(&old_pwd);
	}
	else
	{
		argv = tokenize_input(lineptr, counter);
		if (argv == NULL)
		{
			free(cpy_lineptr);
			free(_lineptr);
			return (1);
		}
		if (*argv[1] == '/')
			status = changeToNamedDirectory(argv[1], &old_pwd);
		else if (_strcmp(argv[1], "-") == 0)
			status = changeToPreviousDirectory(&old_pwd);
		else
			status = changeToNamedDirectory(argv[1], &old_pwd);
	}
	setenv("OLDPWD", old_pwd, 1);
	free(cpy_lineptr);
	free(_lineptr);
	free(argv);
	free(old_pwd);
	return (status);
}
