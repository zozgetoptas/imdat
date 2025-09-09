/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:44:29 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 16:44:29 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_chunk_index(int normalized_value, int chunk_size)
{
    return (normalized_value / chunk_size);
}

int get_chunk_size(int total_size)
{
    if (total_size <= 50)
        return (total_size / 3);  // 3 chunk - daha agresif
    else if (total_size <= 100)
        return (total_size / 6);  // 6 chunk - daha küçük
    else
        return (total_size / 10); // 10 chunk - büyük sayılar için
}

static int get_max_position_in_b(t_stack *stack_b)
{
    t_node *current;
    int max_value;
    int max_pos;
    int current_pos;

    if (!stack_b || !stack_b->top)
        return (-1);
    current = stack_b->top;
    max_value = current->value;
    max_pos = 0;
    current_pos = 0;
    while (current)
    {
        if (current->value > max_value)
        {
            max_value = current->value;
            max_pos = current_pos;
        }
        current = current->next;
        current_pos++;
    }
    return (max_pos);
}

void move_max_to_top_b(t_stack **stack_b)
{
    int max_pos = get_max_position_in_b(*stack_b);
    if (max_pos == -1)
        return;
    
    int size = (*stack_b)->size;
    
    if (max_pos <= size / 2)
    {
        while (max_pos-- > 0)
            rb(stack_b);
    }
    else
    {
        int reverse_moves = size - max_pos;
        while (reverse_moves-- > 0)
            rrb(stack_b);
    }
}
