#include "monty.h"

void free_stack(stack_t *stack);
int misc[] = {0, 0, 0};

/**
 * main - Process Monty byte codes from a file passed in as an argument.
 *
 * @argc: The number of arguments passed to the program.
 * @argv: A double pointer containing the arguments passed.
 *
 * Return: EXIT_SUCCESS if no errors encountered..
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	char *buffer = NULL;
	ssize_t len;
	size_t n;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	misc[MODE_IDX] = STAK_MODE;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	len = getline(&buffer, &n, monty_file);
	while (len != -1)
	{
		line_number++;
		proc_line(buffer, line_number, &stack);
		free(buffer);
		buffer = NULL;
		if (misc[ERROR_IDX] != 0)
		{
			free_stack(stack);
			fclose(monty_file);
			exit(EXIT_FAILURE);
		}
		len = getline(&buffer, &n, monty_file);
	}
	free(buffer);
	free_stack(stack);
	fclose(monty_file);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees up the memory allocated for the stack.
 *
 * @stack: Pointer to the beginning of the stack.
 *
 * Return: Void.
 */
void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
