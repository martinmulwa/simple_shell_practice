#include "main.h"

void print_sep(void);
int test_create_env(void);
void print_env_og(void);
void test_find_name(const char *name);
void test_update_value(int index, char *value);
void test_setenv(char *name, char *value, int overwrite);
void test_unsetenv(char *name);

list_t *env_list = NULL;

/**
 * main - test functions in env_list
 *
 * Return: 0 success. 1 otherwise
 */
int main(void)
{
	/*char *name = "HELLO";
	char *value = "goodbye";*/
	char str[80] = "   - - - - - hello    world             goodbye       510-";
	list_t *str_list;
	/*int index;*/

	/* create env_list */
	create_env(environ);

	/* find index */
	/*index = find_name(env_list, name);*/

	/* update node at index */
	/*test_update_value(index, value);*/

	/* setenv */
	/*test_setenv(name, value, 0);
	test_setenv("HI", "world", 0);
	test_setenv("!", "/bin/", 0);

	print_env();
	print_sep();

	test_unsetenv("SHELL");
	test_unsetenv("LS_COLORS");
	test_unsetenv("!");*/

	printf("%s\n", str);

	/* test split_string */
	str_list = split_string(str, "- ");
	print_list(str_list);

	printf("%s\n", str);

	free_list(&env_list);
	return (0);
}

/**
 * print_sep - prints separator
 */
void print_sep(void)
{
	int i, n;

	for (i = 0, n = 10; i < n; i++)
		printf("--------------------\n");
}

/**
 * test_create_env - tests the create_env function
 *
 * Return: 0 success. 1 otherwise
 */
int test_create_env(void)
{
	/*char *name = "HELLO";
	char *value = "blue";*/

	/* create env_list */
	if (create_env(environ) == NULL)
		return (1);

	/* print env_list */
	/*print_env();*/

	/* get value of name */
	/*printf("%s: %s\n", name, _getenv(name));*/

	/*_setenv(name, value, 0);
	_setenv("PATH", "goodbye", 1);
	_setenv("goodbye", "/bin/bash", 0);
	_setenv(name, "world", 1);*/

	/*setenv(name, value, 0);
	setenv("PATH", "goodbye", 1);
	setenv("goodbye", "/bin/bash", 0);
	setenv("goodbye", "/bin/bash", 1);*/

	/* get value of name */
	/*printf("%s: %s\n", name, _getenv(name));*/

	/*print_env_og();*/

	/* delete env_list */
	/* free_list(&env_list); */

	return (0);
}

/**
 * print_env_og - prints all the environment variables
 */
void print_env_og(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}

/**
 * test_find_name - tests find_name function
 * @name: name of node
 */
void test_find_name(const char *name)
{
	int index = find_name(env_list, name);

	if (index != -1)
		printf("%s is at index %d\n", name, index);
	else
		printf("%s is not in the list\n", name);
}

/**
 * test_update_value - tests the update_value function
 * @index: index of node to update
 * @value: new value
 */
void test_update_value(int index, char *value)
{
	if (update_value(env_list, index, value) == -1)
		printf("Update Failed!\n");
}

/**
 * test_setenv - tests _setenv function
 * @name: name of environment variable
 * @value: value of environment variable
 * @overwrite: overwrite flag
 *
 */
void test_setenv(char *name, char *value, int overwrite)
{
	if (_setenv(name, value, overwrite) == -1)
		printf("Setenv Failed!\n");
}

/**
 * test_unsetenv - tests _unsetenv function
 * @name: name of environment variable
 *
 */
void test_unsetenv(char *name)
{
	if (_unsetenv(name) == -1)
		printf("Unsetenv Failed!\n");
}
