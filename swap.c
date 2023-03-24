#include "monty.h"
/**
 * _swap - adds the top two elements of the stack
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: Can't swap, stack too small\n", counter);
		fclose(global_variable.file);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
