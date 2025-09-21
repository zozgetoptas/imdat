/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sorting_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:09:27 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/21 20:09:27 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_value(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	min = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_min_position(t_stack *stack_a)
{
	int		min_val;
	int		min_pos;
	int		current_pos;
	t_node	*current_node;

	if (!stack_a || !stack_a->top)
		return (-1);
	min_val = stack_a->top->value;
	min_pos = 0;
	current_pos = 0;
	current_node = stack_a->top->next;
	while (current_node)
	{
		current_pos++;
		if (current_node->value < min_val)
		{
			min_val = current_node->value;
			min_pos = current_pos;
		}
		current_node = current_node->next;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **stack_a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*stack_a);
	size = (*stack_a)->size;
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a);
	}
}
