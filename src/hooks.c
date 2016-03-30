/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 11:39:39 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(void *param)
{
	t_env	*env;
	t_pos	*start;
	t_pos	*end;

	env = (t_env*)param;
	start = new_pos(100, 70, 0);
	end = new_pos(100, 410, 0);
	if (env)
	{
		draw_line_2d(env, start, end, 0xFFFFFF);
	}
	free(start);
	free(end);
	return (env == NULL);
}
