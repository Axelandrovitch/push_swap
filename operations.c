/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:31:25 by ahetru            #+#    #+#             */
/*   Updated: 2024/11/23 16:31:26 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_a(t_stack *stack)
{
    int tmp;

    tmp = stack->list[stack->top];
    stack->list[stack->top] = stack->list[stack->top - 1];
    stack->list[stack->top - 1] = stack->list[tmp];
}

void	swap_b(t_stack *stack)
{
    int tmp;

    tmp = stack->list[stack->top];
    stack->list[stack->top] = stack->list[stack->top - 1];
    stack->list[stack->top - 1] = stack->list[tmp];
}

void    swap_swap(t_stack *stack_a, t_stack *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_a()
