/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:22 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:22 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_min_value(t_stack *stack)
{
    t_node *current;
    int min;

    if(!stack || !stack->top)
        return 0;
    min = stack->top->value;
    current = stack->top->next;
    while(current)
    {
        if(current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}