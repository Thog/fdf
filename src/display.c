/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:38:44 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 10:45:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_display(t_env *env)
{
	if (!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, 1366, 768, "fdf")))
		return (1);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

t_pos		*get_pos(t_posdata *data, int x, int y, int z)
{
	t_pos	*tmp;

	while (data)
	{
		tmp = data->data;
		if (tmp->x == x && tmp->y == y && tmp->z == z)
			return (tmp);
		data = data->next;
	}
	return (NULL);
}
