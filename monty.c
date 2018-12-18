#include "monty.h"

stack_t *stack = NULL;
void free_stack(stack_t *stack);

int main(int argc, char **argv)
{
	FILE *monty_file;
	ssize_t len;
	char *buffer = NULL;
	size_t n;
	unsigned int line_number= 0;

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
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		proc_line(buffer, line_number);
		free(buffer);
		buffer = NULL;
		len = getline(&buffer, &n, monty_file);
	}
	free(buffer);
	free_stack(stack);
	fclose(monty_file);
	return (0);
}

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
