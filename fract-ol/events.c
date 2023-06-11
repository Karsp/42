/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:25:48 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/11 05:06:38 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"

void	ft_close(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->color)
		free(data->color);
	printf("\nExit program.");
	exit(0);
}

int	handle_events(t_data *data)
{
	mlx_key_hook(data->win_ptr, &handle_keys, data);
	mlx_hook(data->win_ptr, ON_MOUSEDOWN, 0, handle_mouse, data);
	mlx_hook(data->win_ptr, ON_MOUSEMOVE, (1L << 6), handle_mouse_move, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, (void *)ft_close, data);
	return (0);
}

int	handle_keys(int keysym, t_data *data)
{
	if (keysym == SPACE)
		shift_color(data);
	if (keysym == M)
		mouse_move_shift(data);
	if (keysym == J && data->set == 2)
		shift_julia_set(data);
	if (keysym == 53)
		ft_close(data);
	if (keysym == L_SHIFT || keysym == R_SHIFT)
	{
		if (data->res_shift < 220)
			data->res_shift += 10;
		else
			data->res_shift = 10;
		ft_printf("Resolution: %d\n", data->res_shift + MAX_ITERATION);
	}
	if (keysym == 123 || keysym == 0)
		move(data, 'L');
	if (keysym == 124 || keysym == 2)
		move(data, 'R');
	if (keysym == 125 || keysym == 1)
		move(data, 'D');
	if (keysym == 126 || keysym == 13)
		move(data, 'U');
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_mouse(int keysym, int x, int y, t_data *data)
{
	if (keysym == ON_MOUSEDOWN)
		mouse_zoom(data, 0.9, x, y);
	if (keysym == ON_MOUSEUP)
		mouse_zoom(data, 1.1, x, y);
	if (keysym == ON_LCLICK && data->set == 2)
		new_julia((double)x, (double)y, data);
	if (keysym == ON_LCLICK && data->set == 1)
		mouse_zoom(data, 0.9, x, y);
	if (keysym == ON_RCLICK && data->set == 1)
		mouse_zoom(data, 1.1, x, y);
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	if (data->set == 2 && data->mouse_move == 1)
		new_julia((double)x, (double)y, data);
	return (0);
}
