/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 23:20:34 by pilespin          #+#    #+#             */
/*   Updated: 2015/03/05 17:57:37 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			rg;
	int			vr;
	int			bl;

	int			current_fractal;

	double	 	x_min;
	double	 	x_max;
	double	 	y_min;
	double	 	y_max;

	double	 	x_max_size;
	double	 	y_max_size;
	int 		iteration_max;

	double 		z_r;
	double 		z_i;

	double		c_r;
	double		c_i;

}				t_env;

#endif
