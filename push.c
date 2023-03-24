#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (global_variable.arg)
	{
		if (global_variable.arg[0] == '-')
		{
			j++;
		}
		for (; global_variable[j] != '\0'; j++)
		{
			if (global_variable.arg[j] > 57 || global_variable[j] < 48)
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", counter);
		fclose(global_variable.fd);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(global_variable.arg);
	if (global_variable.lifo == 0)
	{
		addnode(head, n);
	}
	else
	{
		addqueue(head, n);
	}
}
