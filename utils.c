/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:35:58 by ahetru            #+#    #+#             */
/*   Updated: 2024/11/25 13:35:59 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_argument(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	fill_stack_list(int *list, char **av, size_t len)
{
	size_t	i;

	i = 0;
	while (len > 0)
	{
		if (is_valid_argument(av[len]) == FAILURE)
		{
			return (FAILURE);
		}
		list[i] = ft_atoi(av[len]);
		len--;
		i++;
	}
	return (SUCCESS);
}

int	allocate_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (FAILURE);
	}
	(*stack)->list = NULL;
	return (SUCCESS);
}

static int	allocate_list(int **list, size_t len)
{
	*list = (int *)malloc(sizeof(int) * len);
	if (!*list)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	handle_memory_allocation(t_stack **stack_a, t_stack **stack_b, size_t len)
{
	if (allocate_stack(stack_a) == FAILURE)
	{
		return (FAILURE);
	}
	if (allocate_stack(stack_b) == FAILURE)
	{
		free(*stack_a);
		return (FAILURE);
	}
	if (allocate_list(&(*stack_a)->list, len) == FAILURE)
	{
		free(*stack_a);
		free(*stack_b);
		return (FAILURE);
	}
	if (allocate_list(&(*stack_b)->list, len) == FAILURE)
	{
		free((*stack_a)->list);
		free(*stack_a);
		free(*stack_b);
		return (FAILURE);
	}
	return (SUCCESS);
}
