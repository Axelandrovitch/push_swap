/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:28:25 by ahetru            #+#    #+#             */
/*   Updated: 2024/11/23 12:28:26 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
#ifndef	SUCCESS
# define SUCCESS 0
#endif
#ifndef	FAILURE
# define FAILURE 1
#endif

typedef struct stack
{
	int	*list;
	int	top;
}	t_stack;

int	fill_stack_list(int *list, char **av, size_t len);

int	handle_memory_allocation(t_stack **stack_a, t_stack **stack_b, size_t len);

#endif
