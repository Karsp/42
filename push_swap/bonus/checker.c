/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:09:54 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/29 02:05:53 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../srcs/push_swap.h"

void	do_checker_moves(t_stack **stack_a, t_stack **stack_b, char *line)
{
	int	len;
	
	(void)stack_b;
	len = ft_strlen(line);
	if (!ft_strncmp(line, "ra", len-1))
		ft_rx(stack_a, 'a');

}

void	get_do_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_checker_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = chkargs_initstack(ac, av);
	get_do_moves(&stack_a, &stack_b);
	return (0);
}
