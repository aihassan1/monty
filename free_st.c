#include "monty.h"

/**
 * free_st - function that free the stack
 *
 * @stack: to free
 */

void free_st(stack_t **stack)
{
	stack_t *tmp;
	
	if (*stack == NULL)
		return;
	do {
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	} while (*stack);
}
