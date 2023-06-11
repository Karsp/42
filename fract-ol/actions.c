/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:55:55 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/11 04:00:06 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

void	move(t_data	*data, char key)
{
	data->center_re = data->min_re - data->max_re;
	data->center_im = data->min_im - data->max_im;
	if (key == 'U')
	{
		data->min_im -= data->center_im * 0.1;
		data->max_im -= data->center_im * 0.1;
	}
	if (key == 'D')
	{
		data->min_im += data->center_im * 0.1;
		data->max_im += data->center_im * 0.1;
	}
	if (key == 'R')
	{
		data->min_re -= data->center_re * 0.1;
		data->max_re -= data->center_re * 0.1;
	}
	if (key == 'L')
	{
		data->min_re += data->center_re * 0.1;
		data->max_re += data->center_re * 0.1;
	}
	return ;
}

void	mouse_zoom(t_data *data, double zoom, int x, int y)
{
	double	normalized_x = data->max_re + ((double)(WIDTH - x) * (data->min_re
				- data->max_re) / WIDTH);
	double	normalized_y = data->max_im + ((double)y * (data->min_im
				- data->max_im) / HEIGHT);
	double	origin_im = ((data->max_im - data->min_im) / 2) + data->min_im;
	double	origin_re = ((data->max_re - data->min_re) / 2) + data->min_re;
	double	normalized_radius_re = data->max_re - origin_re;
	double	normalized_radius_im = data->max_im - origin_im;
	double	delta_x = (normalized_x - origin_re);
	double	delta_y = (normalized_y - origin_im);
	
	normalized_radius_re *= zoom;
	normalized_radius_im *= zoom;
	delta_x *= zoom;
	delta_y *= zoom;
	origin_re = normalized_x - delta_x;
	origin_im = normalized_y - delta_y;
	data->max_re = normalized_radius_re + origin_re;
	data->min_re = origin_re - normalized_radius_re;
	data->max_im = normalized_radius_im + origin_im;
	data->min_im = origin_im - normalized_radius_im;
	return ;
}
