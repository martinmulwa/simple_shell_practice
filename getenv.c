#include "which.h"

/**
 * _getenv - gets value of an environment variable
 * @name: environment variable
 *
 * Return: return value of name. Otherwise NULL
 */
char *_getenv(const char *name)
{
	char *path;
	unsigned int i;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		path = get_path(environ[i], name);
		if (path)
			break;
	}

	return (path);
}

/**
 * get_path - checks if a given string is the environment variable
 * @str: string
 * @var: string representing environment variable
 *
 * Return: path string if str is PATH. NULL otherwise
 */
char *get_path(char *str, const char *var)
{
	char *path = NULL;

	if (_strcmp(var, strtok(str, "=")) == 0)
		path = strtok(NULL, "\n");

	return (path);
}
