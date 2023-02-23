#include "sshell.h"

/**
 *_argck - checks if the number of arguments passed to main are more than one
 * @ac: number of arguments for main (argc)
 *
 * Return: 127 (error)
 */

int _argck(int ac)
{
	if (ac > 1)
	{
		perror("Error");
		return (127);
	}
	return (0);
}
