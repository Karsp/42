/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:50:25 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/22 21:02:47 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx/mlx.h"
#include<stdio.h>

#define MAXCOUNT 30

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ln_len;
	int		endian;
}				t_data;



void	ft_imgdata(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ln_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Let's Fract-ol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln_len, &img.endian);
	while (i <= 1000)
	{
		ft_imgdata(&img, 5, i, 0x00FF0000);
		if (i > 500)
			ft_imgdata(&img, i, i, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		i++;
	}
	mlx_loop(mlx);
}
