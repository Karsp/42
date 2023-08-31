/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:19:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/31 18:22:40 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **nbrs;

	stack_b = NULL;
	stack_a = NULL;
	nbrs = NULL;
	if(argc == 1)
		ft_printerror("Add numbers to sort.");
	else if(argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		ft_chkstr(nbrs);
		stack_a = init_stacka(nbrs);
		ft_freematrix(nbrs);
	}
	else
	{
		ft_chkstr(argv + 1);
		stack_a = init_stacka(argv + 1);
	}

	print_stack(stack_a);
//	system("leaks push_swap");
	return 0;
}
