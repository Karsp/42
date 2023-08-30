/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:13:20 by daviles-          #+#    #+#             */
/*   Updated: 2023/08/30 15:01:44 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#indef PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int	value;
	int	index;
	int	pos_a;
	int	pos_b;
	int dist_to_a;
	struct	s_list *prev;
	struct	s_list *next;
} t_list;

#endif
