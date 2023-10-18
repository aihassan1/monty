#include "header.h"

/**
 * readf - function that read the file
 * @fp: the file -_-
 * @stack: pointer to the stack
 */
void readf(FILE *fp, stack_t **stack)
{
    unsigned int i = 1;
    size_t lin = 0;
    char *buffer = NULL;

    *stack = NULL;
    while (getline(&buffer, &lin, fp) != -1)
      {
	i++;
	linef(i, buffer, stack);
	free(buffer);
	buffer = NULL;
      }
}
