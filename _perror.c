#include "main.h"

/**
 * _perror - Print an error message with program name and line number.
 * @program_name: The name of the program.
 * @error_number: The error number.
 * @command: pointer to input command
 *
 */

void _perror(const char *program_name, int error_number, const char *command)
{
	fprintf(stderr, "%s: %d: :%s :%s\n", program_name,
			error_number, command, strerror(error_number));
}

