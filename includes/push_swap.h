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

void		normalize_stack(t_stack **stack);
void		move_max_to_top_b(t_stack **stack_b);
int			get_chunk_size(int total_size);
int			chunk_index(int normalized_value, int chunk_size);
void		move_sorted_to_a(t_stack **stack_a, t_stack **stack_b);
void		move_chunks_to_b(t_stack **sA, t_stack **sB, int totalSize);
void		process_chunk(t_stack **sA, t_stack **sB, int curch, int chsize);
void		sort_and_push(t_stack **sB);
t_stack		*parse_arguments(char **argv);
long long	ft_atoll(const char *str);
int			valid_number_control(char *arg);
int			doubles_control(long long *args, int count);
int			integer_limits_control(long long nmbr);
void		sort_two(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		sort_four(t_stack **stack_a, t_stack **stack_b);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		handle_errors(char **argv);
void		error_exit(void);
void		sort_large_hybrid(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
int			get_optimal_rotate_direction(t_stack *stack, int value);
void		move_to_top_optimized(t_stack **stack, int value);
int			get_max_bits(t_stack *a);

#endif