#include "monty.h"
/**
 * _div - divides the top two elements of stack
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: Can't divide, too small\n", counter);
		fclose(global_variable.file);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(global_variable.file);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
