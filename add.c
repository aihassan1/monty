#include "header.h"

/**
* add - Add the top two elements of the stack.
* @stack: A pointer to the stack.
* @line_number: The line number of the instruction.
*/

void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
int result;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

result = (*stack)->n + (*stack)->next->n;
(*stack)->next->n = result;
(*stack) = (*stack)->next;

free(temp);
}
