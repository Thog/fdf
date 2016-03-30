/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 18:01:25 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(void *param)
{
	t_env	*env;
	t_pos	*start;
	t_pos	*end;

	env = (t_env*)param;
	start = new_pos(2000, 100, 0);
	end = new_pos(2000, 400, 0);
	if (env)
	{
		draw_line_3d(env, start, end, 0xFFFFFF);
	}
	free(start);
	free(end);
	return (env == NULL);
}
