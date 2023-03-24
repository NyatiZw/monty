#include "monty.h"
/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	global_variable.lifo = 1;
}

/**
 * addqueue - add node to the the back of stack
 * @n: new value
 * @head: head of stack
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
		{
			aux = aux->next;
		}
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
