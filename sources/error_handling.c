/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztoptas <ztoptas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:06:14 by ztoptas           #+#    #+#             */
/*   Updated: 2025/09/09 13:06:14 by ztoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

static int count_arguments(char **argv)
{
    int i = 1;
    while (argv[i])
        i++;
    return (i - 1);
}
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void handle_errors(char **argv)
{
    int count;
    int i;
    long long *args_ll;

	count = count_arguments(argv);
	args_ll = malloc(sizeof(long long) * count);
    if (!args_ll)
		error_exit();
	i = 1;
    while (argv[i])
    {
        if (valid_number_control(argv[i]))
        {
            free(args_ll);
            error_exit();
        }
        args_ll[i - 1] = ft_atoll(argv[i]);
        if (integer_limits_control(args_ll[i - 1]))
        {
            free(args_ll);
            error_exit();
        }
        i++;
    }
    if (doubles_control(args_ll, count))
    {
        free(args_ll);
        error_exit();
    }    
    free(args_ll);
}

