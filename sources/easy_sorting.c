#include "../includes/push_swap.h"

static void sort_two(t_stack **stack_a)
{
    if ((*stack_a)->top->value > (*stack_a)->top->next->value)
        sa(stack_a);
}

static void sort_three(t_stack **stack_a)
{
    int a = (*stack_a)->top->value;
    int b = (*stack_a)->top->next->value;
    int c = (*stack_a)->top->next->next->value;
    
    if (a < b && b < c)
        return;                    // 1 2 3
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);               // 3 1 2
        ra(stack_a);               //  1 2 3
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);              //  1 2 3
    else if (a > b && b < c && a < c)
        sa(stack_a);               // 1 2 3
    else if (a > b && b < c && a > c)
        ra(stack_a);               //  1 2 3
    else // a > b && b > c
    {
        sa(stack_a);               //  2 3 1
        rra(stack_a);              //  1 2 3
    }
}

// 4 element için
static void sort_four(t_stack **stack_a, t_stack **stack_b)
{
    int min_value = get_min_value(*stack_a);
    move_to_top_optimized(stack_a, min_value);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pa(stack_a, stack_b);
}

static void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int min_value = get_min_value(*stack_a);
    move_to_top_optimized(stack_a, min_value);
    pb(stack_a, stack_b);
    
    int second_min = get_min_value(*stack_a);
    move_to_top_optimized(stack_a, second_min);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size = (*stack_a)->size;
    
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
}
