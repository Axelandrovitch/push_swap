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
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
	int		i;

	len = ac - 1;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (-1);
	}
	stack_b = malloc(sizeof(t_stack));
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stack_a->list = (int *)malloc(sizeof(int) * (len));
	if (stack_a->list == NULL)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (-1);
	}
	i = 0;
	while (len > 0)
	{
		stack_a->list[i] = ft_atoi(av[len]);
		len--;
		i++;
	}
	for (int j = 0; j < ac - 1; j++) {
		printf("%d\n", stack_a->list[j]);
	}
	free(stack_a->list);
	free(stack_a);
	free(stack_b);
	return (0);
}
