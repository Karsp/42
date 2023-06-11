/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 01:07:44 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/11 05:06:34 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	isjulia(t_data *data, double z_im, double z_re)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < (MAX_ITERATION + data->res_shift))
	{
		if (((z_re * z_re) + (z_im * z_im)) > 4)
		{
			data->iter = i;
			return (0);
		}
		tmp = 2 * z_re * z_im + data->julia_kx;
		z_re = (z_re * z_re) - (z_im * z_im) + data->julia_ky;
		z_im = tmp;
		i++;
	}
	data->iter = i;
	return (1);
}

void	generate_julia(t_data *data)
{
	double			z_im;
	double			z_re;
	unsigned int	y;
	unsigned int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		z_im = data->max_im + ((double)y * (data->min_im
					- data->max_im) / HEIGHT);
		while (++x < WIDTH)
		{
			z_re = data->min_re + ((double)x * (data->max_re
						- data->min_re) / WIDTH);
			if (isjulia(data, z_im, z_re))
				img_pix_put(&data->img, x, y, 0x000000);
			else
				img_pix_put(&data->img, x, y, make_color(data));
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
}

void	new_julia(double x, double y, t_data *data)
{
	data->julia_ky = data->max_im + ((double)y * (data->min_im
					- data->max_im) / HEIGHT);
	data->julia_kx = data->min_re + ((double)x * (data->max_re
						- data->min_re) / WIDTH);
	printf("New Julia Z value: %f  %f\n", x, y);
	printf("New Julia Z value: %f  %f\n", data->julia_kx, data->julia_ky);
}

void	shift_julia_set(t_data *data)
{
	if (data->julia_set == 1)
	{
		data->julia_ky = -0.4;
		data->julia_kx = -0.59;
	}
	else if (data->julia_set == 2)
		new_julia(0.34, -0.05, data);
	else if (data->julia_set == 3)
		new_julia(0.355, 0.355, data);
	else if (data->julia_set == 4)
		new_julia(0, 0.8, data);
	else if (data->julia_set == 5)
		new_julia(0, 0.8, data);
	data->julia_set += 1;
	if (data->julia_set >= 8)
		data->julia_set = 0;
	printf("JULIASET = %d", data->julia_set);
}
