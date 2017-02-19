/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:57:07 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/16 14:21:17 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

void ft_print_help(char *error)
{
	if (error)
		ft_dprintf(2, "%s", error);
	ft_dprintf(2, "Usage: fractol -mjd\n");
	ft_dprintf(2, "-m : Mandelbrot\n");
	ft_dprintf(2, "-j : Julia\n");
	ft_dprintf(2, "-d : Douady\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	ft_bzero(e, sizeof(t_env));

	if (ac < 2)
		ft_print_help("Missing argument\n");
	else if (ac > 2)
		ft_print_help("Too many arguments\n");
	else if (ac == 2)
	{ 
		if (!ft_strcmp(av[1], "-j"))
			e->current_fractal = FRACTAL_OF_JULIA;
		else if (!ft_strcmp(av[1], "-m"))
			e->current_fractal = FRACTAL_OF_MANDELBROT;
		else if (!ft_strcmp(av[1], "-d"))
			e->current_fractal = FRACTAL_OF_DOUADY;
		else
			ft_print_help("Bad argument\n");
		ft_start(e, "Fractol");
	}
	return (0);
}

/*
**	0 = COEF MIN
**	2 = COEF MAX
*/

double ft_ratio_mouse(int x, int size)
{
	return (1.0 * (x * 2) / size);
}

int mouse_hook(int button, int x, int y, t_env *e) {

	double coef = 0.1;
	double coefMouseX = ft_ratio_mouse(x, WIDTH);
	double coefMouseY = ft_ratio_mouse(y, HEIGHT);

	double coefElseX = 2 - coefMouseX;
	double coefElseY = 2 - coefMouseY;

	double tmpx = e->x_max - e->x_min;
	double tmpy = e->y_max - e->y_min;

	if (button == SCROLL_UP)
	{
		printf("SCROLL_UP\n");

		e->x_min += (tmpx * coef) * coefMouseX;
		e->x_max -= (tmpx * coef) * coefElseX;
		e->y_min += (tmpy * coef) * coefMouseY;
		e->y_max -= (tmpy * coef) * coefElseY;
		// e->iteration_max += 10;
	}
	else if (button == SCROLL_DOWN && tmpx < e->x_max_size)
	{
		printf("SCROLL_DOWN\n");
		e->x_min -= tmpx * coef;
		e->x_max += tmpx * coef;
		e->y_min -= tmpy * coef;
		e->y_max += tmpy * coef;
	//	e->iteration_max -= 10;
	}
	expose_hook(e);

	return (0);

}

int 	mouse_now(int x, int y, t_env *e) 
{
	// x += WIDTH / 3;
	y -= HEIGHT / 2;

	e->c_r = (1.0 * x / 600);
	e->c_i = (1.0 * y / 600);

	printf("cr = %f\n", e->c_r);
	printf("ci = %f\n", e->c_i);

	expose_hook(e);
	return (0);
}

void	ft_start(t_env *e, char *name)
{
	if (e->current_fractal == FRACTAL_OF_MANDELBROT)
	{
		e->x_min = -2.1;
		e->x_max = 0.6;
		e->y_min = -1.2;
		e->y_max = 1.2;	
		e->z_r = 0;
		e->z_i = 0;
	}
	else if (e->current_fractal == FRACTAL_OF_JULIA)
	{
		e->x_min = -1;
		e->x_max = 1;
		e->y_min = -1.2;
		e->y_max = 1.2;
		e->c_r = 0.285;
		e->c_i = 0.01;
		e->z_r = (e->x_max - e->x_min) * 100;
		e->z_i = (e->y_max - e->y_min) * 100;
	}
	else if (e->current_fractal == FRACTAL_OF_DOUADY)
	{
		e->x_min = -1;
		e->x_max = 1;
		e->y_min = -1.2;
		e->y_max = 1.2;
		e->c_r = -0.123;
		e->c_i = -0.745;
		e->z_r = (e->x_max - e->x_min) * 100;
		e->z_i = (e->y_max - e->y_min) * 100;
	}
	else
		ft_dprintf(2, "WTF\n");

	e->iteration_max = 150;
	e->x_max_size = e->x_max - e->x_min;
	e->y_max_size = e->y_max - e->y_min;

	e->mlx = mlx_init();
	if (e->mlx)
	{
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, name);
		mlx_key_hook(e->win, key_hook, e);
		mlx_mouse_hook (e->win, mouse_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 6, (1L << 8), mouse_now, e);
		mlx_loop(e->mlx);
	}
	else
		ft_dprintf(2, "An error occured when initialising window\n");
}
