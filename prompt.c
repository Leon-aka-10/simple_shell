#include "shell.h"

/**
 * main - integrates the functions to make the shell work
 * Return: 0 on success
 */
int main(void)
{
	char *buff = NULL, **argv = NULL;
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

	if (isatty(STDIN_FILENO) != 1)
	{
		_non_int(built_in_arr);
	}

	(void)signal(SIGINT, sign_handler);
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
/**
 * token_buffer - splits the buffer into tokens
 * @buffer: pointer to the buffer
 * @delimit: delimitator chosen
 * Return: double pointer to the tokens
 **/
char **token_buffer(char *buffer, char *delimit)
{
	int buffsize = 64, iter = 0;
	char **tokens = malloc(sizeof(char *) * (buffsize));
	char *stoken;

	if (!tokens)
	{
		perror("Not possible to allocate memory");
		free(buffer);
		exit(98);
	}
	stoken = _strtok(buffer, delimit);
	while (stoken)
	{
		tokens[iter] = stoken;
		iter++;
		stoken = _strtok(NULL, delimit);
	}
	tokens[iter] = NULL;
	return (tokens);
}

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

/**
 * sign_handler - handles the abscensce of a sign
 * @sig: integer
 */
void sign_handler(int sig)
{
	(void) sig;
	_puts("\n");
	_puts("$ ");
	fflush(stdout);
}
