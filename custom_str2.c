#include "shell.h"

/**
 * _strcmp - A function that compares two strings
 * @s1: input value
 * @s2: input value
 * Return: number < 0 if string 1 less string 2
 *         number = 0 if string 1 is equal to string 2
 *         number > 0 if string 1 is bigger than string 2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strtok_s - Find the first token in a string until the delimiter
 *             and save the rest of the string in save_str.
 * @s: String.
 * @delim: Delimiter.
 * @sav_str: The rest of the string.
 * Return: First word token up.
 */

char *_strtok_s(char *s, const char *delim, char **sav_str)
{
	char *e;

	if (s == NULL)
		s = *sav_str;

	if (*s == '\0')
	{
		*sav_str = s;
		return (NULL);
	}

	s += _strspn(s, delim);

	if (*s == '\0')
	{
		*sav_str = s;
		return (NULL);
	}
	e = s + _strcspn(s, delim);

	if (*e == '\0')
	{
		*sav_str = e;
		return (s);
	}

	*e = '\0';
	*sav_str = e + 1;
	return (s);
}
/**
 * _strtok - Token up a string of words separated by a delimiter.
 * @s: String.
 * @delim: Delimiter.
 * Return: Word with token.
 */

char *_strtok(char *s, const char *delim)
{
	static char *oldz;

	return (_strtok_s(s, delim, &oldz));
}

/**
 * _strncmp - String comaprison.
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes
 * Return: 0 if equal diff if different.
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	unsigned char ch1 = '\0';
	unsigned char ch2 = '\0';
	int n4;

	if (n >= 4)
	{
		n4 = n >> 2;
		do {
			ch1 = (unsigned char) *s1++;
			ch2 = (unsigned char) *s2++;
			if (ch1 == '\0' || ch1 != ch2)
				return (ch1 - ch2);
			ch1 = (unsigned char) *s1++;
			ch2 = (unsigned char) *s2++;
			if (ch1 == '\0' || ch1 != ch2)
				return (ch1 - ch2);
			ch1 = (unsigned char) *s1++;
			ch2 = (unsigned char) *s2++;
			if (ch1 == '\0' || ch1 != ch2)
				return (ch1 - ch2);
			ch1 = (unsigned char) *s1++;
			ch2 = (unsigned char) *s2++;
			if (ch1 == '\0' || ch1 != ch2)
				return (ch1 - ch2);
		} while (--n4 > 0);
		n &= 3;
	}
	while (n > 0)
	{
		ch1 = (unsigned char) *s1++;
		ch2 = (unsigned char) *s2++;
		if (ch1 == '\0' || ch1 != ch2)
			return (ch1 - ch2);
		n--;
	}
	return (ch1 - ch2);
}

/**
 * _atoi - function that convert a string to an integer
 * @s: convert to an integer
 * Return: An integer
 */

int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}
		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}
		if (isi == 1)
		{
			break;
		}
		c++;
	}
	ni *= min;
	return (ni);
}
