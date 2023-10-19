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
	while (p && p->next)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * pstr - prints string
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
