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

#include "libft/libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node *stack_a;

    stack_a = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
    stack_a = init_stack(ac, av);
    if (!stack_a)
    {
		ft_putstr_fd("Error\n", 2);
		return (-1);
    }
    print_stack(stack_a);
    clear_stack(&stack_a);    
	return (0);
}
