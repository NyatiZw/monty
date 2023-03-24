#include "monty.h"
/**
 * _pint - prints the top
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: Can't pint, stack is empty\n", counter);
		fclose(global_variable.fd);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
