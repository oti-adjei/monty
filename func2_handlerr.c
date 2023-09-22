#include "monty.h"
#include "lists.h"


/**
 * mod_handlerr - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void mod_handlerr(stackt_r **stack, unsigned int line_numb)
{
        int mod = 0;
        stackt_r *node = NULL;
        stackt_r *node_0 = get_dnodeint_at_index(*stack, 0);
        stackt_r *node_1 = get_dnodeint_at_index(*stack, 1);

        if (dlistint_len(*stack) < 2)
        {
                dprintf(STDERR_FILENO, MOD_FAIL, line_numb);
                free_all(1);
                exit(EXIT_FAILURE);
        }

        if (node_0->n == 0)
        {
                dprintf(STDERR_FILENO, DIV_ZERO, line_numb);
                free_all(1);
                exit(EXIT_FAILURE);
        }

        mod = node_1->n % node_0->n;
        delete_dnodeint_at_index(stack, 0);
        delete_dnodeint_at_index(stack, 0);
        node = add_dnodeint(stack, mod);
        if (!node)
        {
                dprintf(STDERR_FILENO, MALLOC_FAIL);
                free_all(1);
                exit(EXIT_FAILURE);
        }
}


/**
 * sub_handlerr - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */

void sub_handlerr(stackt_r **stack, unsigned int line_numb)
{
	int sub = 0;
	stackt_r *node = NULL;
	stackt_r *node_0 = get_dnodeint_at_index(*stack, 0);
	stackt_r *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}


/**
 * mul_handlerr - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void mul_handlerr(stackt_r **stack, unsigned int line_numb)
{
	int mul = 0;
	stackt_r *node = NULL;
	stackt_r *node_0 = get_dnodeint_at_index(*stack, 0);
	stackt_r *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

	/**
 * div_handlerr - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void div_handlerr(stackt_r **stack, unsigned int line_numb)
{
        int div = 0;
        stackt_r *node = NULL;
        stackt_r *node_0 = get_dnodeint_at_index(*stack, 0);
        stackt_r *node_1 = get_dnodeint_at_index(*stack, 1);

        if (dlistint_len(*stack) < 2)
        {
                dprintf(STDERR_FILENO, DIV_FAIL, line_numb);
                free_all(1);
                exit(EXIT_FAILURE);
        }

        if (node_0->n == 0)
        {
                dprintf(STDERR_FILENO, DIV_ZERO, line_numb);
                free_all(1);
                exit(EXIT_FAILURE);
        }

        div = node_1->n / node_0->n;
        delete_dnodeint_at_index(stack, 0);
        delete_dnodeint_at_index(stack, 0);
        node = add_dnodeint(stack, div);
        if (!node)
        {
                dprintf(STDERR_FILENO, MALLOC_FAIL);
                free_all(1);
                exit(EXIT_FAILURE);
        }
}
