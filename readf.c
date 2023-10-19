#include "monty.h"
/**
 * readf - function that read the file
 * @fp: the file -_-
 * @stack: null
 */
void readf(FILE *fp, stack_t **stack)
{
	unsigned int i;
	size_t lin = 0;
	char *buffer = NULL;

	for (i = 1; getline(&buffer, &lin, fp) != -1; i++)
		linef(i, buffer, stack);
	free(buffer);
}
