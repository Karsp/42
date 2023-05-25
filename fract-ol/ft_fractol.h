/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:26:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/25 21:33:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL.H
# define FT_FTACTOL.H

# define HEIGHT 600
# define LENGTH 800
# define MAX_ITERATION 30
# include  "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;



#endif
