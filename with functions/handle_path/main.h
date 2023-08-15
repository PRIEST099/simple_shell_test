#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void process_input(char *lineptr, char **en);
int count_tokens(char *lineptr);
char **tokenize_input(char *lineptr, int count);
void execute_command(char **argv, char **en, char *fullpath);
char *pathname(char **en, char *lineptr, char *delim);
char *combine_path_token(const char *path, const char *token2);
int check_path_access(const char *path);
char *find_executable_path(char **en,
		const char *path_variable,
		const char *token2);
char *handle_token(char *value, char *token1, char *token2);

/**
 * getline prototype
 */
int _getline(char **lineptr, size_t *n, int fd);


#endif

