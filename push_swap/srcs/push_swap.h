/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:13:20 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/31 18:17:52 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	long	value;
	int		index;
	int		pos_a;
	int		pos_b;
	int 	dist_to_a;
	int		size_a;
	int		size_b;
	struct	s_stack *prev;
	struct	s_stack *next;
} t_stack;

// utils
int		ft_printerror(char *str);
void	print_stack(t_stack *stack);
t_stack	*node_new(char *nbr);
t_stack	*node_last(t_stack *stack);
void	node_addback(t_stack **stack, t_stack *node);
// setinit
t_stack	*init_stacka(char **nbrs);
int	set_index(char *nbr, char **nbrs);
// parse
int		ft_chkstr(char **str);
int		ft_chknbr(char *str);
int		ft_chkduplicate(char **str);
// node handle

#endif
