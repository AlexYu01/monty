#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *next;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	next = (*stack)->next;
	head->next = next->next;
	next->prev = head->prev;
	head->prev = next;
	next->next = head;
	head = next;
}
