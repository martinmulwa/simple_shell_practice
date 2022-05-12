#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the address of the first node
 * @str: the value of the str field of the new node
 *
 * Return: head of the new list. Otherwise NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *trav, *new;

	if (head == NULL)
		return (NULL);

	trav = *head;

	/* create the new node */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = (str == NULL) ? _strdup("(nil)") : _strdup(str);
	new->len = (str == NULL) ? 0 : _strlen(str);
	new->next = NULL;

	/* if the list has no elements */
	if (trav == NULL)
	{
		*head = new;
		return (*head);
	}

	/* traverse to the end of the list */
	while (trav->next != NULL)
		trav = trav->next;

	trav->next = new;

	return (*head);
}

/**
 * list_len - finds the number of elements in a linked list_t list
 * @h: pointer to a list_t
 *
 * Return: number of elements in the list_t
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}

/**
 * print_list - prints all the elements of a list_t list in a given format
 * @h: pointer to a list_t
 * If str is NULL, print [0] (nil)
 *
 * Return: number of nodes in given list_t
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		count++;
		h = h->next;
	}

	return (count);
}

/**
 * free_list - frees a list_t list
 * @head: pointer to list_t
 */
void free_list(list_t *head)
{
	if (head == NULL)
		return;

	free_list(head->next);
	free(head->str);
	free(head);
}

/**
 * list_to_array - converts a given linked list into an array of strings
 * @head: head of given list
 *
 * Return: an array of strings. Otherwise NULL
 */
char **list_to_array(list_t *head)
{
	char **array;
	unsigned int i, length;

	if (head == NULL)
		return (NULL);

	/* allocate space for array */
	length = list_len(head);
	array = malloc(sizeof(char *) * (length + 1));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < length && head; i++, head = head->next)
		array[i] = _strdup(head->str);

	array[length] = NULL;
	
	return (array);
}
