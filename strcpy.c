#include "shell.h"
/**
 * *_strcpy - Copies the string from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the destination string.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

