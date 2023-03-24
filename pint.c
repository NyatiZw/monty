#include "monty.h"
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
