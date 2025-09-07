#include "../includes/push_swap.h"
#include <stdlib.h>

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
        while ((*b)->size > 0)
            pa(a, b);
            
        i++;
    }
}
