#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

void real_push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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


void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	if (head->next)
		head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
