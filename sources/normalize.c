/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:11:42 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 17:11:42 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

static void	cpy_stack_to_arr(t_stack *stack, int *sorted, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current && i < size)
	{
		sorted[i] = current->value;
		current = current->next;
		i++;
	}
}

static void	sort_array(int *arr, int size)
{
	int	outer_loop;
	int	inner_loop;
	int	temp;

	outer_loop = 0;
	while (outer_loop < size - 1)
	{
		inner_loop = 0;
		while (inner_loop < size - outer_loop - 1)
		{
			if (arr[inner_loop] > arr[inner_loop + 1])
			{
				temp = arr[inner_loop];
				arr[inner_loop] = arr[inner_loop + 1];
				arr[inner_loop + 1] = temp;
			}
			inner_loop++;
		}
		outer_loop++;
	}
}

static void	update_stack_values(t_stack *stack, int *sorted, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	normalize_stack(t_stack **stack)
{
	int	size;
	int	*sorted;

	if (!stack || !*stack || !(*stack)->top)
		return ;
	size = (*stack)->size;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(sorted);
		error_exit();
	}
	cpy_stack_to_arr(*stack, sorted, size);
	sort_array(sorted, size);
	update_stack_values(*stack, sorted, size);
	free(sorted);
}
