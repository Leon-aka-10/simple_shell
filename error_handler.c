#include "shell.h"
/**
 * _error_handler - handles the error, and prints them according to format
 * @status: exit status
 * @err: line counter
 * @argv: Buffer containing the tokens
 */
void _error_handler(int status, int err, char **argv)
{
	/* error msg */

	switch (status)
	{
		case 127:
			_print_base_error(err, argv);
			_puts("not found");
			_puts("\n");
			break;
		case 2:
			_print_base_error(err, argv);
			_puts("Illegal number");
			if (argv[1])
			{
				_puts(": ");
				_puts(argv[1]);
				_puts("\n");
			}
			break;
		default:
			break;
	}
}
/**
 * _print_base_error - prints the errors
 * @err: line counter
 * @argv: buffer containing the tokens
 */
/*void _print_base_error(int err, char **argv)
{
	_puts(program_invocation_name);
	_puts(": ");
	print_number(err);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
}
