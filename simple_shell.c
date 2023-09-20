#include "shell.h"

/**
 * main - entry point for simple shell
 * @argc: argument counts.
 * @argv: an array of strings.
 * Return: 0 or -1.
 */
int main(int argc, char *argv[])
{
	char *stk[10], *av[] = {NULL}, *line = NULL;
	int space;
	
	if (argc != 1)
	{
		return (0);
	}
	while (1)
	{
		_puts("$ ");
		line = _getline(line);
		space = test_white_space(line);
		if (space == 1)
		{
			stk[0] = "\n";
			continue;
		}
		_strtok(line, stk);
		_fork2(stk, av, argv);
	}
	free(line);
	return (0);
}

