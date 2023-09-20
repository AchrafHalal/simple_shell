#include "shell.h"
/**
 * _strchr - custom strchr find the first occurrence of a specified character
 * @str: string input
 * @c: character
 * Return: pointer to the first occurrence of the character
 *  or a null pointer (NULL) if the character is not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
