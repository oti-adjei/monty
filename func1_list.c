#include "monty.h"

/**
 * dbllinkdlst_len - returns the number of nodes in a doubly linked list 
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t dbllinkdlst_len(const dbllinkdlstt_r *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dbllinkdlstt_r *add_dnodeint(dbllinkdlstt_r **head, const int n)
{
	dbllinkdlstt_r *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dbllinkdlstt_r));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_dbllinkdlst - prints a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_dbllinkdlst(const dbllinkdlstt_r *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
 * delete_dnodeint_at_index - deltes node in double-linked list at  given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */


int delete_dnodeint_at_index(dbllinkdlstt_r **head, unsigned int index)
{
	dbllinkdlstt_r *temp = *head;
	unsigned int indx = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		
		free(temp);
		return (1);
	}

	while (indx < index)
	{
		temp = temp->next;
		
		indx++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 * Return: address of the node, or if it does not exist, NULL
 */

dbllinkdlstt_r *get_dnodeint_at_index(dbllinkdlstt_r *head, unsigned int index)
{
	unsigned int indx = 0;

	if (!head)
		return (NULL);

	while (head && indx < index)
	{
		head = head->next;
		indx++;
	}

	return (head ? head : NULL);
}
