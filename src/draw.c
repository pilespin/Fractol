/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 23:09:34 by pilespin          #+#    #+#             */
/*   Updated: 2015/03/06 16:30:02 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

int 	ft_is_in_fractal_mandelbrot(t_env *e, double x, double y)
{
	double 	z_r = e->z_r;
	double 	z_i = e->z_i;
	double 	i;
	double 	tmp;
	
	x = e->x_min + (e->x_max - e->x_min) * (x / WIDTH);
	y = e->y_min + (e->y_max - e->y_min) * (y / HEIGHT);

	i = 0;
	while (i < e->iteration_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + x;
		z_i = 2 * z_i * tmp + y;
		i++;
		if (z_r * z_r + z_i * z_i  > 4)
		{
			return (i * 5);
		}
	}
	return (0);
}

int 	ft_is_in_fractal_julia(t_env *e, double x, double y)
{
	double zoom = WIDTH / 2;

	double z_r = x / zoom + e->x_min;
	double z_i = y / zoom + e->y_min;
	double i = 0;
	double 	tmp;

	x = 0.285;
	y = 0.01;

	i = 0;
	while (i < e->iteration_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + e->c_r;
		z_i = 2 * z_i * tmp + e->c_i;
		i++;
		if (z_r * z_r + z_i * z_i  > 4)
		{
			return (i * 5);
		}
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	ft_create_new_image(e);

	int 	x;
	int 	y;
	int 	col;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			col = 0;
			if (e->current_fractal == FRACTAL_OF_MANDELBROT)
				col = ft_is_in_fractal_mandelbrot(e, x, y);
			else if (e->current_fractal == FRACTAL_OF_JULIA)
				col = ft_is_in_fractal_julia(e, x, y);
			else if (e->current_fractal == FRACTAL_OF_DOUADY)
				col = ft_is_in_fractal_julia(e, x, y);

			if (col)
				ft_image_put(e, x, y, RGB(0, 0, col));
			else
				ft_image_put(e, x, y, RGB(150, 150, 150));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		ft_image_put(t_env *e, int x, int y, int color)
{
	char			*pixel;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	new_color;

	if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
		return (0);
	new_color = mlx_get_color_value(e->mlx, color);
	pixel = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp / 8) * x + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp / 8) * x + 2] = (new_color & 0xFF0000) >> 16;
	return (0);
}
