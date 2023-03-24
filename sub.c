#include "monty.h"
/**
 * _sub - subtraction
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
	{
		aux = aux->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: Can't sub, stack too small\n", counter);
		fclose(global_variable.fd);
		free(global_variable.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
