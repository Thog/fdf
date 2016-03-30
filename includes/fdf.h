/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:07:19 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 11:37:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ABS(X) X < 0 ? (-X) : X
# define PROJ_X(X, Y, Z) ((X/2) - (Y/2) + 200)
# define PROJ_Y(X, Y, Z) (-(Z/2) + (X/4) + (Y/4) + 100)
# include <mlx.h>
# include <stdlib.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;
}				t_pos;

void			draw_line_2d(t_env *env, t_pos *start, t_pos *end, int color);
void			draw_line_3d(t_env *env, t_pos *start, t_pos *end, int color);
t_pos			*new_pos(int x, int y, int z);
int				expose_hook(void *param);
#endif
