#include "monty.h"
/**
 * _pop - prints the top
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(global_variable.fd);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
