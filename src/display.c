/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:38:44 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/17 14:40:20 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_display(t_env *env)
{
	if (!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fdf")))
		return (1);
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

t_pos		*get_pos(t_posdata *data, int x, int y)
{
	t_pos		*tmp;

	while (data)
	{
		tmp = data->data;
		if (tmp->x == x && tmp->y == y)
		{
			return (tmp);
		}
		data = data->next;
	}
	return (NULL);
}

int			put_pixel(t_env *env, int x, int y, int color)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (1);
	mlx_pixel_put(env->mlx, env->win, x, y, color);
	return (0);
}
