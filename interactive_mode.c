#include "shell.h"
/**
 *hight - it keeps track is interactive mode
 *@no: the signal number
 *Return: nothing
 */
void hight(int no)
{
	(void)no;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

