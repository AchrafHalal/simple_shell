#include "shell.h"
/**
 * shexit - handle shell exit
 * @line: a comparission var.
 * Return: Nothing
 */
int shexit(char *line)
{
	if (_strcmp(line, "exit", _strlen("exit")) == 0)
	{
		exit(1);
	}
	else if (_strcmp(line, "\n", _strlen(line)) == 0)
	{
		return (0);
	}
	return (2);
}

