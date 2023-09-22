#include "monty.h"
#include "lists.h"


/**
 * pop_handlerr - handles the pop instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void pop_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * pint_handlerr - handles the pint instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */

void pint_handlerr(stackt_r **stack, unsigned int line_numb)
{
        stackt_r *head = *stack;

        if (!head)
        {
                dprintf(STDERR_FILENO, PINT_FAIL, line_numb);
                free_all(1);
                exit(EXIT_FAILURE);
        }

        printf("%d\n", head->n);
}


/**
 * swap_handlerr - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void swap_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *temp = *stack, *node = NULL;
	int numb;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	numb = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}



/**
 * nop_handlerr - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void nop_handlerr(stackt_r **stack, unsigned int line_numb)
{
        (void)stack;
        (void)line_numb;
}



/**
 * add_handlerr - handles the add instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void add_handlerr(stackt_r **stack, unsigned int line_numb)
{
	int sum = 0;
	stackt_r *node = NULL;
	stackt_r *node_0 = get_dnodeint_at_index(*stack, 0);
	stackt_r *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
