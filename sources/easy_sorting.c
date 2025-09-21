/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:05:36 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:05:36 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min_value(t_stack *stack)
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

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->top->value > (*stack_a)->top->next->value)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->top->value;
	b = (*stack_a)->top->next->value;
	c = (*stack_a)->top->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}
static int	find_min_position(t_stack *stack_a)
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
// En küçük elemanı en üste getir
static void	move_min_to_top(t_stack **stack_a)
{
	int	min_pos = find_min_position(*stack_a);
	int	size = (*stack_a)->size;

	// Üst yarıda ise ra, alt yarıda ise rra kullan
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

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	// En küçük elemanı bul ve stack_b'ye taşı
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	
	// Kalan 3'ü sırala
	sort_three(stack_a);
	
	// En küçüğü geri al
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_value;
	int	second_min;

	min_value = get_min_value(*stack_a);
	move_to_top_optimized(stack_a, min_value);
	pb(stack_a, stack_b);
	second_min = get_min_value(*stack_a);
	move_to_top_optimized(stack_a, second_min);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
