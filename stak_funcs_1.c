#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", *stack->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	head = *stack;
	if (head->next)
		head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
