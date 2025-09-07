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
    return min;
}