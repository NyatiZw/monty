#include "monty.h"
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
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
