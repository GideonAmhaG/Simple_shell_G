#include "sshell.h"

/**
 * create_cmd - creates command that will be first element of execve
 * @cmd: first element of argv as typed
 *
 * Return: pointer to created command
 */
char *create_cmd(char *cmd)
{
	struct stat buf;
	char *token, *pathname, *path = getenv("PATH");

	token = strtok(path, ":");
	printf("token: %s\n", token);
	while (token)
	{
		pathname = malloc((strlen(token) + strlen(cmd) + 2)
				* sizeof(char));
		if (pathname == NULL)
		{
			free(pathname);
			return (NULL);
		}
		strcpy(pathname, token);
		printf("%s\n", pathname);
		strcat(pathname, "/");
		printf("%s\n", pathname);
		strcat(pathname, cmd);
		printf("%s\n", pathname);
		printf("token: %s\n", token);
		if (stat(pathname, &buf) == 0)
			return (pathname);
		//printf("%s\n", pathname);

		free(pathname);
		
		token = strtok(NULL, ":");
	}

	return (NULL);
}

int main(void)
{
	char *cmd = create_cmd("ls");

	printf("cmd: %s\n", cmd);
}
