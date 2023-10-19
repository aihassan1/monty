#include "monty.h"

/**
 * push_item - function that add new item in stack
 * @stack: the stack
 * @value: value to add
 * Return: 0 or -1
 */
int push_item(stack_t **stack, char *value)
{
	int i;
	stack_t *new_node;

	if (value[0] == '-')
		i = 1;
	else
		i = 0;
	while (value[i] != '\0')
	{
		if (isdigit(value[i]) == 0)
			return (-1);
		i++;
	}
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
	return (0);
}
