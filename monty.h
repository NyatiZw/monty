#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list reprresentation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global struct
 * @lifo: stack or queue
 * @cont: current line
 * arg: parameter
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 */
typedef struct global_s
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t global_variable; /* Declaration of variable */

/* opcode_instructions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* get_function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* more_functions */
int _strcmp(char *s1, char *s2);
int _search(char *s, char c);
char *_strtoky(char *s, char *d);

/* doubly linked list functions */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* freeing global variable */
void free_global_variable(void);

# endif /* _MONTY_H */
