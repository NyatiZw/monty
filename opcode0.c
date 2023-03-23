#include "monty.h"

/**
 * _push - push element to stack
 *
 * @doubly: linked list
 * @line_number: line number
 * Return: nothing
 */

void _push(stack_t **doubly, unsigned int line_number)
{
	int i, j;

	if (!global_variable.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_global_variable();
		exit(EXIT_FAILURE);
	}

	for (j = 0; (global_variable.arg[j]) != '\0'; j++)
	{
		if (!isdigit(global_variable.arg[j]) && global_variable.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_global_variable();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(global_variable.arg);

	if (global_variable.lifo == 1)
	{
		add_dnodeint(doubly, i);
	}
	else
	{
		add_dnodeint_end(doubly, i);
	}
}	
		
