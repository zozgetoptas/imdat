/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:47 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:47 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	rra(t_stack **stack_a)
{
	t_node	*first;
	t_node	*last;
	t_node	*just_before_the_last;

	if ((*stack_a) == NULL || (*stack_a)->size < 2)
		return ;
	first = (*stack_a)->top;
	just_before_the_last = NULL;
	last = first;
	while (last->next != NULL)
	{
		just_before_the_last = last;
		last = last->next;
	}
	if (just_before_the_last != NULL)
		just_before_the_last->next = NULL;
	last->next = first;
	(*stack_a)->top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_node	*first;
	t_node	*last;
	t_node	*just_before_the_last;

	if ((*stack_b) == NULL || (*stack_b)->size < 2)
		return ;
	first = (*stack_b)->top;
	just_before_the_last = NULL;
	last = first;
	while (last->next != NULL)
	{
		just_before_the_last = last;
		last = last->next;
	}
	if (just_before_the_last != NULL)
		just_before_the_last->next = NULL;
	last->next = first;
	(*stack_b)->top = last;
	write(1, "rrb\n", 4);
}
