#include "header.h"
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
    instruction_t array[] = {
    {"pall", print_all},{"add", add},
    {"pint", pint},{"pop", pop}, {"swap", swap},
    {"nop", nop}, {NULL, NULL}};

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
	/* we may need to remove the next line */
	 free(buffer);
        exit(EXIT_FAILURE);
    }
}
