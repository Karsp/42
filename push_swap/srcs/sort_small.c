/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:33:33 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/15 00:10:41 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->index > ((*stack)->next)->index)
		ft_rx(stack, 'a');
}

void	sort_3(t_stack **stack)
{
	int	higher;

	higher = get_higher_index_position(stack);
	if (higher == 0)
		ft_rx(stack, 'a');
	else if (higher == 1)
		ft_rrx(stack, 'a');
	if ((*stack)->index > ((*stack)->next)->index)
		ft_swap(stack, 'a');
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size_start == 2)
		sort_2(stack_a);
	if ((*stack_a)->size_start == 3)
		sort_3(stack_a);
	(void)stack_b;
}
