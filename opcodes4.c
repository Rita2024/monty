#include "monty.h"

/**
 * op_pchar - print the char value of the first element
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_ops();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * op_pstr - prints the string of the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *arr = (*stack)->next;
	(void)line_number;

	while (arr && arr->n != 0 && (arr->n > 0 && arr->n <= 127))
	{
		printf("%c", arr->n);
		arr = arr->next;
	}

	printf("\n");
}

/**
 * op_rotl - rotates the first element to the bottom and  the second to the top
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *arr1, *arr2;
	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	arr1 = (*stack)->next;
	arr2 = (*stack)->next;

	while (arr2->next != NULL)
		arr2 = arr2->next;

	arr1->next->prev = *stack;
	(*stack)->next = arr1->next;
	arr2->next = arr1;
	arr1->next = NULL;
	arr1->prev = arr2;
}

/**
 * op_rotr - reverse the stack
 * @stack: head of the linked list
 * @line_number: the line number in the file
 * Return: 0
 */

void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *arr = NULL;
	(void)line_number;

	if ((*stack)->next == NULL || *stack == NULL)
		return;

	arr = *stack;

	for (; arr->next != NULL; arr = arr->next)
		;

	arr->prev->next = NULL;
	arr->next = *stack;
	arr->prev = NULL;
	(*stack)->prev = arr;
	*stack = arr;
}
