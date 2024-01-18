#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/*--- LIBRARIES ---*/
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>

/*--- MACROS ---*/
#define BUFF_SIZE 1024

/*--- GLOBAL VARIABLES ---*/
extern int global_push_value;

/*--- DATA STRUCTURES ---*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*--- UTILITY FUNCTIONS ---*/
char *get_instruction(char *s, unsigned int line_number);
FILE *open_monty_file(const char *filename);
void handle_args(int argc);
void execute(char *opcode, int line_number, stack_t **stack);
int initialize_global_value(int value);

/*--- STACK OPERATIONS ----*/
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);

#endif /* MONTY_H */
