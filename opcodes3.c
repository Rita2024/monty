#include "monty.h"

/**
 * op_div - divides the second element by the top element of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	int x = 0;
	stack_t *arr = NULL;

	arr = *stack;

	for (; arr != NULL; arr = arr->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = (*stack)->next;
	arr->n /= (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_mul - multiplies the top element to the second top element of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	int x = 0;
	stack_t *arr = NULL;

	arr = *stack;

	for (; arr != NULL; arr = arr->next, x++)
		;

	if (x < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = (*stack)->next;
	arr->n *= (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	int t = 0;
	stack_t *arr = NULL;

	arr = *stack;

	for (; arr != NULL; arr = arr->next, t++)
		;

	if (t < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = (*stack)->next;
	arr->n %= (*stack)->n;
	op_pop(stack, line_number);
}
