#include "shell.h"
/**
 * _strcmp - Compares two strings up to a specified number of bytes
 * @s1: First input string
 * @s2: Second input string
 * @n: Number of bytes to compare
 *
 * Return: A negative value if s1 is less than s2, a positive value if s1,
 * is greater than s2 and 0 if s1 is = to s2 up to the specified num of bytes.
 */

int _strcmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && i < n)
	{
		if (s1[i] > s2[i] || s2[i] > s1[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
