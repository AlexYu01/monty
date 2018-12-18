#include "monty.h"

void proc_line(char *buffer, unsigned int line_number)
{
	char *token;
	char *save_point;
	void (*f)(stack_t **stack, unsigned int line_number);

	token = strtok_r(buffer, " ", &save_point);
	if (token != NULL)
	{
		f = get_op(token);
		if (f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, token);
			exit(EXIT_FAILURE);
		}
		if (f == push)
		{
			token = strtok_r(NULL, " ", &save_point);
			real_push(&stack, line_number, token);
		}
		else
		{
			f(&stack, line_number);
		}
	}
}

/**
 * get_op - gets the operation from token
 * @token: the operation
 * Return: a function pointer
 */

void (*get_op(char *tok))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "pop", pop },
		{ "swap", swap},
		{ "add", add},
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
