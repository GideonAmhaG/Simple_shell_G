#include "sshell.h"

/**
 * _execute - executes commands and paramets passed in argv
 * @argv: argument vector containing commands and paramenters
 *
 * Return: 0 or 127 if there's an error
 */
int _execute(char **argv)
{
	char *ex_name = NULL, *path = NULL;
	int status = 0, found = 0;
	struct stat st;
	pid_t child_pid;

	if (stat(argv[1], &st) == 0)
	{
		found = 1;
		ex_name = argv[1];
	}
	else
	{
		path = _getenv("PATH", environ);
		ex_name = create_cmd(argv[1], path);
		if (ex_name != NULL)
			found = 1;
		free(path);
	}

	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve((ex_name), (argv + 1), environ) == -1)
			{
				perror(argv[0]);
				free(ex_name);
			}
		}
		else
			wait(&status);
	}
	else
	{
		perror(argv[0]);
		return (127);
	}
	return (0);
}
