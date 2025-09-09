/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:54 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:54 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	ra(t_stack **stack_a)
{
	t_node	*first;
	t_node	*last;

	if ((*stack_a) == NULL || (*stack_a)->size < 2)
		return ;
	first = (*stack_a)->top;
	(*stack_a)->top = first->next;
	last = first;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_node	*first;
	t_node	*last;

	if ((*stack_b) == NULL || (*stack_b)->size < 2)
		return ;
	first = (*stack_b)->top;
	(*stack_b)->top = first->next;
	last = first;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}
