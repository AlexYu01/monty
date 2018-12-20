#include "monty.h"

/**
 * get_op - gets the operation from token
 * @tok: the operation
 * Return: a function pointer
 */

void (*get_op(char *tok))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{ "rotr", rotr},
		{ "rotl", rotl},
		{ "pchar", pchar},
		{ "pstr", pstr},
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap },
		{ "add", add },
		{ "sub", sub },
		{ "mul", mul },
		{ "div", _div },
		{ "mod", mod },
		{ "nop", nop },
		{ "stack", stack_set },
		{ "queue", queue_set },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, tok) == 0)
			return (ops[i].f);
	}
	return (NULL);
}

/**
 * proc_line - Parses the line for an opcode. If one is found, check if it is
 * a valid opcode, if so perform the operation.
 * If an error is encountered, prints a message and exits with EXIT_FAILURE.
 *
 * @buffer: The line to process.
 * @line_number: The line number of the current line in the file that is being
 * processed.
 * @stack: Double pointer to the beginning of the stack.
 *
 * Return: Void.
 */
void proc_line(char *buffer, unsigned int line_number, stack_t **stack)
{
	char *token;
	char *save_point;
	void (*f)(stack_t **stack, unsigned int line_number);

	token = strtok_r(buffer, " \t\n", &save_point);
	if (token != NULL && token[0] != '#')
	{
		f = get_op(token);
		if (f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, token);
			misc[ERROR_IDX] = 1;
			return;
		}
		if (f == push)
		{
			token = strtok_r(NULL, " \t\n", &save_point);
			if (token == NULL || check_num(token) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n",
						line_number);
				misc[ERROR_IDX] = 1;
				return;
			}
			misc[N_IDX] = atoi(token);
		}
		f(stack, line_number);
	}
}
