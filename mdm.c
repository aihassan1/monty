#include "monty.h"

/**
 * mood - division the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 */

void mood(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}

/**
 * diiv - division the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 */

void diiv(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}
/**
 * mul - multiplies the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}
