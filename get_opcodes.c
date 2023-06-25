#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"queue", op_queue},
		{"stack", op_stack},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	int r;

	for (r = 0; instruct[r].opcode; r++)
	{
		if (_strcmp(instruct[r].opcode, opc) == 0)
			return (instruct[r].f);
	}
	return (NULL);
}
