#include "header.h"

/**
* pop - Remove the top element from the stack.
* @stack: A pointer to the stack.
* @line_number: The line number of the instruction.
*/

void pop(stack_t **stack, unsigned int line_number)
{

stack_t *temp = *stack;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

*stack = (*stack)->next;

free(temp);
}
