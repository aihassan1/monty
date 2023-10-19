#include "monty.h"

/**
 * linef - fun
 * @lin: l
 * @buffer: b
 * @stack: s
 */
void linef(unsigned int lin, char *buffer, stack_t **stack)
{
	int i;
	char *opcode, *value;
	instruction_t array[] = {
		{"pall", print_all}, {"add", add},
		{"pint", pint}, {"pop", pop}, {"swap", swap},
		{"nop", nop}, {"sub", sub}, {"div", diiv},
		{"mul", mul}, {"mod", mood}, {"pchar", pchar},
		{NULL, NULL}};

	opcode = strtok(buffer, "\n ");
	if (opcode == NULL || opcode[0] == '#')
		return;
	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, "\n ");
		if (value == NULL || (push_item(stack, value)) == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lin);
			free_st(stack);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		return;
	}
	for (i = 0; array[i].opcode != NULL; i++)
		if (strcmp(array[i].opcode, opcode) == 0)
		{
			array[i].f(stack, lin);
			return;
		}
	fprintf(stderr, "L%d: unknown instruction %s\n", lin, opcode);
	free_st(stack);
	/* we may need to remove the next line */
	free(buffer);
	exit(EXIT_FAILURE);
}
