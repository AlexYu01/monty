#include "monty.h"

/**
 * push - fake push
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * real_push - The real push: pushes a node to a stack
 * @stack: a pointer to a pointer to the stack
 * @n: Pointer to string containing a number.
 */

void real_push(stack_t **stack, char *n)
{
	stack_t *new;
	stack_t *end;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (mode == STAK_MODE)
	{
		new->next = (*stack);
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new;
		}
		else
		{
			end = *stack;
			while (end->next != NULL)
				end = end->next;
			end->next = new;
			new->prev = end;
		}
	}
}

/**
 * pall - prints all elements in the stack
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void) line_number;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}


/**
 * pint - prints the top element in the stack
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pops the top element of a stack
 * @stack: a pointer to a pointer to the stack
 * @line_number: holds the line the code is run
 */

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
