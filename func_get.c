#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the right function 
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stackt_r **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handlerr},
		{"pall", pall_handlerr},
		{"pint", pint_handlerr},
		{"pop", pop_handlerr},
		{"swap", swap_handlerr},
		{"add", add_handlerr},
		{"nop", nop_handlerr},
		{"sub", sub_handlerr},
		{"div", div_handlerr},
		{"mul", mul_handlerr},
		{"mod", mod_handlerr},
		{"pchar", pchar_handlerr},
		{"pstr", pstr_handlerr},
		{"rotl", rotl_handlerr},
		{"rotr", rotr_handlerr},
		{"stack", stack_handlerr},
		{"queue", queue_handlerr},
		{NULL, NULL}
	};

	int codes = 17, index;

	for (index = 0; index < codes; index++)
	{
		if (strcmp(func_arr[index].opcode, parsed[0]) == 0)
		{
			return (func_arr[index].f);
		}
	}
	return (NULL);
}

/**
 * push_handlerr - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void push_handlerr(stackt_r **stack, unsigned int line_numb)
{
	stackt_r *new;
	int numb = 0, index;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_numb);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (index = 0; data.words[1][index]; index++)
	{
		if (isalpha(data.words[1][index]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_numb);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	numb = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, numb);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, numb);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handlerr - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_numb: number of the line in the file
 */
void pall_handlerr(stackt_r **stack, unsigned int line_numb)
{
	(void)line_numb;
	if (*stack)
		print_dlistint(*stack);
}
