#include "shell.h"
/**
 * print_prompt - Prints the prompt to indicate the program is ready for input
 */

void print_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		high.interactive_mod = 1;
	if (high.interactive_mod)
		write(STDERR_FILENO, "$ ", 2);
}

