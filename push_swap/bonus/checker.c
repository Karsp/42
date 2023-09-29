/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:09:54 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/29 02:33:38 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../srcs/push_swap.h"

void	do_checker_moves(t_stack **stack_a, t_stack **stack_b, char *line, int len)
{
	if (!ft_strncmp(line, "ra", len - 1))
		ft_rx(stack_a, 'a');
	else if (!ft_strncmp(line, "rb", len - 1))
		ft_rx(stack_b, 'b');
	else if (!ft_strncmp(line, "rr", len - 1))
		ft_rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rrb", len - 1))
		ft_rrx(stack_b, 'b');
	else if (!ft_strncmp(line, "rra", len - 1))
		ft_rrx(stack_a, 'a');
	else if (!ft_strncmp(line, "rrr", len - 1))
		ft_rrr(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", len - 1))
		ft_pusha(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb", len - 1))
		ft_pushb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ss", len - 1))
		ft_swapab(stack_a, stack_b);
	else if (!ft_strncmp(line, "sa", len - 1))
		ft_swap(stack_a, 'a');
	else if (!ft_strncmp(line, "sb", len - 1))
		ft_swap(stack_b, 'b');
	else
		ft_printerror("\n");
}

void	get_do_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		len;
	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		do_checker_moves(stack_a, stack_b, line, len);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(*stack_a) && !*stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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