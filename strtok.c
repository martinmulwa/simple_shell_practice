#include <stdio.h>
#include "strings.h"
/*#include <string.h>*/
/**
 * main - splits a string and returns an array of each word of the string
 *
 * Return: 0
 */
int main(void)
{
	int j, i = 0;
	char str[80] = "   - - - - - hello    world             goodbye       510-";
	char *delim = "";
	char *res;
	char *words[80];

	/* get first token */
	words[i++] = _strtok(str, delim);

	/* get all other tokens */
	while ((res = _strtok(NULL, delim)))
		words[i++] = res;

	printf("%s\n", str);

	/* print all tokens */
	for (j = 0; j < i; j++)
		printf("%s\n", words[j]);

	return (0);
}
