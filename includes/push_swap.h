/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:07:55 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:07:55 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// === PARSING & ERROR HANDLING ===
t_stack		*parse_arguments(char **argv);
long long	ft_atoll(const char *str);
void		handle_errors(char **argv);
void		error_exit(void);
int			valid_number_control(char *arg);
int			doubles_control(long long *args, int count);
int			integer_limits_control(long long nmbr);

// === STACK OPERATIONS ===
void		sa(t_stack **stack_a);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

// === SORTING ALGORITHMS ===
void		sort_two(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		sort_large_hybrid(t_stack **stack_a, t_stack **stack_b);

// === UTILITY FUNCTIONS ===
void		normalize_stack(t_stack **stack);
int			get_min_value(t_stack *stack);
int			find_min_position(t_stack *stack_a);
void		move_min_to_top(t_stack **stack_a);
void		move_value_to_top(t_stack **stack, int value);
int			get_optimal_rotate_direction(t_stack *stack, int value);

// === CHUNK SORT FUNCTIONS ===
int			get_chunk_size(int total_size);
int			chunk_index(int normalized_value, int chunk_size);
void		move_chunks_to_b(t_stack **sA, t_stack **sB, int totalSize);
void		move_sorted_to_a(t_stack **stack_a, t_stack **stack_b);
void		move_max_to_top_b(t_stack **stack_b);
void		process_chunk(t_stack **sA, t_stack **sB, int curch, int chsize);
void		sort_and_push(t_stack **sB);

#endif