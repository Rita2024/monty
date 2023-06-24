#include "monty.h"

/**
 * op_queue - sets the format of the data to a queue (FIFO)
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: no return
 */

void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	ops.lifo = 0;
}

/**
 * op_stack - sets the format fo the data to a stack (LIFO)
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: no return
 */

void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	ops.lifo = 1;
}

/**
 * op_add - adds the top two elements of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: no return
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	int x = 0;
	stack_t *arr = NULL;

	arr = *stack;

	for (; arr != NULL; arr = arr->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = (*stack)->next;
	arr->n += (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_nop - doesn't do anythinhg
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_sub - subtracts the top element to the second top element of the stack
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: 0
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	int r = 0;
	stack_t *arr = NULL;

	arr = *stack;

	for (; arr != NULL; arr = arr->next, r++)
		;

	if (r < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = (*stack)->next;
	arr->n -= (*stack)->n;
	op_pop(stack, line_number);
}
