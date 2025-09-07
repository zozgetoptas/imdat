#include "../includes/push_swap.h"



static void sort_two(t_stack **stack_a)
{
    if ((*stack_a)->top->value > (*stack_a)->top->next->value)
        sa(stack_a);
}

// 3 element için
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
    int min_pos = get_position(*stack_a, min_value);
    
    if (min_pos == 0)
        pb(stack_a, stack_b);
    else if (min_pos == 1)
    {
        sa(stack_a);
        pb(stack_a, stack_b);
    }
    else if (min_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
        pb(stack_a, stack_b);
    }
    else
    {
        rra(stack_a);
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
}

static void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int min_value = get_min_value(*stack_a);
    int min_pos = get_position(*stack_a, min_value);
    
    if (min_pos == 1)
        sa(stack_a);
    else if (min_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (min_pos == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if (min_pos == 4)
        rra(stack_a);
    pb(stack_a, stack_b);

    int second_min = get_min_value(*stack_a);
    int second_min_pos = get_position(*stack_a, second_min);
    
    if (second_min_pos == 1)
        sa(stack_a);
    else if (second_min_pos == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (second_min_pos == 3)
        rra(stack_a);
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
