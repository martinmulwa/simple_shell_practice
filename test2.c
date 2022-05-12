#include "_string.h"
#include <stdio.h>
#include <string.h>

/**
 * main - test string functions
 *
 * Return: 0 always
 */
int main(void)
{
	char *s1 = "hello";
	char *s2 = "hello";

	/* test _strcmp */
	if (_strcmp(s1, s2) == 0)
		printf("The strings %s and %s are similar\n", s1, s2);
	else
		printf("The strings %s and %s are NOT similar\n", s1, s2);

	return (0);
}
