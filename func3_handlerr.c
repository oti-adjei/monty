#include "monty.h"
#include "lists.h"

/**
 * rotl_handlerr - handles the rotl instruction
 *
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */


void rotl_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *temp = *stack;
	int numb  = 0;

	(void)line_numb;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	numb = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, numb);
}

/**
 *
 * queue_handlerr - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void queue_handlerr(stackt_r **stack, unsigned int line_numb)
{
        (void)stack;
        (void)line_numb;
        data.qflag = 1;
}



/**
 * rotr_handlerr - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void rotr_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *temp = *stack;
	int numb = 0, lenth = dlistint_len(*stack);

	(void)line_numb;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, lenth - 1);
	
	numb = temp->n;
	delete_dnodeint_at_index(stack, lenth - 1);
	add_dnodeint(stack, numb);
}

/**
 * stack_handlerr - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void stack_handlerr(stackt_r **stack, unsigned int line_numb)
{
	(void)stack;
	(void)line_numb;
	data.qflag = 0;
}
