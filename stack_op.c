#include "monty.h"
/**
 * Add node to the stack
 * @head: stack head
 *
 * @counter: line_number
 * Return: no return
*/

void push_st(stack_t **head, unsigned int counter)
{
	int nee, jee = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			jee++;
		for (; bus.arg[jee] != '\0'; jee++)
		{
			if (bus.arg[jee] > 57 || bus.arg[jee] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stackk(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE); }
	nee = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, nee);
	else
		addqueue(head, nee);
}


/**
  *f_rotl- Rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */

void rottop_st(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *tot_sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tot_sum = (*head)->next;
	tot_sum->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = tot_sum;
}

/**
  *Rotates the stack to the bottom
  
 *@head: Stack head
  *@counter: line_number
  *Return: no return
 */

void rotbot_st(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *dupli;

	dupli = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dupli->next)
	{
		dupli = dupli->next;
	}
	dupli->next = *head;
	dupli->prev->next = NULL;
	dupli->prev = NULL;
	(*head)->prev = dupli;
	(*head) = dupli;
}


/**
* Frees a doubly linked list
* @head: head of the stack
*
*/

void free_stackk(stack_t *head)
{
	stack_t *tot_sum;

	tot_sum = head;
	while (head)
	{
		tot_sum = head->next;
		free(head);
		head = tot_sum;
	}
}
