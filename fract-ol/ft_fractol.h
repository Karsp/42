/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:26:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/26 22:30:55 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include  "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# define HEIGHT 600
# define WIDTH 800
# define MAX_ITERATION 30
# define MLX_ERROR 1

typedef struct	s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	*set;
}	t_data;



#endif
