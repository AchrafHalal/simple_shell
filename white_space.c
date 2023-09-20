#include "shell.h"
/**
 * test_white_space - tests if the str is whitespace or new line
 * or tab or return
 * @str: input string
 * Return: 1 if its true 0 Otherwise
 */
int test_white_space(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	for (i = 0; i < _strlen(str); i++)
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\r')
			return (0);
	return (1);
}
