#include "monty.h"



/**
 * multipy_st - Multiplies the 2nd with the top element of the stack.
 * @head: Stack head
 * @counter: line_number
 * Return: no return
*/


void multiply_st(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int lenth = 0, tot_sum;


	h = *head;
	while (h)

	{
	
		h = h->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
	
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tot_sum = h->next->n * h->n;

	h->next->n = tot_sum;
	*head = h->next;
	free(h);
}


/**
 *Adds top two elements of the stack.
 * @head: Stack head

 * @counter: line_number
 * Return: no return
*/

void add_st(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int lenth = 0, tot_sum;

	h = *head;
	while (h)
	{
		h = h->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tot_sum = h->n + h->next->n;
	h->next->n = tot_sum;

	*head = h->next;
	free(h);
}




/**
 * divides the 2nd  element by  top element of the stack.
 *
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void div_st(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int lenth = 0, tot_sum;

	h = *head;

	while (h)
	{
		h = h->next;
		lenth++;
	}
	if (lenth < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);

		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);

		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	tot_sum = h->next->n / h->n;

	h->next->n = tot_sum;

	*head = h->next;
	free(h);
}

/**
  *subtract the top element of the stack from 2nd element
  *@head: stack head
  *
  *@counter: line_number
  *Return: no return
 */

void sub_st(stack_t **head, unsigned int counter)
{
	stack_t *tot_sum;

	int ext, nodee;

	tot_sum = *head;

	for (nodee = 0; tot_sum != NULL; nodee++)
		tot_sum = tot_sum->next;
	if (nodee < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);

		fclose(bus.file);
		free(bus.content);

		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	tot_sum = *head;
	ext = tot_sum->next->n - tot_sum->n;
	tot_sum->next->n = ext;
	*head = tot_sum->next;
	free(tot_sum);
}

