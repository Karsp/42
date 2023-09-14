/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:50:04 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/14 20:12:02 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (stack == NULL)
		return (1);
	while (aux->next)
	{
		if (aux->value > (aux->next)->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	sort_3(t_stack **stack)
{
	int	node_3;

	node_3 = (((*stack)->next)->next)->value;
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value > ((*stack)->next)->value)
			if ((*stack)->value > node_3)
				if (((*stack)->next)->value < node_3)
					ft_rx(stack, 'a');
				else
				{
					ft_swap(stack, 'a');
					ft_rrx(stack, 'a');
				}
			else
				ft_swap(stack, 'a');
	else
		if((*stack)->value > node_3)
			ft_rrx(stack, 'a');
		else if(((*stack)->next)->value > node_3)
		{
			ft_rrx(stack, 'a');
			ft_swap(stack, 'a');
		}
}

void	pushall_lessthree(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	pushed;
	int	size;

	size = stack_lenght(stack_a);
	i = 0;
	pushed = 0;
	while (i < size && pushed < size / 2 && size > 6)
	{
		if ((*stack_a)->value <= size / 2)
		{
			ft_pushb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_rx(stack_a, 'a');
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pushb(stack_a, stack_b);
		pushed++;
	}
}

void	shift_stack(t_stack **stack)
{
	int	size;
	int	lowest_id_pos;

	size = stack_lenght(stack);
	lowest_id_pos = get_lowest_index_position(stack);
	if (lowest_id_pos > size / 2)
	{
		while (lowest_id_pos < size)
		{
			ft_rrx(stack, 'a');
			lowest_id_pos++;
		}
	}
	else
	{
		while (lowest_id_pos > 0)
		{
			ft_rx(stack, 'a');
			lowest_id_pos--;
		}
	}
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	pushall_lessthree(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		set_pos_targ(stack_a, stack_b);
		get_distance(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
