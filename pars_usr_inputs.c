#include "shell.h"

/**
* splits_txts - Splits lines of written texts in the console.
* @commd: Line writes text to console.
*
* Return: An array to all split words.
*/

char **splits_txts(char *commd)
{
	int tempsize = 64, tracker = 0;
	char **tokens;
	char *token;

	tokens = malloc(tempsize * sizeof(char *));
	if (!tokens)
	{
		perror("shell: allocation error\n");
		return (NULL);
	}

	token = _strtok(commd, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[tracker] = token;
		tracker++;

		if (tracker >= tempsize)
		{
			tempsize += 64;
			tokens = _realloc(tokens, tempsize - 64, tempsize * sizeof(char *));
			if (!tokens)
			{
				perror("shell: allocation error\n");
				return (NULL);
			}
		}
		token = _strtok(NULL, " \t\r\n\a");
	}
	tokens[tracker] = NULL;
	return (tokens);
}
