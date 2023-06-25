#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	int n, m;

	if (!ops.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	for (m = 0; ops.arg[m] != '\0'; m++)
	{
		if (!isdigit(ops.arg[m]) && ops.arg[m] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_ops();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(ops.arg);

	if (ops.lifo == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}

/**
 * op_pall - prints all values on the stack
 * @stack: head of the linked list
 * @line_number: the line numbers in the file
 * Return: 0
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *arr;
	(void)line_number;

	arr = *stack;

	while (arr)
	{
		printf("%d\n", arr->n);
		arr = arr->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *arr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = *stack;
	*stack = (*stack)->next;
	free(arr);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int r;
	stack_t *arr = NULL;

	arr = *stack;

	for (r = 0; arr != NULL; arr = arr->next, r++)
		;

	if (r < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	arr = *stack;
	*stack = (*stack)->next;
	arr->next = (*stack)->next;
	arr->prev = *stack;
	(*stack)->next = arr;
	(*stack)->prev = NULL;
}
