#include "monty.h"

/**
 * add_dnodeint_end - add node to end of doubly linked list
 * @head: first position of linked list
 * @n: data to store
 * Return: a doubly linked list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *aux;

	if (head == NULL)
	{
		return (NULL);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_variable();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
	{
		aux = aux->next;
	}
	tmp->next = aux->next;
	tmp->prev = aux;
	aux->next = tmp;
	return (aux->next);
}

/**
 * add_dnodeint - add a node to start of doubly linked list
 * @head: head pointer
 * @n: data
 * Return: doubly linked list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return (NULL);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_variable();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = next;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlistint - frees doubly linked list
 * @head: pointer to head of list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while ((temp == head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
