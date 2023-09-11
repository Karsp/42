/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:59:09 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/11 21:59:06 by daviles-         ###   ########.fr       */
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
