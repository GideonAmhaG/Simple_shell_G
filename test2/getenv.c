#include "sshell.h"

/**
 * _getenv - get variable enviriomment
 * @key: key of envirionment variable eg. PATH, HOME
 * @env: envirionment variable
 * Return: char value envirionment
 **/
char *_getenv(char *key, char **env)
{
	char *tmp = NULL, *token = NULL, *envir = NULL, *current_env = NULL;
	int itr = 0;

	envir = _strdup(key);
	while (env[itr] && env)
	{
		current_env = NULL;
		token = NULL;
		current_env = _strdup(env[itr]);
		tmp = strtok(current_env, "=");
		token = _strdup(strtok(NULL, "="));
		if (_strcmp(envir, tmp) == 0)
		{
			break;
		}
		free(current_env);
		free(token);
		itr++;
	}
	free(current_env);
	current_env = NULL;
	free(envir);
	return (token);
}
