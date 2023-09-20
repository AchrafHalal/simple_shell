#include "shell.h"

/**
* _split_commd_ - This splits the command written in the console.
* @commd: command written in the console.
* Return: An array with all words split.
*/

char **_split_commd_(char *commd)
{
	int bufsize = 64, post = 0;
	char **tokenize;
	char *tokens;

	tokenize = malloc(bufsize * sizeof(char *));
	if (!tokenize)
	{
		perror("shell: allocation error\n");
		return (NULL);
	}

	tokens = _strtok(commd, " \t\r\n\a");
	while (tokens != NULL)
	{
		tokenize[post] = tokens;
		post++;

		if (post >= bufsize)
		{
			bufsize += 64;
			tokenize = _realloc(tokenize, bufsize - 64, bufsize * sizeof(char *));
			if (!tokenize)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		tokens = _strtok(NULL, " \t\r\n\a");
	}
	tokenize[post] = NULL;
	return (tokenize);
}
