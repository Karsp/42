/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:19:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/30 21:05:35 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if(argc == 1)
		ft_printerror("Add numbers to sort.");
	else if(argc == 2)
	{
		//es un string, convertir en numeros entrada
		stack_b = NULL;
		stack_a = NULL;
		ft_chkstr(argv[1]);
	}
	else
	{
	}
//	system("leaks push_swap");
	return 0;
}
