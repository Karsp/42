/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:14:51 by daviles-          #+#    #+#             */
/*   Updated: 2024/03/03 00:39:47 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ft_b_rx(t_stack **stack, char x)
{
	t_stack	*node_1;
	t_stack	*node_lst;

	if (*stack == NULL)
		return ;
	node_1 = *stack;
	node_lst = node_last(*stack);
	*stack = (*stack)->next;
	node_lst->next = node_1;
	node_1->next = NULL;
	if (x == 'a')
		return ;
	if (x == 'b')
		return ;
}

void	ft_b_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	ft_b_rx(stack_a, 'x');
	ft_b_rx(stack_b, 'x');
}

void	ft_b_rrx(t_stack **stack, char x)
{
	t_stack	*node_lst;
	t_stack	*node_pnult;
	t_stack	*aux;

	if (*stack == NULL)
		return ;
	aux = *stack;
	while (aux->next)
	{
		if ((aux->next)->next == NULL)
			node_pnult = aux;
		aux = aux->next;
	}
	node_lst = aux;
	node_lst->next = *stack;
	*stack = node_lst;
	node_pnult->next = NULL;
	if (x == 'a')
		return ;
	if (x == 'b')
		return ;
}

void	ft_b_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	ft_b_rrx(stack_a, 'x');
	ft_b_rrx(stack_b, 'x');
}
