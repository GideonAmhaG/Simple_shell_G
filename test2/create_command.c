#include "sshell.h"

/**
 * create_cmd - creates command that will be first element of execve
 * @cmd: first element of argv as typed
 *
 * Return: pointer to created command
 */
char *create_cmd(char *cmd, char *path)
{
	struct stat buf;
	char *token = NULL, *pathname = NULL;
	
	//path = getenv("PATH");
	
	//setenv("PATH", path, 1);


	/*while (*env)
	{
		printf("%s\n", *env);
		env++;
	}*/
	//printf("path: %s\n", path);
	token = strtok(path, ":");
	while (token != NULL)
	{
		
		pathname = malloc((_strlen(token) + _strlen(cmd) + 2)
				* sizeof(char));
		if (pathname == NULL)
		{
			free(pathname);
			return (NULL);
		}
		_strcpy(pathname, token);
		_strcat(pathname, "/");
		_strcat(pathname, cmd);
		if (stat(pathname, &buf) == 0)
			return (pathname);

		printf("pathname: %s\n", pathname);
		free(pathname);
		token = strtok(NULL, ":");
		printf("token: %s\n", token);
	}


	return (NULL);
}

