/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:50:25 by daviles-          #+#    #+#             */
/*   Updated: 2023/05/24 21:52:50 by daviles-         ###   ########.fr       */
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

void	ft_mandelbrot(int imgW, int imgH)
{
	double	minRe;
	double	maxRe;
	double	minIm;
	double	maxIm;
	double	reFact;
	double	imFact;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		x;
	int		y;
	int		maxIter;
	int		iter;
	int		isMan;

	maxIter = 60;
	x = 0;
	y = 0;
	minRe = -2.0;
	maxRe = 1.0;
	minIm = -1.2;
	maxIm = minIm + (maxRe - minRe) * imgH / imgW;
	reFact = (maxRe - minRe) / (imgW - 1);
	imFact = (maxIm - minIm) / (imgH - 1);
	while (y < imgH)
	{
		c_im = maxIm - y * imFact;
		while (x < imgW)
		{
			c_re = maxRe + x * reFact;
			z_re = c_re;
			z_im = c_im;
			iter = 0;
			isMan = 1;
			while (iter < maxIter)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					isMan = 0;
					break;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				iter++;
			}
			if (isMan)
	//			print_pxl(x, y);
			x++;
		}
		y++;
	}

}

void	ft_imgdata(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ln_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

/*void	print_pxl(int x, int y)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		imgH;
	int		imgW;

	imgW = 1080;
	imgH = 1920;
	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, imgW, imgH, "Let's Fract-ol");
	img.img = mlx_new_image(mlx, imgW, imgH);
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
}*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		imgH;
	int		imgW;

	imgW = 800;
	imgH = 600;
	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, imgW, imgH, "Let's Fract-ol");
	img.img = mlx_new_image(mlx, imgW, imgH);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ln_len, &img.endian);
	
	double	minRe;
	double	maxRe;
	double	minIm;
	double	maxIm;
	double	reFact;
	double	imFact;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		x;
	int		y;
	int		maxIter;
	int		iter;
	int		isMan;

	maxIter = 60;
	x = 0;
	y = 0;
	minRe = -2.0;
	maxRe = 1.0;
	minIm = -1.2;
	maxIm = minIm + (maxRe - minRe) * imgH / imgW;
	reFact = (maxRe - minRe) / (imgW - 1);
	imFact = (maxIm - minIm) / (imgH - 1);
	while (y < imgH)
	{
		c_im = maxIm - y * imFact;
		while (x < imgW)
		{
			c_re = maxRe + x * reFact;
			z_re = c_re;
			z_im = c_im;
			iter = 0;
			isMan = 1;
			while (iter < maxIter && isMan)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					ft_imgdata(&img, x, y, 0xFF000000);
					mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
					isMan = 0;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				iter++;
			}
			if (isMan)
			{
				ft_imgdata(&img, x, y, 0x00FF0000);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
}
