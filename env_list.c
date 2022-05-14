#include "main.h"

/**
 * create_env - creates a list of environment variables
 * @env: array of environment variables
 *
 * Return: new head of list. Otherwise NULL
 */
list_t *create_env(char **env)
{
	unsigned int i;
	char *name, *value;

	if (env == NULL)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		name = _strtok(env[i], "=");
		value = _strtok(NULL, "\n");

		if (add_node_end(&env_list, name, value) == NULL)
			return (NULL);
	}

	return (env_list);
}

/**
 * print_env - prints all the environment variables
 */
void print_env(void)
{
	list_t *trav = env_list;
	/*unsigned int index = 0;*/

	while (trav != NULL)
	{
		printf("%s=", trav->name);
		printf("%s\n", trav->value);

		trav = trav->next;
	}
}

/**
 * _getenv - gets the value of an environment variable
 * @name: environment variable
 *
 * Return: value of name. Otherwise NULL
 */
char *_getenv(const char *name)
{
	list_t *trav = env_list;

	if (name == NULL)
		return (NULL);

	while (trav && _strcmp(trav->name, name)) /* check each node for a match */
		trav = trav->next;

	if (trav)
		return (trav->value);

	return (NULL);
}

/**
 * _setenv - changes or adds an environment variable
 * @name: name of environment variable
 * @value: value of environment variable
 * @overwrite: overwrite flag
 *
 * Return: 0 if successful. Otherwise -1
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int index;

	if (name == NULL || value == NULL || is_in_str(name, '='))
		return (-1);

	/* find index of node with name */
	index = find_name(env_list, name);

	/* if name not in list */
	if (index == -1)
	{
		if (add_node_end(&env_list, name, value) == NULL)
			return (-1);

		return (0);
	}

	/* update node at index */
	if (overwrite)
		return (update_value(env_list, index, value));

	return (0);
}

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name of variable to delete
 *
 * Return: 0 success. 1 otherwise
 */
int _unsetenv(const char *name)
{
	int index;

	if (name == NULL)
		return (-1);

	/* find index of node to delete */
	index = find_name(env_list, name);

	/* if name is not in the list */
	if (index == -1)
		return (0);

	/* delete node at index */
	if (delete_node_index(&env_list, index) == -1)
		return (-1);

	return (0);
}
