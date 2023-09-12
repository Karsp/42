/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:32:54 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/12 15:33:47 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*aux;
	int		pos;

	aux = *stack;
	pos = 0;
	while (aux)
	{
		aux->pos = pos;
		aux = aux->next;
		pos++;
	}
}

int	get_target(t_stack **stack_a, int index_b, int t_index, int t_pos)
{
	t_stack	*aux_a;

	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index > index_b && aux_a->index < t_index)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	if (t_pos != INT_MAX)
		return (t_pos);
	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index < t_index)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	return (t_pos);
}

void	set_pos_targ(t_stack **stack_a, t_stack **stack_b)
{
	int		t_pos;
	t_stack	*aux_b;

	t_pos = 0;
	aux_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	while (aux_b)
	{
		t_pos = get_target(stack_a, aux_b->index, INT_MAX, t_pos);
		aux_b->target = t_pos;
		aux_b = aux_b->next;
	}
}	
