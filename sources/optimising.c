/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:34 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:34 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

static int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack || !stack->top)
		return (0);
	size = stack->size;
	return (size);
}

static int	get_position(t_stack *stack, int value)
{
	int		position;
	t_node	*current;

	position = 0;
	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
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
	int	reverse_moves;

	size = get_stack_size(*stack);
	pos = get_position(*stack, value);
	if (pos == -1)
		return ;
	direction = get_optimal_rotate_direction(*stack, value);
	if (direction == 1)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else if (direction == -1)
	{
		reverse_moves = size - pos;
		while (reverse_moves-- > 0)
			rra(stack);
	}
}
