#include "shell.h"

/**
 * read_commd_ - function reads the command prompt.
 * Return: returns pointer to the read command
 */

char *read_commd_(void)
{
	char *commd = NULL;
	size_t bufsize = 0;
	ssize_t result;


	/* _getline_ allocates the buffer. */
	result = _getline_(&commd, &bufsize, STDIN_FILENO);
	if (result == -1)
	{
		free(commd);
		return (NULL);
	}
	return (commd);
}
