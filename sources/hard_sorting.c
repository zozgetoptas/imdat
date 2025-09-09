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

void normalize_stack(t_stack **stack)
{
    if (!stack || !*stack || !(*stack)->top)
        return;
    int size = (*stack)->size;
    int *values = malloc(sizeof(int) * size);
    int *sorted = malloc(sizeof(int) * size);
    if (!values || !sorted)
    {
        free(values);
        free(sorted);
        error_exit();
    }
    t_node *current = (*stack)->top;
    int i = 0;
    while (current && i < size)
    {
        values[i] = current->value;
        sorted[i] = current->value;
        current = current->next;
        i++;
    }
    int outer_loop = 0;
    while (outer_loop < size - 1)
    {
        int inner_loop = 0;
        while (inner_loop < size - outer_loop - 1)
        {
            if (sorted[inner_loop] > sorted[inner_loop + 1])
            {
                int temp = sorted[inner_loop];
                sorted[inner_loop] = sorted[inner_loop + 1];
                sorted[inner_loop + 1] = temp;
            }
            inner_loop++;
        }
        outer_loop++;
    }
    current = (*stack)->top;
    while (current)
    {
        i = 0;
        while (i < size)
        {
            if (current->value == sorted[i])
            {
                current->value = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
    
    free(values);
    free(sorted);
}
int get_max_bits(t_stack *a)
{
    if (!a || !a->top)
        return 0;
        
    int max_value = a->size - 1;
    int max_bit_count = 0;
    
    if (max_value == 0)
        return 1;
        
    while ((max_value >> max_bit_count) != 0)
        max_bit_count++;
        
    return max_bit_count;
}

void radix_sort(t_stack **a, t_stack **b)
{
    normalize_stack(a);
    
    int max_bit_count = get_max_bits(*a);
    int i = 0;
    
    while (i < max_bit_count)
    {
        int a_stack_size = (*a)->size;
        int j = 0;
        
        while (j < a_stack_size)
        {
            int value = (*a)->top->value;
            if (((value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while ((*b) && (*b)->size > 0)
            pa(a, b);
        i++;
    }
}

static int get_chunk_size(int total_size)
{
    if (total_size <= 50)
        return (total_size / 3);  // 3 chunk - daha agresif
    else if (total_size <= 100)
        return (total_size / 6);  // 6 chunk - daha küçük
    else
        return (total_size / 10); // 10 chunk - büyük sayılar için
}

static int get_chunk_index(int normalized_value, int chunk_size)
{
    return normalized_value / chunk_size;
}

static int get_max_position_in_b(t_stack *stack_b)
{
    if (!stack_b || !stack_b->top)
        return -1;
    
    t_node *current = stack_b->top;
    int max_value = current->value;
    int max_pos = 0;
    int current_pos = 0;
    
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
    return max_pos;
}

static void move_max_to_top_b(t_stack **stack_b)
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

void chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
    normalize_stack(stack_a);
    
    int total_size = (*stack_a)->size;
    int chunk_size = get_chunk_size(total_size);
    if (chunk_size < 1)
        chunk_size = 1;
    
    int current_chunk = 0;
    int max_chunk = (total_size - 1) / chunk_size;
    
    // Phase 1: Stack A'dan chunk'ları Stack B'ye gönder
    while (current_chunk <= max_chunk && (*stack_a)->size > 0)
    {
        int initial_size = (*stack_a)->size;
        
        for (int i = 0; i < initial_size; i++)
        {
            int top_value = (*stack_a)->top->value;
            int value_chunk = get_chunk_index(top_value, chunk_size);
            
            if (value_chunk == current_chunk)
            {
                pb(stack_a, stack_b);
                
                if ((*stack_b)->size > 1 && 
                    (*stack_b)->top->value < (*stack_b)->top->next->value)
                    rb(stack_b);
            }
            else
            {
                ra(stack_a);
            }
            
            if ((*stack_a)->size == 0)
                break;
        }
        
        current_chunk++;
    }
    
    // Phase 2: Stack B'den Stack A'ya en büyükten küçüğe sırayla geri gönder
    while ((*stack_b)->size > 0)
    {
        move_max_to_top_b(stack_b);
        pa(stack_a, stack_b);
    }
}

void sort_large_chunk(t_stack **stack_a, t_stack **stack_b)
{
    chunk_sort(stack_a, stack_b);
}

void sort_large_radix(t_stack **stack_a, t_stack **stack_b)
{
    radix_sort(stack_a, stack_b);
}

// HYBRID APPROACH - İstersen bunu kullanabilirsin
void sort_large_hybrid(t_stack **stack_a, t_stack **stack_b)
{
    if ((*stack_a)->size <= 100)
        chunk_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}