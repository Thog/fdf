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

t_pos	*get_and_transform_pos(t_posdata *data, int x, int y)
{
	t_pos	*pos;

	if ((pos = get_pos(data, x, y)) && (pos = new_pos(pos->x, pos->y, pos->z)))
	{
		pos->x = pos->x * W_SC + W_SC + 1000;
		pos->y = pos->y * W_SC + W_SC;
		pos->z = pos->z * H_SC;
		return (pos);
	}
	return (NULL);
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
		i = 0;
		while ((tmp1 = get_and_transform_pos(env->data, i, j)) && (tmp2 = get_and_transform_pos(env->data, i, j + 1)))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
			++i;
		}
		++j;
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
		while ((tmp1 = get_and_transform_pos(env->data, i, j)) && (tmp2 = get_and_transform_pos(env->data, i + 1, j)))
		{
			draw_line_3d(env, tmp1, tmp2, 0xFFFFFF);
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
		display_horizontal(env);
		display_vertical(env);
	}
	return (env == NULL);
}
