#include "shell.h"

/**
 * read_line - read input form stdin
 * Return: pointer to buffer read
 */

char *read_line()
{
	char *buffer = NULL;
	size_t len = 1024;
	int read;

	read = getline(&buffer, &len, stdin);
	if (read == EOF)
	{
		_puts("\n");
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	buffer[_strlen(buffer) - 1] = '\0';
	return (buffer);
}
