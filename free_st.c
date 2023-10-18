#include "header.h"

void free_st(stack_t **stack)
{
    stack_t *tmp;

    do{
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }while (*stack);
}
