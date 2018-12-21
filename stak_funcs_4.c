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
	stack_t *last_ptr;
	stack_t *head;
	stack_t *next;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
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
	*stack = next;
}

/**
 * rotr - Rotates the stack to the bottom, the last element becomes the top
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of where the mul opcode is in the file.
 *
 * Return: Void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last_ptr;
	stack_t *head;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	last_ptr = *stack;
	head = *stack;
	while (last_ptr->next != NULL)
		last_ptr = last_ptr->next;
	head->prev = last_ptr;
	last_ptr->prev->next = NULL;
	last_ptr->next = head;
	last_ptr->prev = NULL;
	*stack = last_ptr;
}
/**
 * stack_set - Sets the format of the data to a stack. This is the default
 * behavior of the program. Anything pushed after the stack opcode will follow
 * the LIFO style.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of where the stack opcode is in the file.
 *
 * Return: Void.
 */
void stack_set(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	misc[MODE_IDX] = STAK_MODE;
}

/**
 * queue_set - Sets the format of the data to a queue. Anything pushed after
 * the queue opcode will follow the FIFO style.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of where the stack opcode is in the file.
 *
 * Return: Void.
 */
void queue_set(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	misc[MODE_IDX] = QUEU_MODE;
}
