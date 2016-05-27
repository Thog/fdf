/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:07:19 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/27 12:16:16 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "graphics.h"
# define W_SC 60
# define H_SC 5
# define BASE_COLOR 0x28112D
# ifdef __APPLE__
#  define ARROW_OFFSET 122
#  define ESCAPE 53
#  define ARROW_RIGHT ARROW_OFFSET + 2
#  define ARROW_DOWN ARROW_OFFSET + 3
#  define ARROW_UP ARROW_OFFSET + 4
# else
#  define ARROW_OFFSET 65360
#  define ARROW_RIGHT ARROW_OFFSET + 3
#  define ARROW_UP ARROW_OFFSET + 2
#  define ARROW_DOWN ARROW_OFFSET + 4
#  define ESCAPE 65307
# endif
# define ARROW_LEFT ARROW_OFFSET + 1


typedef struct			s_posdata
{
	t_pos				*data;
	struct s_posdata	*next;
}						t_posdata;


typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					x;
	int					y;
	int					width;
	t_posdata			*data;
	t_pos				*modifier;
	t_image				*render;
	t_colorizer			colorizer;
}						t_env;

int						init_display(t_env *env);
int						init_data(t_env *env, int ac, char **av);
t_posdata				*data_put(t_posdata *root, t_pos *array);
void					compute_render(t_env *env, t_pos *tmp3, t_pos *tmp4);
void					recompile_render(t_env *env);
t_pos					*get_pos(t_posdata *data, int x, int y);
t_pos					*get_and_transform_pos(t_env *env, t_pos *pos, int x,
	int y);
int						destroy_env(t_env *env);
#endif
