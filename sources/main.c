#include "../includes/push_swap.h"
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

static int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top || stack->size <= 1)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}


static void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *temp;

    if (!stack)
        return;
    current = stack->top;
    while(current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    free(stack);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        return(0);
    handle_errors(argv);
    stack_a = parse_arguments(argv);
    stack_b = malloc(sizeof(t_stack));
    if (!stack_b)
        error_exit();
    stack_b->top = NULL;
    stack_b->size = 0;
    if (is_sorted(stack_a))
    {
        free_stack(stack_a);
        return(0);
    }
    if (stack_a->size <= 5)
	 	sort_small(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return(0);
}