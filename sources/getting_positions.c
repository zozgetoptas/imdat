/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:17 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:17 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_position(t_stack *stack, int value)
{
    int position = 0;
    t_node *current;
    if(!stack || !stack->top)
        return (-1);
    current = stack->top;
    while(current)
    {
        if (current->value == value)
            return position;
        current = current->next;
        position++;
    }
    return (-1);
}