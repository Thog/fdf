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

int		expose_hook(void *param)
{
	t_env		*env;
	t_posdata	*data;
	t_pos		*pos;
	t_pos		*tmp;

	env = (t_env*)param;
	if (env)
	{
		data = env->data;
		while (data)
		{
			pos = data->data;
			tmp = get_pos(env->data, pos->x - 1, pos->y);
			draw_line_3d(env, pos, tmp, 0xFFFFFF);
			tmp = get_pos(env->data, pos->x + 1, pos->y);
			draw_line_3d(env, pos, tmp, 0xFFFFFF);
			tmp = get_pos(env->data, pos->x, pos->y - 1);
			draw_line_3d(env, pos, tmp, 0xFFFFFF);
			tmp = get_pos(env->data, pos->x, pos->y + 1);
			draw_line_3d(env, pos, tmp, 0xFFFFFF);
			data = data->next;
		}
	}
	return (env == NULL);
}
