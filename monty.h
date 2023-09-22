#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_list - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct stack_list
{
	int n;
	struct stack_list *prev;
	struct stack_list *next;
} stackt_r;

/**
 * struct ext_data_s - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct ext_data_s
{
        char *line;
        char **words;
        stackt_r *stack;
        FILE *fptr;
        int qflag;
} datat_r;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO ALX project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stackt_r **stack, unsigned int line_numb);
} instruction_t;

/**
 * struct args_struct - structure of arguments from main
 * @av: name of the file from the command line
 * @ac: number of arguments from main
 * @line_numb: number of the current line in the file
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_struct
{
	char *av;
	int ac;
	unsigned int line_numb;
} argst_r;
typedef stackt_r dbllinkdlstt_r;

extern datat_r data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't do pint, Empty stack\n"
#define POP_FAIL "L%u: can't do pop an empty stack\n"
#define SWAP_FAIL "L%u: can't do swap, short stack\n"
#define ADD_FAIL "L%u: can't do add, short stack\n"
#define SUB_FAIL "L%u: can't do sub, short stack\n"
#define DIV_FAIL "L%u: can't do div, short stack\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't do mul, short stack\n"
#define MOD_FAIL "L%u: can't do mod, short stack\n"
#define PCHAR_FAIL "L%u: can't do pchar, Empty stack\n"
#define PCHAR_RANGE "L%u: can't do  pchar, value out of range\n"

/* main.c */
void monty(argst_r *args);

/* handlerr_funcs2.c */
void sub_handlerr(stackt_r **stack, unsigned int line_numb);
void mul_handlerr(stackt_r **stack, unsigned int line_numb);
void mod_handlerr(stackt_r **stack, unsigned int line_numb);
void div_handlerr(stackt_r **stack, unsigned int line_numb);


/* get_func.c */
void (*get_func(char **parsed))(stackt_r **, unsigned int);
void pall_handlerr(stackt_r **stack, unsigned int line_numb);
void push_handlerr(stackt_r **stack, unsigned int line_numb);

/* handlerr_funcs3.c */
void rotl_handlerr(stackt_r **stack, unsigned int line_numb);
void rotr_handlerr(stackt_r **stack, unsigned int line_numb);
void stack_handlerr(stackt_r **stack, unsigned int line_numb);
void queue_handlerr(stackt_r **stack, unsigned int line_numb);


/* handlerr_funcs1.c */
void pint_handlerr(stackt_r **stack, unsigned int line_numb);
void pop_handlerr(stackt_r **stack, unsigned int line_numb);
void add_handlerr(stackt_r **stack, unsigned int line_numb);
void nop_handlerr(stackt_r **stack, unsigned int line_numb);
void swap_handlerr(stackt_r **stack, unsigned int line_numb);

/* char.c */
void pchar_handler(stackt_r **stack, unsigned int line_numb);
void pstr_handlerr(stackt_r **stack, unsigned int line_numb);

/* strtow.c */
int count_word(char *s);
void free_errthing(char **args);
char **strtow(char *str);

/* free.c */
void free_all(int all);

#endif
