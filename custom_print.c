#include "shell.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print like puts function
 * @str: pointer to a char
 * Return: void
 */

void _puts(char *str)
{
	int acc = 0;

	while (str[acc] != '\0')
	{
		_putchar(str[acc]);
		acc++;
	}
}
