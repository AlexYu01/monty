#include "monty.h"
/**
 * swap - swaps the top two elements
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	stack_t *next;
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	head = *stack;
	next = (*stack)->next;
	temp = head->n;
	head->n = next->n;
	next->n = temp;
}
/**
 * add - add the top two elements and pops the top and stores it in the new top
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void add(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	res = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = res;
}
/**
 * sub - subtract the top two elements and pops the top and stores it in
 * the new top
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	res = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * _div - divides the top two elements and pops the top and stores the
 * result in the new top.
 *
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	res = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * nop - does nothing
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
