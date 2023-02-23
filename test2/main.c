#include "sshell.h"

/**
 * main - simple shell
 * @ac: number of arguments passed to main
 * @av: arguments vector
 *
 * Return: 0 or, on error, 127
 */
int main(int ac, char **av, char **env)
{
	size_t len = 0;
	char *token = NULL, *buffer = NULL, *argv[100], **childenv = env;
	int i, chars_read, ret;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror(argv[0]);
	ret = _argck(ac);
	while (1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		chars_read = getline(&buffer, &len, stdin);
		if (chars_read == EOF)
		{
			free(buffer);
			write(STDIN_FILENO, "\n", 1);
			return (0);
		}
		if (chars_read > 1)
		{
			token = strtok(buffer, " \n");
			argv[0] = av[0];
			for (i = 1; i < 100 && token != NULL; i++)
			{
				argv[i] = token;
				token = strtok(NULL, " \n");
			}
			argv[i] = NULL;
			if (argv[1])
			{
				_builtin(argv[1]);
				if ((_strcmp(argv[1], "exit")) != 0 &&
						(_strcmp(argv[1], "env")) != 0)
					ret = _execute(argv, childenv);
			}
		}
	}
	return (ret);
}
