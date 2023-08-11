#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Get the PATH environment variable
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "Unable to retrieve PATH environment variable.\n");
        return 1;
    }

    // Tokenize the PATH variable using ':' as the delimiter
    char *path_entry = strtok(path, ":");
    while (path_entry != NULL) {
        // Construct the full path to 'ls' executable
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/ls", path_entry);

        // Check if the file exists and is executable
        if (access(full_path, X_OK) == 0) {
            printf("'ls' executable found at: %s\n", full_path);

            // Prepare environment for execve
            char *env[] = {NULL}; // Null-terminated array
            if (execve(full_path, (char *const[]){"ls", "-al", NULL}, env) == -1) {
                perror("execve");
                return 1;
            }

            // If execve succeeds, the following lines won't be reached
        }

        // Move to the next path entry
        path_entry = strtok(NULL, ":");
    }

    printf("'ls' executable not found in any PATH directory.\n");
    return 1;
}

