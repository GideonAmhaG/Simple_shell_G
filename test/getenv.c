#include <stdlib.h>
#include <stdio.h>

extern char **environ;
/**
 *_getenv - searches the environment list to find the environment variable
 * name
 * @envarname: environmental variable name to be searched
 *
 * Return: a pointer to the value in the environment, or NULL if there is no
 * match
 */
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

int main(void)
{
     char *s = _getenv("PATH");
	 char *s1 = getenv("PATH");
	 int i;

	 for (i = 0; i < 10; i++)
	 {
     	printf("%s\n", s);
     	printf("%s\n", s1);
	 }

	 return (0);
}
