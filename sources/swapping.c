/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:07:00 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:07:00 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void sa(t_stack **stack_a)
{
	t_node *first;
	t_node *second;
	if ((*stack_a) == NULL || (*stack_a)->size < 2)
		return;
	first = (*stack_a)->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack_a)->top = second;
    write(1, "sa\n", 3);
}
