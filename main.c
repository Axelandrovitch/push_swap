/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:58:55 by ahetru            #+#    #+#             */
/*   Updated: 2024/11/23 13:58:57 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a = {0};
	t_stack	*stack_b = {0};

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (handle_memory_allocation(&stack_a, &stack_b, ac - 1) == FAILURE)
	{
		return (-1);
	}
	if (fill_stack_list(stack_a->list, av, ac - 1) == FAILURE)
	{
		free(stack_a->list);
		free(stack_b->list);
		free(stack_a);
		free(stack_b);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	for (int j = 0; j < ac - 1; j++) {
		printf("%d\n", stack_a->list[j]);
	}
	free(stack_a->list);
	free(stack_b->list);
	free(stack_a);
	free(stack_b);
	return (0);
}
