#include "shell.h"

/**
 * _getenv_ - funtion that finds environmental variables.
 * @n: the name of environment variable.
 * Return: all the environment variables.
 */

char *_getenv_(const char *n)
{
	size_t length;
	char **geo;

	/* Get the NAME length*/
	length = _strlen((char *)n);


	if (environ == NULL || n[0] == '\0')
		return (NULL);

	length--;
	for (geo = environ; *geo != NULL; geo++)
	{
		if (!_strncmp(*geo, n, length) && (*geo)[length + 1] == '=')
			return (&(*geo)[length + 2]);
	}
	return (NULL);
}
