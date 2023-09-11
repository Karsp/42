/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:19:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/11 22:26:39 by daviles-         ###   ########.fr       */
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
	
	ft_printf("Before \n");
	print_stack(stack_a);
	ft_rrx(&stack_a,'a');
	ft_printf("After\n");
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);
	ft_pushb(&stack_a, &stack_b);
	ft_printf("After\n");
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);
	ft_pushb(&stack_a, &stack_b);
	ft_printf("After\n");
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);
	ft_rrr(&stack_a, &stack_b);
	ft_printf("After\n");
	print_stack(stack_a);
	ft_printf("B: \n");
	print_stack(stack_b);
//	system("leaks push_swap");
	return 0;
}
