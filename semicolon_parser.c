#include "shell.h"
/**
 * simicolen - Executes commands separated by semicolons
 * @line: Command line input
 * @envp: Environment variables
 * @argv: Argument variables
 * Return: 1 if semicolon-separated commands are executed, 0 otherwise.
 */
int simicolen(char *line, char *envp[], char *argv[])
{
	int i = 0, j;
	char **stk2 = malloc(1024 * sizeof(char *));
	char **exe = malloc(1024 * sizeof(char *));

	if (_strchr(line, ';') != NULL && line[0] != ';')
	{
		stk2[0] = strtok(line, ";");
		if (stk2[0] == NULL)
		{
			free(exe);
			free(stk2);
			return (0);
		}
		while (stk2[i] != NULL)
		{
			i++;
			stk2[i] = strtok(NULL, ";");
		}
		stk2[i] = NULL;
		j = i - 1;
		i = 0;
		while (j >= i)
		{
			stk2[i] = _which(stk2[i], envp);
			if (stk2[i] == NULL)
			{
				_fork(stk2, stk2, envp, argv);
				continue;
			}
			_strtok(stk2[i], exe);
			_fork(exe, exe, envp, argv);
			i++;
		}
		free(exe);
		free(stk2);
		return (1);
	}
	free(exe);
	free(stk2);
	return (0);
}

