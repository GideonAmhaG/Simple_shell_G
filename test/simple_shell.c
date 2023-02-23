#include "sshell.h"

/**
 * main - super simple shell
 * @ac: number of arguments passed to main
 * @av: arguments vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t len = 0;
	char *token = NULL, *buffer = NULL, *argv[100];
	int i, chars_read, status, found = 0;
	struct stat st;
	pid_t child_pid;

	//signal inteeruppt
	if (ac > 1)
	{
		perror("Error");
		return(127);
	}
	
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
				_exit_handler();
				_env_handler();
				if ((_strcmp(argv[1], "exit") != 0 &&
						(_strcmp(argv[1], "env") != 0)
					j = argvone(argv);
			}
		}
	}
	

	return (j);
}

	int argvone(char **argv)
	{
		char *ex_name = NULL;
		int status = 0, found = 0, mem_c = 0;
		struct stat st;
		pid_t child_pid;


				//_env(argv[1], environ);

				if (stat(argv[1], &st) == 0)
				{
					found = 1; 
					ex_name = argv[1];
				}
				else
				{
					  ex_name = create_cmd(argv[1]);
					  if (ex_name != NULL)
					  {
						  mem_c = 1;
						  found = 1;
					  }
				}

				if (found)
				{			
					child_pid = fork();
					if (child_pid == 0)
					{
						if (execve((ex_name), (argv + 1), environ)
							== -1)
						{
							perror(av[0]);
							
							//(mem_c == 1) ? free(ex_name) : (void) mem_c;
						}
					}
					
						wait(&status);
				}
				else
				{
					perror(av[0]);
					return(127);
				}

				return (0);
	}
