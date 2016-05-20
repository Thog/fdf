/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:07:19 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/20 15:31:14 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# define WIDTH 1366
# define HEIGHT 768
# define ISO_C1 0.5F
# define ISO_C2 0.5F
# define W_SC 60
# define H_SC 5
# define W_LIMIT (WIDTH / W_SC) + W_SC
# define H_LIMIT (HEIGHT / H_SC) + H_SC
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

typedef struct			s_pos
{
	int					x;
	int					y;
	int					z;
}						t_pos;

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
}						t_env;

typedef int				(*t_transformer)(int x, int y, int z);

int						proj_dummy_x(t_pos *pos);
int						proj_dummy_y(t_pos *pos);
int						proj_iso_x(t_pos *pos);
int						proj_iso_y(t_pos *pos);
int						draw_line_2d(t_env *env, t_pos *start, t_pos *end,
	int color);
int						draw_line_3d(t_env *env, t_pos *start, t_pos *end,
	int color);
t_pos					*new_pos(int x, int y, int z);
int						expose_hook(void *param);
int						key_hook(int keycode, void *param);
int						init_display(t_env *env);
int						init_data(t_env *env, int ac, char **av);
t_posdata				*data_put(t_posdata *root, t_pos *array);
t_pos					*get_pos(t_posdata *data, int x, int y);
int						put_pixel(t_env *env, int x, int y, int color);
#endif
