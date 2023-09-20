#include "shell.h"

/**
 * main - Simple shell entry point
 * @argc: argument count
 * @argv: argument values vector.
 * Return: Always 0.
 */

int main(__attribute__((unused)) int argc,
__attribute__((unused)) char **argv)
{

	/* Run command the interact_loop.*/
	interact_loop();

	return (0);
}
