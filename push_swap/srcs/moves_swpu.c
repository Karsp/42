/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swpu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:12:43 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/11 20:15:01 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(t_stack **stack, char x)
{
	int		l;
	t_stack	*aux_1;
	t_stack	*aux_2;
	t_stack	*aux_3;

	l = stack_lenght(stack);
	aux_1 = *stack;
	aux_2 = (*stack)->next;
	aux_3 = ((*stack)->next)->next;
	if (l > 1)
	{
		aux_2->next = *stack;
		aux_1->next = aux_3;
		*stack = aux_2;
		if (x == 'a')
			ft_printf("sa\n");
		if (x == 'b')
			ft_printf("sb\n");
	}
}

void	ft_swapab(t_stack **stacka, t_stack **stackb )
{
	ft_swap(stacka, 'a');
	ft_swap(stackb, 'b');
	ft_printf("ss\n");
}

void	ft_pushb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*node_a1;
	t_stack	*node_b1;
	
	if (*stacka != NULL)
	{
		node_a1 = *stacka;
		if (*stackb == NULL)
		{
			if ((*stacka)->next)
				*stacka = (*stacka)->next;
			else
				*stacka = NULL;	
			*stackb = node_a1;
			node_a1->next = NULL;
		}
		else
		{
			node_b1 = *stackb;
			if ((*stacka)->next)
				*stacka = (*stacka)->next;
			else
				*stacka = NULL;	
			*stackb = node_a1;
			node_a1->next = node_b1;
		}
	ft_printf("pb\n");
	}
}

void	ft_pusha(t_stack **stacka, t_stack **stackb)
{
	t_stack	*node_b1;
	t_stack	*node_a1;
	
	if (*stackb != NULL)
	{
		node_b1 = *stackb;
		if (*stacka == NULL)
		{
			if ((*stackb)->next)
				*stackb = (*stackb)->next;
			else
				*stackb = NULL;
			*stacka = node_b1;
			node_b1->next = NULL;
		}
		else
		{
			node_a1 = *stacka;
			if ((*stackb)->next)
				*stackb = (*stackb)->next;
			else
				*stackb = NULL;
			*stacka = node_b1;
			node_b1->next = node_a1;
		}
	ft_printf("pa\n");
	}
}
