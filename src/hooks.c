/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:41:55 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/06 15:04:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(void *param)
{
	t_env *env;
	t_vec3 *pos;

	env = (t_env*)param;
	pos = new_vec3(10, 10, 100);
	if (env)
	{
		draw_quad(env, pos, 300, 0xFFFFFF);
	}
	free(pos);
	return (env == NULL);
}
