#include "../includes/push_swap.h"
#include <unistd.h>

void ra(t_stack **stack_a)
{
    if ((*stack_a) == NULL || (*stack_a)->size < 2)
        return;

    t_node *first;
    t_node *last;

    first = (*stack_a)->top;
    (*stack_a)->top = first->next;

    last = first;
    while (last->next != NULL)
        last = last->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
    if ((*stack_b) == NULL || (*stack_b)->size < 2)
        return;

    t_node *first;
    t_node *last;

    first = (*stack_b)->top;
    (*stack_b)->top = first->next;

    last = first;
    while (last->next != NULL)
        last = last->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}