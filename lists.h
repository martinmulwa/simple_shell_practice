#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct list_s - singly linked list of values
 * @name: string
 * @value: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *name, const char *value);
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
list_t *create_node(const char *name, const char *value);
void free_node(list_t *h);
void free_list(list_t **head);
char **list_to_array(const list_t *h);
int delete_node_name(list_t **head, const char *name);
int delete_node_index(list_t **head, int index);
int find_name(list_t *h, const char *name);
int update_value(list_t *h, int index, const char *value);
list_t *split_string(char *str, char *delim);

/********* String functions **********/
char *_strcpy(char *dest, const char *src);
unsigned int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strtok(char *str, const char *delim);
int is_in_str(const char *str, char c);

#endif
