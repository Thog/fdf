/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/25 16:14:45 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			recompile_render(t_env *env)
{
	t_pos		*cache_1;
	t_pos		*cache_2;

	cache_1 = new_pos(0, 0, 0);
	cache_2 = new_pos(0, 0, 0);
	if (env->render && env->render->data && cache_1 && cache_2)
	{
		ft_bzero(env->render->data, env->render->line_size * HEIGHT);
		compute_render(env, cache_1, cache_2);
		ft_memdel((void **)&cache_1);
		ft_memdel((void **)&cache_2);
	}
}

static int		draw_quad(t_env *env, t_pos *cache, int x, int y)
{
	t_pos	*tmp1;
	t_pos	*tmp2;
	int		ret;

	ret = 1;
	tmp1 = get_and_transform_pos(env, cache, x, y);
	tmp2 = get_and_transform_pos(env, cache + 1, x + 1, y);
	ret = draw_line_3d(env, tmp1, tmp2, 0x28112D);
	tmp2 = get_and_transform_pos(env, cache + 1, x, y + 1);
	ret += draw_line_3d(env, tmp1, tmp2, 0x28112D);
	return (ret);
}

void			compute_render(t_env *env, t_pos *tmp3, t_pos *tmp4)
{
	t_pos		tmp[2];
	int			i;
	int			j;

	tmp[0] = *tmp3;
	tmp[1] = *tmp4;
	i = 0;
	j = 0;
	while (j < env->y)
	{
		i = 0;
		while (i < env->width)
		{
			draw_quad(env, tmp, i, j);
			++i;
		}
		++j;
	}
}

int				expose_hook(void *param)
{
	t_env		*env;

	if (param)
	{
		env = (t_env*)param;
		mlx_put_image_to_window(env->mlx, env->win, env->render->ptr, 0, 0);
	}
	return (param == NULL);
}

int				key_hook(int keycode, void *param)
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
		{
			recompile_render(env);
			expose_hook(param);
		}
	}
	return (env == NULL);
}
