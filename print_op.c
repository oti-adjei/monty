#include "monty.h"


/**
 * function that prints the stack
 *
 * @head: stack head
 * @counter: not used
 *
 * Return: no return
*/

void p_all_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;
	(void)counter;

	hee = *head;
	if (hee == NULL)
		return;
	while (hee)
	{
		printf("%d\n", hee->n);
		hee = hee->next;
	}
}


/**
 * function that prints the top of stack
 * @head: stack head
 *
 * @counter: line_number
 *
 * Return: no return
*/

void p_top_st(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);

		free(bus.content);
		
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	
	printf("%d\n", (*head)->n);
}


/**
 * pop - prints the top of stack
 *
 * @head: stack head
 * @counter: line_number
 * Return: no return
 *
*/

void pop_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	hee = *head;
	*head = hee->next;
	free(hee);
}


/**
 * pstr_st - Prints the string starting from the top of the stack,
 *
 * @head: Stack head
 * @counter: line_number
 *
 * Return: no return
*/

void pstr_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;
	(void)counter;

	hee = *head;
	while (hee)
	{
		if (hee->n > 127 || hee->n <= 0)
		{
			break;
		}
		printf("%c", hee->n);
		hee = hee->next;
	}
	printf("\n");
}

/**
 * pchar_st - Prints the char at the top of the stack,
 *
 * @head: Stack head
 * @counter: line_number
 * Return: no return
*/

void pchar_st(stack_t **head, unsigned int counter)
{
	stack_t *hee;

	hee = *head;


	if (!hee)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		
		free(bus.content);
		free_stackk(*head);
		
		exit(EXIT_FAILURE);
	}
	if (hee->n > 127 || hee->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		
		fclose(bus.file);
		free(bus.content);
		
		free_stackk(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hee->n);
}
