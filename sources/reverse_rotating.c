#include "../includes/push_swap.h"
#include <unistd.h>

void rra(t_stack **stack_a)
{
    if ((*stack_a) == NULL || (*stack_a)->size < 2)
        return;

    t_node *first;
    t_node *last;
    t_node *just_before_the_last;

    first = (*stack_a)->top;
    just_before_the_last = NULL;
    last = first;
    while (last->next != NULL)
    {
        just_before_the_last = last;
        last = last->next;
    }
    if (just_before_the_last != NULL)
        just_before_the_last->next = NULL;
    last->next = first;
    (*stack_a)->top = last;
    write(1, "rra\n", 4);
}