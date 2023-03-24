#include "monty.h"
/**
 * _push - add node to the stack
 * @head: stack head
 * @number: line number
 * Return: void
 */
void _push(stack_t **head, unsigned int number)
{
	int n, j = 0, flag = 0;

	if (global_variable.arg)
	{
		if (global_variable.arg[0] == '-')
		{
			j++;
		}
		for (; global_variable.arg[j] != '\0'; j++)
		{
			if (global_variable.arg[j] > 57 || global_variable.arg[j] < 48)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: Usage: push integer\n", number);
			fclose(global_variable.fd);
			free(global_variable.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: Usage: push integer\n", number);
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

/**
 * _pall - prints the stack
 * @head: stack head
 * @number: integer
 * Return: void
 */
void _pall(stack_t **head, unsigned int number)
{
	stack_t *h;
	(void)number;

	h = *head;
	if (h == NULL)
	{
		return;
	}
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _pint - prints the top
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: Can't pint, stack is empty\n", number);
		fclose(global_variable.fd);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
