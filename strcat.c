#include "shell.h"
/**
 * *_strcat - calculates the lengths of strings
 * @dest: the destination string
 * @src: the source string
 * Return: a string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

