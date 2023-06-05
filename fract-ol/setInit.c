/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setInit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:07:07 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/05 14:40:10 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

t_data	clean_init(void)
{
	t_data	data;

	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.min_re = 0;
	data.max_re = 0;
	data.min_im = 0;
	data.max_im = 0;
	data.iter = 0;
	data.color_shift = 1;
	//data.resolution_shift = 0;
	data.set = 0;
	data.center_im = 0;
	data.center_re = 0;
	data.img.mlx_img  = ft_calloc(1, sizeof(t_img));
	data.color = ft_calloc(1, sizeof(t_color));
	return (data);
}

void	set_minmaxnum(t_data *data)
{
	data->min_re = -2.0;
	data->max_re = data->min_re * -1 * WIDTH / HEIGHT;
	data->min_im = -2.0;
	data->max_im = data->min_im * -1 * HEIGHT / WIDTH;
	return ;
}