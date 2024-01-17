#ifndef MONTY_H
#define MONTY_H

/*--- LIBRARIES ---*/
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*--- MACROS ---*/
#define BUFF_SIZE 1024

/*--- GLOBAL VARIABLES ---*/
extern stack;

/*--- MACROS ---*/
#define BUFF_SIZE 1024

/*--- GLOBAL VARIABLES ---*/


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

/**
 * struct operation_s - opcode and value
 * @opcode: the opcode
 * @value: the value
*/

typedef struct operation_s
{
	char *opcode;
	int value;
} operation_t;

/*--- UTILITY FUNCTIONS ---*/
void replace_newline_char(char *s);
operation_t get_instruction(char *s);
FILE *open_monty_file(const char *filename);
void handle_args(int argc);

/*--- STRING OPERATIONS ---*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/*--- STACK OPERATIONS ----*/
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
