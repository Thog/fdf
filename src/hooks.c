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

t_pos	*get_and_transform_pos(t_env *env, t_pos *pos, int x, int y)
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

void	render(t_env *env, t_pos *tmp3, t_pos *tmp4)
{
	t_pos		*tmp1;
	t_pos		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp1 = NULL;
	tmp2 = NULL;
	while (j < env->y)
	{
		i = 0;
		while (i < env->width)
		{
			tmp1 = get_and_transform_pos(env, tmp3, i, j);
			tmp2 = get_and_transform_pos(env, tmp4, i + 1, j);
			draw_line_3d(env, tmp1, tmp2, 0x28112D);
			tmp2 = get_and_transform_pos(env, tmp4, i, j + 1);
			draw_line_3d(env, tmp1, tmp2, 0x28112D);
			++i;
		}
		++j;
	}
}

int		expose_hook(void *param)
{
	t_env		*env;
	t_pos		*cache_1;
	t_pos		*cache_2;

	cache_1 = new_pos(0, 0, 0);
	cache_2 = new_pos(0, 0, 0);
	env = (t_env*)param;
	if (env && cache_1 && cache_2)
	{
		mlx_clear_window(env->mlx, env->win);
		render(env, cache_1, cache_2);
		ft_memdel((void **)&cache_1);
		ft_memdel((void **)&cache_2);
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
