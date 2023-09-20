#include "shell.h"

/**
  * sigint_handler - Handles the signal.
  * @signa: The signal.
  */

void sigint_handler(int signa)
{
	(void)signa;
	_putchar('\n');
	write(STDOUT_FILENO, "~$ ", 3);
	fflush(stdout);
}
