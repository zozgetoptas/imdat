/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:45:31 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 16:45:31 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_bits(t_stack *a)
{
    int max_value;
    int max_bit_count;

    if (!a || !a->top)
        return (0);   
    max_value = a->size - 1;
    max_bit_count = 0;
    
    if (max_value == 0)
        return (1);
    while ((max_value >> max_bit_count) != 0)
        max_bit_count++;    
    return (max_bit_count);
}