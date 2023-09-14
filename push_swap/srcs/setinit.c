/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:58:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/14 23:28:25 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*init_stacka(char **nbrs)
{
	int		i;
	t_stack	*stack;
	t_stack	*node;

	stack = NULL;
	node = NULL;
	i = 0;
	while (nbrs[i] != '\0')
	{
		node = node_new(nbrs[i]);
		node->index = set_index(nbrs[i], nbrs);
		node_addback(&stack, node);
		i++;
	}
	stack->size_start = i;
	return (stack);
}

int	set_index(char *nbr, char **nbrs)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (nbrs[i] != '\0')
	{
		if (ft_atoi(nbr) >= ft_atoi(nbrs[i]))
			index++;
		i++;
	}
	return (index);
}

t_stack	*chkargs_initstack(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**nbrs;

	stack_a = NULL;
	nbrs = NULL;
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		nbrs = ft_split(argv[1], ' ');
		ft_chkstr(nbrs);
		stack_a = init_stacka(nbrs);
		ft_freematrix(&nbrs);
	}
	else
	{
		ft_chkstr(argv + 1);
		stack_a = init_stacka(argv + 1);
	}
	return (stack_a);
}
