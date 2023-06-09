#include "monty.h"

/**
 * execute - executes the opcode
 * @head: head linked list
 * @counter: line_conter
 * @fd: pointer to file
 * @content: line content
 * Return: void
 */
int execute(char *content, stack_t **head, unsigned int counter, FILE *fd)
{
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"stack", _stack},
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
			opst[i].f(head, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: Unknown Instruction %s\n", counter, op);
		fclose(fd);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
