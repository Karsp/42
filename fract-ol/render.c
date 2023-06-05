/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:53:11 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/05 15:15:51 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

int	make_color(t_data *data)
{
	int	color_value;

	color_value = data->iter * 10;
	data->color->r = get_r(color_value);
	data->color->g = get_g(color_value);
	data->color->b = get_b(color_value);
//	apply_shift(data);
	return (create_trgb(0, data->color->r, data->color->g, data->color->b));
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
