#include "../includes/push_swap.h"
#include <stdlib.h>

// buraya biraz kafa yormalıyım.. KULLANAMADIM FONKSİYONLARI

void push(t_stack *stack, int value)
{
    t_node *new_node;

    if (!stack)
        error_exit();
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        error_exit();
    
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
		return (0);

	if (pos <= size / 2)
		return (1);
	else
		return (-1);
}

void	move_to_top_optimized(t_stack **stack, int value)
{
	int	pos;
	int	size;
	int	direction;

	size = get_stack_size(*stack);
	pos = get_position(*stack, value);
	if (pos == -1)
		return;

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