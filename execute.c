#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list 
 * @counter: line_conter
 * @file: pointer to file
 * @content: line content
 * Return: void
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *fd)
{
	instruction_t opst[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}
	global_variable.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: Unknown Instruction %s\n", counter, op);
		fclose(fd);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
