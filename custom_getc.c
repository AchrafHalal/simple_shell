#include "shell.h"

/**
 * _getc - Reads a text file and prints it to POSIX
 *
 * Return: 0 on success
 */

int _getc(void)
{
	char buff[1];
	char *chread;
	int result_read;

	result_read = read(STDIN_FILENO, buff, 1);
	if (result_read > 0)
	{
		chread = buff;
		return (*chread);
	}

	if (result_read == -1)
		return (0);

	return (EOF);
}
