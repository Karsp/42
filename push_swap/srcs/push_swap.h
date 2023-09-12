/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:13:20 by daviles-          #+#    #+#             */
/*   Updated: 2023/09/12 15:38:29 by daviles-         ###   ########.fr       */
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
	long			value;
	int				index;
	int				pos;
	int				target;
	int				dist_to_a;
	int				size_a;
	int				size_b;
	struct s_stack	*next;
}	t_stack;

// utils
int		ft_printerror(char *str);
void	print_stack(t_stack *stack);
void	print_stack_tg(t_stack *stack);
// handle_nodes
t_stack	*node_new(char *nbr);
t_stack	*node_last(t_stack *stack);
void	node_addback(t_stack **stack, t_stack *node);
void	node_addfront(t_stack **stack, t_stack *node);
int		stack_lenght(t_stack **stack);
// sort
int		is_sorted(t_stack *stack);
void	pushall_lessthree(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack);
// setinit
t_stack	*chkargs_initstack(int argc, char **argv);
t_stack	*init_stacka(char **nbrs);
void	main_sort(t_stack *stack_a, t_stack *stack_b);
int		set_index(char *nbr, char **nbrs);
// position and target
void	set_pos_targ(t_stack **stack_a, t_stack **stack_b);
int		get_target(t_stack **stack_a, int index_b, int t_index, int t_pos);
void	get_position(t_stack **stack);
// parse
int		ft_chkstr(char **str);
int		ft_chknbr(char *str);
int		ft_chkduplicate(char **str);
// moves
void	ft_swap(t_stack **stack, char x);
void	ft_swapab(t_stack **stack_a, t_stack **stack_b);
void	ft_pushb(t_stack **stack_a, t_stack **stack_b);
void	ft_pusha(t_stack **stack_a, t_stack **stack_b);
void	ft_rx(t_stack **stack, char x);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrx(t_stack **stack, char x);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
#endif
