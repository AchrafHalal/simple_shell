#include "shell.h"

/**
 * _strlen - function that returns the length of a string.
 * @str: The string to get the length.
 * Return: lenght of string.
 */
int _strlen(char *str)
{
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcat - function that concatenates two strings.
 * @dest: The destination of the string.
 * @src: The source string.
 * Return: pointer to the concatenated strings.
 */
char *_strcat(char *dest, char *src)
{
	int j;
	int dlen = _strlen(dest);

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[dlen + j] = src[j];
	}
	dest[dlen + j] = '\0';

	return (dest);
}

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: The destination value.
 * @src: source value.
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int k, j = 0;

	while (*(src + j) != '\0')
	{
		j++;
	}

	for (k = 0; k <= j; k++)
	{
		*(dest + k) = *(src + k);
	}

	dest[k + 1] = '\0';
	return (dest);
}

/**
 * _strcspn - function that finds position of delimiter in the string.
 * @str: The string value.
 * @delim: The delimiter.
 * Return: the delimeter in the string.
 */
int _strcspn(char *str, const char *delim)
{
	int counts = 0, j;

	while (*str)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (*str == delim[j])
				return (counts);
		}
		counts++;
		str++;
	}
	return (counts);
}

/**
 * _strspn - Determines position as the delimiter equals the string.
 * @str: The string value.
 * @delim: The delimiter.
 * Return: the delimiter as different from the string.
 */
int _strspn(char *str, const char *delim)
{
	int j;

	for (j = 0; (str[j] == delim[j]) && (str[j] != '\0' && delim[j] != '\0'); j++)
	{
		;
	}
	return (j);
}
