#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

char *prompt(void);
char *strip_newline(char *str);
void sig_handler(int sig);

char *buf;

/**
 * main - implements a super simple shell
 *
 * Return: 0 if successfull. 1 otherwise.
 */
int main(void)
{
	char *input;
	int status, child_pid;
	char *argv[2];

	argv[1] = NULL;

	/* handle SIGINT */
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		exit(98);

	while (1)
	{
		/* get input */
		input = prompt();
		if (input == NULL)
		{
			write(STDOUT_FILENO, "\n", 2);
			exit(0);
		}

		argv[0] = input;

		/* create process */
		child_pid = fork();
		if (child_pid == -1)
		{
			free(input);
			perror("fork Error!");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				free(input);
				perror("exec Error!");
				return (1);
			}
		}

		wait(&status);
		free(input);
	}

	return (0);
}

/**
 * prompt - gets input from user
 *
 * Return: string containing user input. Otherwise NULL
 */
char *prompt(void)
{
	size_t size = 10;

	/* allocate space for buf */
	buf = malloc(sizeof(char) * size);
	if (buf == NULL)
		return (NULL);

	printf("#cisfun$ ");

	/* get input */
	if (getline(&buf, &size, stdin) == -1)
	{
		free(buf);
		return (NULL);
	}

	/* remove newline and return */
	return (strip_newline(buf));
}

/**
 * strip_newline - removes newline character from a string
 * @str: string
 *
 * Return: string with newline character stripped
 */
char *strip_newline(char *str)
{
	int i;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}

	return (str);
}

/**
 * sig_handler - handles SIGINT
 * @sig: SIGINT
 */
void sig_handler(int sig)
{
	free(buf);
	(void)sig;
	write(STDOUT_FILENO, "\n", 2);
	exit(0);
}
