#include "monty.h"

/**
* pint - Print the value at the top of the stack.
* @stack: A pointer to the stack.
* @line_number: The line number of the instruction.
*/
void pint(stack_t **stack, unsigned int line_number)
{
int value;

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

value = (*stack)->n;
printf("%d\n", value);
}
