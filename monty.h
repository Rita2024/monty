#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define STACK_SIZE 1024
#define DELIMS " \n\t\a\b"

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
 * struct var_s - global structure to use in the functions
 * @lifo: is stack or queue
 * @currt: current line
 * @arg: second parameter inside the current line
 * @h: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 * Description: the doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct var_s
{
	int lifo;
	unsigned int currt;
	char  *arg;
	stack_t *h;
	FILE *fd;
	char *buffer;
} var_t;

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

extern var_t ops;
var_t ops;

void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptrs, unsigned int old_sizes, unsigned int new_sizes);
void *_calloc(unsigned int nmemb, unsigned int sizes);
int _strcmp(char *s1, char *s2);

stack_t *add_dnodeint_end(stack_t **h, const int n);
stack_t *add_dnodeint(stack_t **h, const int n);
void free_dlistint(stack_t *h);

void free_ops(void);
void start_ops(FILE *fd);

#endif
