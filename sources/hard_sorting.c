/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:25 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:25 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	process_chunk(t_stack **sA, t_stack **sB, int curch, int chsize)
{
	int	i;
	int	initial_size;

	i = -1;
	initial_size = (*sA)->size;
	while (++i < initial_size)
	{
		if (chunk_index((*sA)->top->value, chsize) == curch)
		{
			pb(sA, sB);
			sort_and_push(sB);
		}
		else
		{
			ra(sA);
		}
	}
}

static void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	a_stack_size;
	int	max_bit_count;
	int	value;

	normalize_stack(a);
	max_bit_count = get_max_bits(*a);
	i = -1;
	while (++i < max_bit_count)
	{
		a_stack_size = (*a)->size;
		j = -1;
		while (++j < a_stack_size)
		{
			value = (*a)->top->value;
			if (((value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while ((*b) && (*b)->size > 0)
			pa(a, b);
	}
}

static void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	normalize_stack(stack_a);
	move_chunks_to_b(stack_a, stack_b, (*stack_a)->size);
	move_sorted_to_a(stack_a, stack_b);
}

void	sort_large_hybrid(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size < 450)
		chunk_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
