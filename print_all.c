#include "monty.h"

/**
 * print_all - function that prints all the values
 * on the stack starting from the top
 * @stack: the stack -_-
 * @line_nu: unused stuff
 */
void print_all(stack_t **stack, unsigned int line_nu)
{
	stack_t *p;

	(void)line_nu;
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	p = *stack;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
