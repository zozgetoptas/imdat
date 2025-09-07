#include "../includes/push_swap.h"
#include <stdlib.h>

void push(t_stack *stack, int value)
{
    t_node *new_node;
    
    // Check if the stack pointer is valid
    if (!stack)
        error_exit(); // Or handle this case appropriately based on your design

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        error_exit(); // Handle memory allocation failure
    
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}
static int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack || !stack->top)
		return (0);
	size = stack->size;
	return (size);
}

int	get_optimal_rotate_direction(t_stack *stack, int value)
{
	int	pos;
	int	size;

	size = get_stack_size(stack);
	pos = get_position(stack, value);
	if (pos == -1)
		return (0); // Value not found

	if (pos <= size / 2)
		return (1); // Top half: rotate up
	else
		return (-1); // Bottom half: reverse rotate down
}

void	move_to_top_optimized(t_stack **stack, int value)
{
	int	pos;
	int	size;
	int	direction;

	size = get_stack_size(*stack);
	pos = get_position(*stack, value);
	if (pos == -1)
		return; // Value not found

	direction = get_optimal_rotate_direction(*stack, value);
	if (direction == 1)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else if (direction == -1)
	{
		int reverse_moves = size - pos;
		while (reverse_moves-- > 0)
			rra(stack);
	}
}