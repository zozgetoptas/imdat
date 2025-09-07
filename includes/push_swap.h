#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// parsing functions
t_stack *parse_arguments(char **argv);
long long	ft_atoll(const char *str);

// arg_checks functions
int valid_number_control(char *arg);
int doubles_control(long long *args, int count);
int integer_limits_control(long long nmbr);

// easy_sorting functions
void sort_small(t_stack **stack_a, t_stack **stack_b);

// swapping functions
void sa(t_stack **stack_a);

// handle_errors functions
void handle_errors(char **argv);
void error_exit(void);

// hard_sorting functions
int get_max_bits(t_stack *a);
void radix_sort(t_stack **a, t_stack **b);
void normalize_stack(t_stack **stack);

// pushing functions
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

// rotating functions
void ra(t_stack **stack_a);

// reverse_rotating functions
void rra(t_stack **stack_a);

// getting_positions functions
int get_position(t_stack *stack, int value);

// getting_values functions
int get_min_value(t_stack *stack);

// optimising functions
void push(t_stack *stack, int value);
int	get_optimal_rotate_direction(t_stack *stack, int value);
void	move_to_top_optimized(t_stack **stack, int value);

#endif