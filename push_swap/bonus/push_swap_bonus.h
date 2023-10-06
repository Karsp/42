/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:13:20 by daviles-          #+#    #+#             */
/*   Updated: 2023/10/06 21:40:26 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "../srcs/push_swap.h"

// moves bonus
void	ft_b_swap(t_stack **stack, char x);
void	ft_b_swapab(t_stack **stack_a, t_stack **stack_b);
void	ft_b_pushb(t_stack **stack_a, t_stack **stack_b);
void	ft_b_pusha(t_stack **stack_a, t_stack **stack_b);
void	ft_b_rx(t_stack **stack, char x);
void	ft_b_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_b_rrx(t_stack **stack, char x);
void	ft_b_rrr(t_stack **stack_a, t_stack **stack_b);
// bonus functions
void	get_do_moves(t_stack **stack_a, t_stack **stack_b);
void	checker_mov(t_stack **stack_a, t_stack **stack_b, char *line, int len);

#endif
