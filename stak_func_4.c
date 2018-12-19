#include "monty.h"

/**
 * rotl - Rotates the stack to the top, the to element becomes the bottom and
 * the second element becomes the first one
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of where the mul opcode is in the file.
 *
 * Return: Void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *last_ptr;
	stack_t *head;
	stack_t *next;


	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
		return;
	last_ptr = *stack;
	head = *stack;
	next = head->next;
	while (last_ptr->next != NULL)
		last_ptr = last_ptr->next;
	next->prev = NULL;
	last_ptr->next = head;
	head->next = NULL;
	head->prev = last_ptr;
	head = next;
}