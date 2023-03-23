#include "monty.h"

/**
 * get_opcodes - selects correct opcode to perform
 * @opc: opcode passed
 * Return: pointer to function to be executed
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc)  == 0)
		{
			break;
		}
	}

	return (instruct[i].f);
}
