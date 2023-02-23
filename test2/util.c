#include "sshell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: difference between the 2 strings
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcpy - copies a string
 * @dest: input string
 * @src: string to copy from
 *
 * Return: pointer to dest after src is in it
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i++] = '\0';

	return (dest);
}

/**
  * _strlen - returns string length
  * @s: input string
  *
  * Return: string length
  */

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcat - joins 2 strings
 * @dest: 1st string
 * @src: 2nd string
 *
 * Return: pointer to joined string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i++])
		j++;

	for (i = 0; src[i] != '\0'; i++)
		dest[i + j] = src[i];

	dest[i + j] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @src: src to copy from
 * Return: pointer to malloc'd space
 */

char *_strdup(char *src)
{
	int len, i;
	char *dest;

	if (src == NULL)
	return (NULL);
	len = _strlen(src);
	if (len < 0)
	return (NULL);
	len++;
	dest = malloc((len) * sizeof(char));
	if (dest == NULL)
	return (NULL);
	for (i = 0; i < len; i++)
	dest[i] = src[i];
	dest[i - 1] = '\0';
	return (dest);
}
