#include "shell.h"

/**
 * exe - Executes a command
 * @stk: Array of command tokens
 * @envp: Environment variables array
 * @argv: Argument vector
 * @line: Input command line
 */

void exe(char **stk, char *envp[], char *argv[], char *line)
{
	char *cmd = NULL;

	cmd = _which(line, envp);
	if (cmd == NULL)
	{
		return;
	}
	_strtok(cmd, stk);
	_fork(stk, stk, envp, argv);
	free(cmd);
}

