/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:59:09 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/31 18:15:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_printerror(char *str)
{
	ft_putstr_fd("Error: ", 2);	
	ft_putstr_fd(str, 2);	
	exit(0);
}

void	print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next)
	{
		ft_printf("Value: %d index: %d\n", aux->value, aux->index);
		aux = aux->next;
	}
	ft_printf("Value: %d index: %d\n", aux->value, aux->index);
}

void	node_addback(t_stack **stack, t_stack *node)
{
	if (node != 0)
	{
		if (*stack == 0)
		{
			*stack = node;
			(*stack)->next = NULL;
		}
		else
		{
			node_last(*stack)->next = node;
			node->prev = node_last(*stack);
		}
	}
}

t_stack	*node_last(t_stack *stack)
{
	if  (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*node_new(char *nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc (sizeof (t_stack));
	if (!new_node)
		ft_printerror("On Malloc.");
	new_node->value = ft_atoi(nbr);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
