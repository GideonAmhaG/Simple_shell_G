#include "sshell.h"

/**
 * _builtin - checks builtin command and takes proper action
 * @s: first argument of the argument vector (typed "exit")
 */
void _builtin(char *s)
{
	int i;

	if ((_strcmp(s, "exit")) == 0)
	{
		exit(0);
	}

	/*if ((_strcmp(s, "env")) == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}*/
}
