#include "which.h"

/**
 * main - looks for files in the current PATH
 * @ac: number of commandline arguments
 * @av: array of commandline arguments
 * @env: array of environment variables
 *
 * Return: 0 success. 1 otherwise
 */
int main(int ac, char **av, char **env)
{
	char *path, *full_path = NULL;
	unsigned int i;
	list_t *dir_l = NULL;
	char **dir_a = NULL;

	if (ac < 2)
	{
		printf("Usage: _which filename ...\n");
		return (1);
	}

	/* create environ linked list */

	/* get PATH */
	for (i = 0; env[i] != NULL; i++)
	{
		path = get_path(env[i], "PATH");
		if (path)
			break;
	}

	/* split path */
	dir_l = split_string(path, ":");
	dir_a = list_to_array(dir_l);
	if (dir_l)
		free_list(dir_l);

	/* check if filename is in directories */
	for (i = 1; av[i]; i++)
	{
		full_path = get_full_path(av[i], dir_a);
		if (full_path)
		{
			printf("%s\n", full_path);
			free(full_path);
		}
	}

	/* free dir_a */
	for (i = 0; dir_a && dir_a[i]; i++)
		free(dir_a[i]);

	if (dir_a)
		free(dir_a);

	return (0);
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

/**
 * get_full_path - checks if a given file is in PATH and returns its full path
 * @filename: filename as string
 * @dir_a: array of the directories in PATH
 *
 * Return: full path of filename. Otherwise NULL
 */
char *get_full_path(char *filename, char **dir_a)
{
	unsigned int i;
	char *full_path;
	struct stat sfile;

	if (filename == NULL || *filename == '\0')
		return (NULL);

	if (filename[0] == '/' || filename[0] == '.')
	{
		if (access(filename, X_OK) == 0)
		{
			stat(filename, &sfile);
			if (sfile.st_mode & S_IFREG)
				return (_strdup(filename));
		}

		return (NULL);
	}

	for (i = 0; dir_a && dir_a[i]; i++)
	{
		/* get fullpath */
		full_path = create_path(dir_a[i], filename);
		if (full_path)
		{
			if (access(full_path, X_OK) == 0)
			{
				stat(full_path, &sfile);
				if (sfile.st_mode & S_IFREG)
					return (full_path);
			}
			free(full_path);
		}
	}
	return (NULL);
}

/**
 * create_path - concatenates directory name and filename to create full path
 * @dir: directory name
 * @filename: filename
 *
 * Return: new string representing full file path. Otherwise NULL
 */
char *create_path(char *dir, char *filename)
{
	unsigned int i, j, k, len_d, len_f;
	char *full_path;

	if (dir == NULL || filename == NULL)
		return (NULL);

	len_d = _strlen(dir);
	len_f = _strlen(filename);

	full_path = malloc(sizeof(char) * (len_d + len_f + 2));
	if (full_path == NULL)
		return (NULL);

	/* copy contents of dir */
	for (i = 0, k = 0; i < len_d; i++, k++)
		full_path[k] = dir[i];

	full_path[k++] = '/';

	/* copy contents of filename */
	for (j = 0; j < len_f; j++, k++)
		full_path[k] = filename[j];

	full_path[k] = '\0';

	return (full_path);
}
