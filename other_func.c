#include "monty.h"


/**
 * Adds the top two elements of the stack.
 *
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void swap_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;
	int lenth = 0, tot_sum;

	hee = *head;
	while (hee)
	{
		hee = hee->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		
		fclose(bus.file);
		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	hee = *head;
	tot_sum = hee->n;
	hee->n = hee->next->n;
	hee->next->n = tot_sum;
}

/**
  *f_nop- Does nothing
  *@head: stack head
  *
  *@counter: line_number
  *Return: no return
 */

void nop_st(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}


/**
 * addnode - add node to the head of stack
 * @head: head of the stack
 * @n: new_value
 *
 * Return: no return
*/

void addnode(stack_t **head, int n)
{

	stack_t *new_node, *tot_sum;

	tot_sum = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (tot_sum)
		tot_sum->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * Computes the rest of the division of the second top element of the stack by the top element of the stack
 * @head: Stack head
 *
 * @counter: line_number
 * Return: no return
*/

void mod_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;
	int lenth = 0, tot_sum;

	hee = *head;
	while (hee)
	{
		hee = hee->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	hee = *head;
	if (hee->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
	
		fclose(bus.file);
		free(bus.content);
		free_stackk(*head);

		exit(EXIT_FAILURE);
	}
	tot_sum = hee->next->n % hee->n;
	hee->next->n = tot_sum;
	*head = hee->next;
	free(hee);
}

/**
 * f_queue - Prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/


void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail of the stack
 * @n: new_value
 *
 * @head: head of the stack
 * Return: no return
*/

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *tot_sum;

	tot_sum = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tot_sum)
	{
		while (tot_sum->next)
			tot_sum = tot_sum->next;
	}
	if (!tot_sum)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tot_sum->next = new_node;
		new_node->prev = tot_sum;
	}
}


/**
 * f_stack - Prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
