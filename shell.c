#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - integrates the functions to make the shell work
 * Return: 0 on success
 */
int main(void)
{
    char *buffer = NULL, **argv = NULL;
	int flag = 1, err_count = 0;
	int status = EXIT_SUCCESS;

        built_in_t built_in_arr[] = {
		{"exit", ourexit},
		{"env", _printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{NULL, NULL}
	};

	/*if (isatty(STDIN_FILENO) != 1)
	{
		_non_int(built_in_arr);
	}*/

	/*(void)signal(SIGINT, sign_handler);*/
	(void) built_in_arr;

	while (flag)
	{
		_puts("$ ");

		err_count++;

		buffer = read_line();

		argv = token_buffer(buffer, " \t\r\n\a");

		status = shell_exec(argv, built_in_arr);

		/*printf("------>status: %d\n", status);*/

		_error_handler(status, err_count, argv);
		free(argv);
		free(buffer);
	}
	return (status);
}
