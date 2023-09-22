#include "monty.h"
#include "lists.h"


/**
 * free_dbllinkdlst - frees a doubly linked list
 * @head: pointer to the list to free
 *
 */
void free_dbllinkdlst(dbllinkdlstt_r *head)
{
        dbllinkdlstt_r *temp;

        while (head)
        {
                temp = head->next;
                free(head);
                head = temp;
        }
}



/**
 * insert_dnodeint_at_index - insert  node at  given index in a doubly linked list 
 * @n: data to insert
 * @h: double pointer to the list
 * @idx: index of the node to insert
 * Return: address of the new node, or NULL if it failed
 */
dbllinkdlstt_r *insert_dnodeint_at_index(dbllinkdlstt_r **h, unsigned int idx, int n)
{
	unsigned int i;
	dbllinkdlstt_r *new;
	dbllinkdlstt_r *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dbllinkdlstt_r));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dbllinkdlstt_r *add_dnodeint_end(dbllinkdlstt_r **head, const int n)
{
	dbllinkdlstt_r *new;
	dbllinkdlstt_r *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dbllinkdlstt_r));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
