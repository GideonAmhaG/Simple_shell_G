#include "sshell.h"

/**
 * _execute - executes commands and paramets passed in argv
 * @argv: argument vector containing commands and paramenters
 *
 * Return: 0 or 127 if there's an error
 */
int _execute(char **argv, char **env)
{
	char *ex_name = NULL, *path = NULL, **en = NULL;
	int status = 0, found = 0;
	struct stat st;
	pid_t child_pid;

	for (int i = 0; env[i] != NULL; i++)
	{
		en = realloc(en, (i + 2) * sizeof(char *));
		en[i] = strdup(env[i]);
		en[i + 1] = NULL;
	}

	if (stat(argv[1], &st) == 0)
	{
		found = 1;
		ex_name = argv[1];
	}
	else
	{
		path = _getenv("PATH", env);
		ex_name = create_cmd(argv[1], path);
		if (ex_name != NULL)
		{
			found = 1;
		}
		free(path);
	}
	if (ex_name != NULL)
	{
		printf("%s\n", argv[1]);
		printf("%s\n", ex_name);
	}
	else
	{
		printf("%s\n", argv[1]);
		printf("NULL\n");
	}

	if (found)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			setenv("PATH", path, 1);
			if (execve((ex_name), (argv + 1), en) == -1)
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
