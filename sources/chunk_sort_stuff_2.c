/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_stuff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:46:11 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 18:46:11 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_and_push(t_stack **sB)
{
	if ((*sB)->size > 1 && (*sB)->top->value < (*sB)->top->next->value)
		rb(sB);
}

void	move_chunks_to_b(t_stack **sA, t_stack **sB, int totalSize)
{
	int	curchunk;
	int	max_chunk;
	int	chunk_size;

	curchunk = -1;
	chunk_size = get_chunk_size(totalSize);
	max_chunk = (totalSize - 1) / chunk_size;
	while (++curchunk <= max_chunk && (*sA)->size > 0)
	{
		process_chunk(sA, sB, curchunk, chunk_size);
	}
}

void	move_sorted_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->size > 0)
	{
		move_max_to_top_b(stack_b);
		pa(stack_a, stack_b);
	}
}
