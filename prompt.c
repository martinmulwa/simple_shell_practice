#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - prints user input
 *
 * Return: 0
 */
int main(void)
{
	size_t size = 10;
	char *buf;

	buf = malloc(sizeof(char) * size);

	printf("$ ");
	getline(&buf, &size, stdin);

	printf("%s", buf);

	free(buf);
	return (0);
}
