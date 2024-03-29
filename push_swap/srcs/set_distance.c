/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:37:59 by daviles-          #+#    #+#             */
/*   Updated: 2024/03/03 00:41:50 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_distance(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	size_a = stack_lenght(stack_a);
	size_b = stack_lenght(stack_b);
	while (aux_b)
	{
		aux_b->dist_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->dist_b = (size_b - aux_b->pos) * -1;
		aux_b->dist_a = aux_b->target;
		if (aux_b->target > size_a / 2)
			aux_b->dist_a = (size_a - aux_b->target) * -1;
		aux_b = aux_b->next;
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int dist_a, int dist_b)
{
	if (dist_a < 0 && dist_b < 0)
	{
		while (dist_a < 0 && dist_b < 0)
		{
			dist_a++;
			dist_b++;
			ft_rrr(stack_a, stack_b);
		}
	}
	else if (dist_a > 0 && dist_b > 0)
	{
		while (dist_a > 0 && dist_b > 0)
		{
			dist_a--;
			dist_b--;
			ft_rr(stack_a, stack_b);
		}
	}
	ft_loop_rotate(stack_a, stack_b, dist_a, 'a');
	ft_loop_rotate(stack_a, stack_b, dist_b, 'b');
	if (*stack_b)
		ft_pusha(stack_a, stack_b);
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		dist_a;
	int		dist_b;
	int		cheapest;

	aux_b = *stack_b;
	cheapest = INT_MAX;
	while (aux_b)
	{
		if (ft_absolute_value(aux_b->dist_a) + ft_absolute_value(aux_b->dist_b)
			< ft_absolute_value(cheapest))
		{
			cheapest = ft_absolute_value(aux_b->dist_a) + \
			ft_absolute_value(aux_b->dist_b);
			dist_a = aux_b->dist_a;
			dist_b = aux_b->dist_b;
		}
		aux_b = aux_b->next;
	}
	do_move(stack_a, stack_b, dist_a, dist_b);
}
