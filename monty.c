#include "monty.h"

stack_t *stack = NULL;
void push(stack_t **stack, unsigned int line_number);
void real_push(stack_t **stack, unsigned int line_number, char *n);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

int main(int argc, char **argv)
{
	FILE *monty_file;
	ssize_t len;
	char *buffer = NULL;
	char *token;
	char *save_point;
	size_t n;
	int i;
	int line_number= 0;
	instruction_t ops[] = {
		{ "push", push },
		{ "pall", pall },
		{ NULL, NULL }
	};

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
		token = strtok_r(buffer, " ", &save_point);
		if (token != NULL)
		{
			for (i = 0; ops[i].opcode != NULL; i++)
			{
				if (strcmp(ops[i].opcode, token) == 0)
				{
					if (ops[i].f == push)
					{
						token = strtok_r(NULL, " ", &save_point);
						real_push(&stack, line_number, token);
					}
					else
					{
						ops[i].f(&stack, line_number);
					}
				}
			}
		}
		free(buffer);
		buffer = NULL;
		len = getline(&buffer, &n, monty_file);
	}
	free(buffer);
	free_stack(stack);
	fclose(monty_file);
	return (0);
}

void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
void real_push(stack_t **stack, unsigned int line_number, char *n)
{
	(void) stack;
	(void) line_number;
	(void) n;
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Malloc fail\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = (*stack);
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
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
