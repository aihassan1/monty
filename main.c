#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fp;

	if (argc != 2)
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
	readf(fp, &stack);
	if (stack)
		free_st(&stack);
	fclose(fp);
	return (0);
}
