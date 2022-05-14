#include "main.h"

list_t *env_list = NULL;

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
	char *path;
	unsigned int i;
	list_t *path_list;

	if (ac < 2)
	{
		printf("Usage: _which filename ...\n");
		return (1);
	}

	/* create environ linked list */
	create_env(env);

	/* get value of PATH */
	path = _getenv("PATH");

	/* split path */
	path_list = split_string(path, ":");

	/* check if filename is in directories */
	for (i = 1; av[i]; i++)
		_which(av[i], path_list);

	free_list(&path_list);
	free_list(&env_list);

	return (0);
}

/**
 * _which - locates and prints a given command if it is in the PATH
 * @filename: string
 * @path_list: list of directories in PATH
 */
void _which(char *filename, list_t *path_list)
{
	char *full_path;

	if (filename == NULL)
		return;

	/* get full path of filename */
	full_path = get_full_path(filename, path_list);

	/* print full_path if filename is a valid command */
	if (full_path)
	{
		printf("%s\n", full_path);
		free(full_path);
	}
}


/**
 * get_full_path - checks if a given file is in PATH and returns its full path
 * @filename: filename as string
 * @path_list: list of the directories in PATH
 *
 * Return: full path of filename. Otherwise NULL
 */
char *get_full_path(char *filename, list_t *path_list)
{
	char *full_path;
	list_t *trav;

	if (filename == NULL || *filename == '\0')
		return (NULL);

	/* check if filename starts with . or / */
	if (filename[0] == '/' || filename[0] == '.')
	{
		if (is_command(filename))
			return (_strdup(filename));

		return (NULL);
	}

	/* check for filename in all the directories */
	for (trav = path_list; trav; trav = trav->next)
	{
		/* get fullpath */
		full_path = create_path(trav->name, filename);
		if (full_path)
		{
			if (is_command(full_path))
				return (full_path);

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

	/* allocate space for new string */
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

/**
 * is_command - checks if a given filename is a valid command
 * @filename: string
 *
 * Return: 1 if filename is valid command. 0 otherwise.
 */
int is_command(char *filename)
{
	struct stat sfile;

	if (filename == NULL)
		return (0);

	/* if file exists and can be executed */
	if (access(filename, X_OK) == 0)
	{
		stat(filename, &sfile);
		if (sfile.st_mode & S_IFREG) /* ensure it's a regular file */
			return (1);
	}

	return (0);
}
