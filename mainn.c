#include "header.h"

/**
 * main - entry point
 * @argc: int
 * @argv: char *
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	FILE *fp;
	
	if (argc <= 1)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
	fp = fopen(argv[1], "r");
	if (argv[1] == NULL || fp == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
	stack = malloc(sizeof(stack_t));
        if (!stack)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
	readf(fp, &stack);
	free_st(&stack);
	fclose(fp);
	return 0;
}
