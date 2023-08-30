/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:19:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/30 21:47:07 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	stack_b = NULL;
	stack_a = NULL;
	char **nbrs;
	nbrs = NULL;

	if(argc == 1)
		ft_printerror("Add numbers to sort.");
	else if(argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		ft_chkstr(nbrs);
	}
	else
	{
		ft_chkstr(argv + 1);
	}
//	system("leaks push_swap");
	return 0;
}
