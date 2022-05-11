#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - runs another program from the current program
 *
 * Return: 0
 */
int main(void)
{
	int i, status, child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error!\n");
		}
		else if (child_pid == -1)
		{
			perror("Error:");
        	return (1);
		}

		wait(&status);
	}

	return (0);
}
