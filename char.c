#include <stdio.h>
#include "monty.h"
#include "lists.h"




/**
 * pstr_handlerr - handles the pstr instruction
 *
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void pstr_handlerr(stackt_r **stack, unsigned int line_numb)
{
        stackt_r *node = *stack;

        (void)line_numb;

        if (!node)
        {
                putchar('\n');
                return;
        }

        while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
        {
                putchar(node->n);
                node = node->next;
        }

        putchar('\n');
}

/**
 * pchar_handlerr - handles the pchar instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 *
 */

void pchar_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *node = *stack;

	if (!node)
	{
		vprintf(STDERR_FILENO, PCHAR_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

