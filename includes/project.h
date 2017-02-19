/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:53:20 by pilespin          #+#    #+#             */
/*   Updated: 2015/10/16 14:21:30 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include <struct.h>
# include <stdio.h>
# include <math.h>

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define WIDTH 600
# define HEIGHT (int)((WIDTH / (e->x_max_size)) * (e->y_max_size))

/*
** KEYBOARD
*/

# define ZOOM_IN 		69
# define ZOOM_OUT 		78
# define MOVE_UP 		126
# define MOVE_DOWN 		125
# define MOVE_LEFT 		123
# define MOVE_RIGHT		124
# define PRECISION_UP	116
# define PRECISION_DOWN 121
# define HOME 			115
# define END 			119
# define FN 			279
# define SUPPR 			117

# define SCROLL_DOWN	5
# define SCROLL_UP 		4

# define FRACTAL_OF_MANDELBROT 		1
# define FRACTAL_OF_JULIA	 		2
# define FRACTAL_OF_DOUADY			3

void	ft_start(t_env *e, char *name);
int		expose_hook(t_env *e);
int		key_hook(int key, t_env *e);
void	ft_init_line(t_env *e, int i);
int		ft_image_put(t_env *e, int x, int y, int color);
void	ft_create_new_image(t_env *e);

#endif
