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

#include "libft/libft.h"
#include "push_swap.h"

t_node  *init_node(int value)
{
    t_node  *node = malloc(sizeof(t_node));
    if (!node)
    {
        return (NULL);
    }
    node->value = value;
    node->next = NULL;
    return (node);
}

t_node	*last_node(t_node *node)
{
	if (node == NULL)
    {
		return (NULL);
    }
	while (node->next != NULL)
    {
		node = node->next;
    }
	return (node);
}

void	node_add_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

    if (!new_node)
    {
        ft_putstr_fd("Error\n", 2);
        return ;
    }
	if (*stack)
	{
		last = last_node(*stack);
		last -> next = new_node;
	}
	else
    {
		*stack= new_node;
    }
}

int is_num(char *value)
{
    size_t  i;

    i = 0;
    while(value[i])
    {
        if(ft_isdigit(value[i] == 0))
        {
            return (FAILURE);
        }
        i++;
    }
    return (SUCCESS);
}

int valid_arguments(char **av)
{
    size_t  i;

    i = 1;
    while(av[i])
    {
        if (is_num(av[i]) == FAILURE)
        {
            return (FAILURE);
        }
        i++;
    }
    return (SUCCESS);
}


void	del_node(t_node *node)
{
	if (node == NULL)
		return ;
	free (node);
}

void	clear_stack(t_node **stack)
{
	t_node  *current;
	t_node	*next_node;

	current = *stack;
	if (stack == NULL || *stack == NULL)
		return ;
	while (current != NULL)
	{
		next_node = current -> next;
		del_node(current);
		current = next_node;
	}
	*stack = NULL;
}

t_node *init_stack(int ac, char**av)
{
    t_node  *stack;
    t_node  *current_node;

    stack = NULL;
    if (valid_arguments(av) == FAILURE)
    {
        return (NULL);
    }
    while (ac > 1)
    {
        current_node = init_node(ft_atoi(av[ac - 1]));
        if (!current_node)
        {
            clear_stack(&stack);
            return (NULL);
        }
        ac--;
        node_add_back(&stack, current_node);
    }
    return (stack);
}

void    print_stack(t_node *node)
{
	while (node != NULL)
    {
        printf("%d\n", node->value);
		node = node->next;
    }
}

