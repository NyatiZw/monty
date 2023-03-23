#include "monty.h"

global_t global_variable;

/**
 * free_global_variable - frees the global variable
 *
 * Return: void
 */
void free_global_variable(void)
{
	free_dlistint(global_variable.head);
	free(global_variable.buffer);
	fclose(global_variable.fd);
}

/**
 * start_global_variable - initiates the global variable
 *
 * @fd: file descriptor
 * Return: void
 */
void start_global_variable(FILE *fd)
{
	global_variable.lifo = 1;
	global_variable.cont = 1;
	global_variable.arg = NULL;
	global_variable.head = NULL;
	global_variable.fd = fd;
	global_variable.lifo = NULL;
}

/**
 * check_input - checks access to the file
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %S\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_global_variable(fd);
	nlines = getline(&global_variable.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtok(global_variable.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_variable.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_global_variable();
				exit(EXIT_FAILURE);
			}
			global_variable.arg = _strtok(NULL, " \t\n");
			f(&global_variable.head, global_variable.cont);
		}
		nlines = getline(&global_variable.buffer, &size, fd);
		global_variable.cont++;
	}

	free_global_variable();

	return (0);
}
