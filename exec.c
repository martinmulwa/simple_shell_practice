#include <stdio.h>
#include <unistd.h>

/**
 * main - runs another program from the current program
 *
 * Return: 0
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};

	printf("Before execve\n");

	if (execve(argv[0], argv, NULL) == -1)
		perror("Error!\n");

	printf("After execve\n");

	return (0);
}
