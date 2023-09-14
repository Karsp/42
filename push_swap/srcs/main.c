/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:19:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/14 20:07:59 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	stack_a = chkargs_initstack(argc, argv);
	
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);

	main_sort(&stack_a, &stack_b);
   	ft_printf("A\n");
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);
	if (is_sorted(stack_a))
			ft_printf("Sorted");
	else
        printf("KO\n");
	
//	system("leaks push_swap");
	return 0;
}
