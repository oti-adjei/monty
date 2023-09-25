#include "monty.h"
/**
* execute - Executes the opcode
*
* @stack: head linked list - stack
* @counter: line_counter
*
* @file: Poiner to monty file
* @content: line content
*
* Return: no return
*/

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_st}, {"pall", p_all_st}, {"pint", p_top_st},
				{"pop", pop_st},
				{"swap", swap_st},
				{"add", add_st},
				{"nop", nop_st},
				{"sub", sub_st},
				{"div", div_st},
				{"mul", multiply_st},
				{"mod", mod_st},
				{"pchar", pchar_st},
				{"pstr", pstr_st},
				{"rotl", rottop_st},
				{"rotr", rotbot_st},
				{"queue", f_queue},
				{"stack",f_stack},
				{NULL, NULL}
				};
	unsigned int index = 0;
	
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	
	bus.arg = strtok(NULL, " \n\t");

	while (opst[index].opcode && op)
	{
		if (strcmp(op, opst[index].opcode) == 0)
	
		{	opst[index].f(stack, counter);
			return (0);
		}
		
		index++;
	}
	
	if (op && opst[index].opcode == NULL)
	
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stackk(*stack);
		
		exit(EXIT_FAILURE); }
	return (1);
}
