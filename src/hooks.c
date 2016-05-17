/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/17 12:59:24 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_and_transform_pos(t_env *env, t_pos *pos, int x, int y)
{
	t_pos	*tmp;

	tmp = get_pos(env->data, x, y);
	if (tmp)
	{
		pos->x = (tmp->x + env->modifier->x) * W_SC + W_SC + 1000;
		pos->y = (tmp->y + env->modifier->y) * W_SC + W_SC;
		pos->z = tmp->z * H_SC;
	}
	return (tmp != NULL);
}

void	display_vertical(t_env *env)
{
	t_pos		*tmp1;
	t_pos		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp1 = new_pos(0, 0, 0);
	tmp2 = new_pos(0, 0, 0);
	while (get_pos(env->data, i, j) && tmp1 && tmp2)
	{
		j = 0;
		while (get_and_transform_pos(env, tmp1, i, j) &&
			get_and_transform_pos(env, tmp2, i, j + 1))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
			++j;
		}
		++i;
	}
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
}

void	display_horizontal(t_env *env)
{
	t_pos		*tmp1;
	t_pos		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp1 = new_pos(0, 0, 0);
	tmp2 = new_pos(0, 0, 0);
	while (get_pos(env->data, i, j))
	{
		i = 0;
		while ((get_and_transform_pos(env, tmp1, i, j)) &&
				get_and_transform_pos(env, tmp2, i + 1, j))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
			++i;
		}
		++j;
	}
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
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
	if (keycode == ESCAPE)
		exit(EXIT_SUCCESS);
	else if (env)
	{
		if (keycode == ARROW_DOWN)
			env->modifier->y++;
		else if (keycode == ARROW_UP)
			env->modifier->y--;
		else if (keycode == ARROW_RIGHT)
			env->modifier->x++;
		else if (keycode == ARROW_LEFT)
			env->modifier->x--;
		if (keycode > ARROW_OFFSET && keycode < (ARROW_OFFSET + 5))
			expose_hook(param);
	}
	return (env == NULL);
}
