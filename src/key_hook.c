/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 22:58:50 by pilespin          #+#    #+#             */
/*   Updated: 2015/03/06 16:09:14 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <project.h>

int		key_hook(int key, t_env *e)
{
	double coef = 0.1;
	double tmpx = e->x_max - e->x_min;
	double tmpy = e->y_max - e->y_min;

	ft_printf("key = %d\n", key);
	if (key == 53)
	{
		exit(0);
	}
	else if (key == ZOOM_IN)
	{
		e->x_min += tmpx * coef;
		e->x_max -= tmpx * coef;
		e->y_min += tmpy * coef;
		e->y_max -= tmpy * coef;
		//e->iteration_max += 10;
	}
	else if (key == ZOOM_OUT && tmpx < e->x_max_size)
	{
		e->x_min -= tmpx * coef;
		e->x_max += tmpx * coef;
		e->y_min -= tmpy * coef;
		e->y_max += tmpy * coef;
	//	e->iteration_max -= 10;
	}
	else if (key == MOVE_UP)
	{
		e->y_min -= tmpy * coef;
		e->y_max -= tmpy * coef;
	}
	else if (key == MOVE_DOWN)
	{
		e->y_min += tmpy * coef;
		e->y_max += tmpy * coef;
	}
	else if (key == MOVE_LEFT)
	{
		e->x_min -= tmpx * coef;
		e->x_max -= tmpx * coef;
		printf("x_dist: %f\n", e->x_max - e->x_min);
	}
	else if (key == MOVE_RIGHT)
	{
		e->x_min += tmpx * coef;
		e->x_max += tmpx * coef;
		printf("x_dist: %f\n", e->x_max - e->x_min);
	}
	else if (key == PRECISION_UP)
	{
		e->iteration_max += 10;
		printf("iteration: %d\n", e->iteration_max);

	}
	else if (key == PRECISION_DOWN)
	{
		if (e->iteration_max > 12)
			e->iteration_max -= 10;
		printf("iteration: %d\n", e->iteration_max);
	}
	else if (key == HOME)
	{
		e->z_r += 0.1;
		printf("z_r: %f\n", e->z_r);
	}
	else if (key == END)
	{
		e->z_r -= 0.1;
		printf("z_r: %f\n", e->z_r);
	}
	else if (key == SUPPR)
	{
		e->z_i += 0.1;
		printf("z_i: %f\n", e->z_i);
	}
	else if (key == FN)
	{
		e->z_i -= 0.1;
		printf("z_i: %f\n", e->z_i);
	}


	expose_hook(e);
	return (0);
}
