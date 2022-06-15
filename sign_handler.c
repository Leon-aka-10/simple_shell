#include "shell.h"
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
