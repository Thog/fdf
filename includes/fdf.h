/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:07:19 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 07:43:04 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PROJ_X(X, Y, Z) ((X/2) - (Y/2) + 200)
# define PROJ_Y(X, Y, Z) (-(Z/2) + (X/4) + (Y/4) + 100)
# define SWAP(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)
# define ISO_C1 0.5F
# define ISO_C2 0.5F
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

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

typedef int		(*t_transformer)(int x, int y, int z);

int				proj_dummy_x(t_pos *pos);
int				proj_dummy_y(t_pos *pos);
int				proj_iso_x(t_pos *pos);
int				proj_iso_y(t_pos *pos);
void			draw_line_2d(t_env *env, t_pos *start, t_pos *end, int color);
void			draw_line_3d(t_env *env, t_pos *start, t_pos *end, int color);
t_pos			*new_pos(int x, int y, int z);
int				expose_hook(void *param);
int				init_display(t_env *env);
int				init_data(t_env *env, int ac, char **av);
#endif
