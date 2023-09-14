/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:59:09 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/14 20:21:30 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int ft_printerror(char *str)
{
	ft_putstr_fd("Error: ", 2);	
	ft_putstr_fd(str, 2);	
	exit(0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		while (aux->next)
		{
			ft_printf("Value: %d index: %d next: %d\n", aux->value, aux->index, aux->next);
			aux = aux->next;
		}
		ft_printf("Value: %d index: %d next: %d\n", aux->value, aux->index, aux->next);
	}
	else
		ft_printf("Empty stock\n");
}
void	print_stack_tg(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		while (aux->next)
		{
			ft_printf("Value: %d index: %d next: %d tget: %d\n", aux->value, aux->index, aux->next, aux->target);
			aux = aux->next;
		}
		ft_printf("Value: %d index: %d next: %d\n", aux->value, aux->index, aux->next);
	}
	else
		ft_printf("Empty stock\n");
}
