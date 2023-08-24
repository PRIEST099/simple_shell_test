#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define LINESIZE 1024

void process_input(char *lineptr, char **en, char **av);
int count_tokens(char *lineptr);
char **tokenize_input(char *lineptr, int count, char **av);
void execute_command(char **argv, char **en, char *fullpath, char **av);
char *pathname(char **en, char *lineptr, char *delim);
char *combine_path_token(const char *path, const char *token2);
int check_path_access(const char *path);
char *find_executable_path(char **en,
		const char *path_variable,
		const char *token2);
char *handle_token(char *value, char *token1, char *token2);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *delim);

int ext(char *lineptr, char **av);
int _isdigit(char *status);
int _isspace(int c);

size_t _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strpbrk(const char *s, const char *accept);
char *_strstr(const char *haystack, const char *needle);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(const char *s, int c);
char *_strdup(const char *s);

int _atoi(const char *s);

int _setenv(char **en, const char *variable, const char *value, char **av);
int _unsetenv(char **en, const char *variable, char **av);
void handle_commands(char *lineptr, char **en, char **av);

void trim_spaces(char *lineptr);
int cd(char *lineptr, char **av);

void _perror(const char *program_name, int error_number, const char *command);

#endif
