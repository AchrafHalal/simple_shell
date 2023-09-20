#include "shell.h"

/**
 * _strtok - tokenize a given string.
 * @line: the line to be modified.
 * @stk: an array of strings
 * Return: a pointer to the first token that found
*/

char **_strtok(char *line, char *stk[])
{
	char *token;
	int i = 0;

	token = strtok(line, " ");
	while (token)
	{
		stk[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	stk[i] = NULL;
	return (stk);
}
