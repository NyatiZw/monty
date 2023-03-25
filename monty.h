#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
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
 * @arg: parameter
 * @fd: file descriptor
 * @content: input text
 *
 * Description: doubly linked list node structure
 */
typedef struct global_s
{
	int lifo;
	char *arg;
	FILE *fd;
	char *content;
} global_t;

extern global_t global_variable; /* Declaration of variable */

/* opcode_instructions */
void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void  _pint(stack_t **head, unsigned int number);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _rotl(stack_t **head, unsigned int counter);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

/* Handling memory */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void free_stack(stack_t *head);

/* more_functions */
int execute(char *content, stack_t **head, unsigned int counter, FILE *fd);

/* doubly linked list functions */
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);

/* freeing memory */
char *clean_line(char *content);

# endif /* _MONTY_H */
