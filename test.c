#include <stdio.h>
#include <stdlib.h>
#include "which.h"

/**
 * main - tests
 *
 * Return: 0 success. 1 otherwise
 */
int main(void)
{
	unsigned int i;
	char *name = "PATH";
	char *value = "/hello/world:/goodbye/world";

	printf("-------CURRENT ENV--------\n\n\n");

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	/* setenv */
	if (setenv(name, value, -1) == -1)
	{
		perror("Error\n");
		return (1);
	}

	printf("-------CURRENT ENV--------\n\n\n");

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (0);
}
