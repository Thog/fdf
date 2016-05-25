/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:38:44 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/25 16:13:45 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_display(t_env *env)
{
	if (!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fdf")))
		return (1);
	env->render = new_img(env, WIDTH, HEIGHT);
	recompile_render(env);
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
			return (tmp);
		data = data->next;
	}
	return (NULL);
}

t_pos		*get_and_transform_pos(t_env *env, t_pos *pos, int x, int y)
{
	t_pos	*tmp;

	tmp = get_pos(env->data, x, y);
	if (tmp)
	{
		pos->x = (tmp->x + env->modifier->x) * W_SC + W_SC + 1000;
		pos->y = (tmp->y + env->modifier->y) * W_SC + W_SC;
		pos->z = tmp->z * H_SC;
		return (pos);
	}
	return (tmp);
}

void		set_pixel(t_image *img, int x, int y, unsigned int color)
{
	int		pos;

	pos = (x * img->byte_per_pixel) + y * img->line_size;
	img->data[pos] = (color & 0xFF0000) >> 16;
	img->data[pos + 1] = (color & 0xFF00) >> 8;
	img->data[pos + 2] = color & 0xFF;
}

int			put_pixel(t_env *env, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	set_pixel(env->render, x, y, color);
	return (1);
}
