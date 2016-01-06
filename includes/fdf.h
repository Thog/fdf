/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:07:19 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/06 11:06:38 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_vec3
{
	int				x;
	int				y;
	int				z;
}					t_vec3;

void				draw_quad(t_env *env, t_vec3 *pos, int size, int color);
t_vec3				*new_vec3(int x, int y, int z);
int					expose_hook(void *param);
#endif
