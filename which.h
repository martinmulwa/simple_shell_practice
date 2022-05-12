#ifndef WHICH_H
#define WHICH_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>

extern char **environ;

/********** String Functions ************/

char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);

/********** List Functions ************/

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
void free_list(list_t *head);
char **list_to_array(list_t *head);

/********** Which Functions ************/

char *get_path(char *str, const char *var);
list_t *split_string(char *str, char *delim);
char *get_full_path(char *filename, char **dir_a);
char *create_path(char *dir, char *filename);
char *_getenv(const char *name);

#endif
