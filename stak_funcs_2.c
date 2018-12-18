#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *next;
	int temp;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	next = (*stack)->next;
	temp = head->n;
	head->n = next->n;
	next->n = temp;
}
