#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sshell.h"

void _printenv(void);
char *_getenv(char *envarname);

int main(void)
{
	_printenv();

	return (0);
}

void _printenv(void)
{
	char *token, *path = _getenv("PATH"), *arr[100];
	int i;

	token = strtok(path, ":");
	for (i = 0; token != NULL; i++)
	{
		arr[i] = token;
		printf("%s\n", arr[i]);
		token = strtok(NULL, ":");
	}

}

char *_getenv(char *envarname)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;

	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = envarname;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);

		environ_cursor++;
	}
	return (NULL);
}	
