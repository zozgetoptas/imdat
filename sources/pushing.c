/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:43 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:43 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*first_b;

	if (!(*stack_b) || !(*stack_b)->top)
		return ;
	first_b = (*stack_b)->top;
	(*stack_b)->top = first_b->next;
	first_b->next = (*stack_a)->top;
	(*stack_a)->top = first_b;
	(*stack_a)->size++;
	(*stack_b)->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*first_a;

	if (!(*stack_a) || !(*stack_a)->top)
		return ;
	first_a = (*stack_a)->top;
	(*stack_a)->top = first_a->next;
	first_a->next = (*stack_b)->top;
	(*stack_b)->top = first_a;
	(*stack_a)->size--;
	(*stack_b)->size++;
	write(1, "pb\n", 3);
}
