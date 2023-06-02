/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviles- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:50:25 by daviles-          #+#    #+#             */
/*   Updated: 2023/06/02 15:25:52 by daviles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fractol.h"


void	ft_close(t_data *data)
{
	if (data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("\nExit program.");
	exit(0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}


int	handle_keys(int keysym, t_data *data)
{
	if (keysym == 53)
		ft_close(data);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_mouse(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	(void)data;
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	isMandelbrot(int n, double z_re, double z_im, double c_im, double c_re)
{
	double Z_re2; 
    double Z_im2;

	while (n++ < MAX_ITERATION)
	{
		Z_re2 = Z_re * Z_re;
		Z_im2 = Z_im * Z_im;
		if(Z_re2 + Z_im2 > 4)
			return (0);
		Z_im = 2*Z_re*Z_im + c_im;
		Z_re = Z_re2 - Z_im2 + c_re;
	}
	return (1); 
}


int	generate_fractal(t_data data)
{
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe)*HEIGHT/WIDTH;
	double Re_factor = (MaxRe-MinRe)/(WIDTH-1);
	double Im_factor = (MaxIm-MinIm)/(HEIGHT-1);
	unsigned y;
	unsigned x;
	unsigned n;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		double c_im = MaxIm - y*Im_factor;
   	 while (x++ < WIDTH)
   	 {
        double c_re = MinRe + x*Re_factor;
        double Z_re = c_re, Z_im = c_im;
        int isInside = 1;
		n = 0;
        while (n++ < MAX_ITERATION)
        {
            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
            if(Z_re2 + Z_im2 > 4)
            {
				printf("ZRE %f ZRE2 %f  \n", Z_re, Z_re2);
                isInside = 0;
                break;
            }
            Z_im = 2*Z_re*Z_im + c_im;
            Z_re = Z_re2 - Z_im2 + c_re;
        }
        if(isInside)  	
			img_pix_put(&data.img, x, y, 0xFF0000);
    }
}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Let's Fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (!data.img.mlx_img)
	{
		ft_close(&data);
		printf("MLX image creation error.\n");
		return (MLX_ERROR);
	}
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
							&data.img.ln_len, &data.img.endian);
	/* Generate fractal*/
	generate_fractal(data);
	/* Setup hooks */ 
	mlx_key_hook(data.win_ptr, &handle_keys, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);

}
