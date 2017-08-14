#include "monty.h"

/**
 * m_swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack_len < 2)
	{
		dprintf(STDERR_FILENO,
			"L%ud: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);
	(*stack)->prev->next = (*stack);
	(*stack)->prev->prev = NULL;
	(*stack) = (*stack)->prev;
}
