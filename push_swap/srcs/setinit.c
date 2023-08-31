/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:58:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/31 18:17:28 by daviles-         ###   ########.fr       */
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

