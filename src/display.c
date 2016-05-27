/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:38:44 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/27 12:15:59 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(int index)
{
	return (BASE_COLOR + 0x020202 * ft_min(index, W_SC));
}

int				init_display(t_env *env)
{
	if (!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fdf")))
		return (1);
	env->colorizer = &get_color;
	env->render = new_img(env, WIDTH, HEIGHT);
	recompile_render(env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

t_pos			*get_pos(t_posdata *data, int x, int y)
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
