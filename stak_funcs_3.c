#include "monty.h"

/**
 * mul - Takes the top two elements of the stack and multiplies them. Result is
 * stored at the top of the stack. The stack will be one shorter than before.
 * If an error occurs, print a message to stderr and exit with EXIT_FAILURE.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of where the mul opcode is in the file.
 *
 * Return: Void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	res = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * mod - Takes the second element of the stack modulus it by the first element
 * of the stack. Result is stored at the top of the stack. The stack will be
 * one shorter than before. If an error occurs, print a message to stderr and
 * exit with EXIT_FAILURE.
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of where the mod opcode is in the file.
 *
 * Return: Void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	res = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * pchar - Treats the integer value at the top of the stack as an ascii and
 * prints the char equivalent.
 * If an error is encountered, prints a message and exits with EXIT_FAILURE.
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of where the pchar opcode is in the file.
 *
 * Return: Void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the integer values of a stack as ascii characters. Stops when
 * the stack is over, the value of the element is 0, or an invalid ascii value.
 * Prints a newline regardless.
 *
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of where the pstr opcode is in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int ascii;
	(void) line_number;

	if (stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			ascii = current->n;
			if (ascii != 0 && ascii > 0 && ascii <= 127)
				putchar(ascii);
			else
				break;
			current = current->next;
		}
	}
	putchar('\n');
}
