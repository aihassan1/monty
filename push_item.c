#include "monty.h"

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

