#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **av, char **en) {
    char *path = getenv("PATH");
    printf("PATH: %s\n", path);

    char *arg;
    printf("Enter the executable name: ");
    if (scanf("%ms", &arg) != 1) {
        perror("Input error");
        return 1;
    }

    char *path_helper = strdup(path);
    if (path_helper == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    char *token;
    int done = 0;
    char new_arg[256]; // Adjust the size as needed

    char *args[] = {arg, NULL}; // Adjust the argument array

    token = strtok(path_helper, ":");
    while (token != NULL) {
        snprintf(new_arg, sizeof(new_arg), "%s/%s", token, arg);
        if (access(new_arg, X_OK) == 0) { // Check if the file is executable
            execve(new_arg, args, NULL);
            perror("Execution error");
        }
        token = strtok(NULL, ":");
    }

    free(path_helper);
    free(arg);

    return 0;
}

