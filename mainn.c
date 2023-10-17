#include "header.h"

/**
 * main - entry point
 * @argc: int
 * @argv: char *
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	FILE *fp;
	
	if (argc <= 1)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
	fp = fopen(argv[1], "r");
	if (argv[1] == NULL || fp == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
	stack = malloc(sizeof(stack_t));
        if (!stack)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
	readf(fp, &stack);
	free_st(&stack);
	fclose(fp);
	return 0;
}
/**
 * readf - function that read the file
 * @fp: the file -_-
 */
void readf(FILE *fp, stack_t **stack)
{
	unsigned int i;
	size_t lin = 0;
	char *buffer = NULL;

	*stack = NULL;
	for (i = 1; getline(&buffer, &lin, fp) != -1; i++)
		linef(i, buffer, stack);
	free(buffer);
}
/**
 * linef - fun
 * @lin: l
 * @buffer: b
 * @stack: s
 */
void linef(unsigned int lin, char *buffer, stack_t **stack)
{
	int i, j;
	char *opcode, *value;
	instruction_t array[] = {{"pall", print_all}, {"nop", nop}, {NULL, NULL}};

	j = 0;
	opcode = strtok(buffer, "\n ");
	if (opcode == NULL)
		return;
	if (strcmp(opcode, "push") == 0)
	{
		value = strtok(NULL, "\n ");
		push_item(stack, value);
		j = 1;
	};
	for (i = 0; array[i].opcode != NULL; i++)
	{
		if (strcmp(array[i].opcode, opcode) == 0)
		{
			array[i].f(stack, lin);
			j = 1;
		}
	}
	if (j == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lin, opcode);
		
		free_st(stack);
		free(buffer);
		exit(EXIT_FAILURE);
	}
}
/**
 */
void push_item(stack_t **stack, char *value)
{
	stack_t *new_node;
	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_st(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(value);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 */
void free_st(stack_t **stack)
{
	stack_t *tmp;

	do{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}while (*stack);
}

