#ifndef _STRING_H
#define _STRING_H

#include <stdlib.h>

char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
int is_in_str(const char *str, char c);

#endif
