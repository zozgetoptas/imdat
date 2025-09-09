/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:39 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:39 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

static void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		error_exit();
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit();
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

static long long	get_overflow_value(int sign)
{
	if (sign == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

long long	ft_atoll(const char *str)
{
	int				sign;
	long long		res;
	int				i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (LLONG_MAX - (str[i] - '0')) / 10)
			return (get_overflow_value(sign));
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

t_stack	*parse_arguments(char **argv)
{
	int			total_args;
	t_stack		*stack_a;
	long long	nmbr;

	total_args = 1;
	while (argv[total_args])
		total_args++;
	total_args--;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		error_exit();
	stack_a->top = NULL;
	stack_a->size = 0;
	while (total_args >= 1)
	{
		nmbr = ft_atoll(argv[total_args]);
		push(stack_a, (int)nmbr);
		total_args--;
	}
	return (stack_a);
}
