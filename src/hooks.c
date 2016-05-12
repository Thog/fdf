/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 11:00:41 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	*get_and_transform_pos(t_env *env, int x, int y)
{
	t_pos	*pos;

	if ((pos = get_pos(env->data, x, y)))
		pos = new_pos(x, y, pos->z);
	if (pos)
	{
		pos->x = pos->x * W_SC + W_SC + 1000 + env->modifier->x;
		pos->y = pos->y * W_SC + W_SC + env->modifier->y;
		pos->z = pos->z * H_SC;
	}
	return (pos);
}

void	display_vertical(t_env *env)
{
	t_pos		*tmp1;
	t_pos		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;

	while ((tmp1 = get_pos(env->data, i, j)))
	{
		j = 0;
		while ((tmp1 = get_and_transform_pos(env, i, j)) && (tmp2 = get_and_transform_pos(env, i, j + 1)))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
			free(tmp1);
			free(tmp2);
			++j;
		}
		++i;
	}
}

void	display_horizontal(t_env *env)
{
	t_pos		*tmp1;
	t_pos		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;

	while ((tmp1 = get_pos(env->data, i, j)))
	{
		i = 0;
		while ((tmp1 = get_and_transform_pos(env, i, j)) && (tmp2 = get_and_transform_pos(env, i + 1, j)))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
			free(tmp1);
			free(tmp2);
			++i;
		}
		++j;
	}
}

int		expose_hook(void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (env)
	{
		mlx_clear_window(env->mlx, env->win);
		display_horizontal(env);
		display_vertical(env);
	}
	return (env == NULL);
}

int		key_hook(int keycode, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (env)
	{
		if (keycode == 65362)
			env->modifier->y += 10;
		else if (keycode == 65364)
			env->modifier->y -= 10;
		else if (keycode == 65363)
			env->modifier->x += 10;
		else if (keycode == 65361)
			env->modifier->x -= 10;

		if (keycode > 65360 && keycode < 65365)
			expose_hook(param);
	}
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (env == NULL);
}
