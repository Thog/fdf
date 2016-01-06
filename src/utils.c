/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/06 15:00:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#define PROJ_X(X, Y, Z) ((X/2) - (Y/2) + 200)
#define PROJ_Y(X, Y, Z) (-(Z/2) + (X/4) + (Y/4) + 100)
void		draw_quad(t_env *env, t_vec3 *pos, int size, int color)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			if (i == 1 || i == size || j == 1 || j == size)
			{
				x = pos->x + i;
				y = pos->y + j;
				if (pos->z)
				{
					x = PROJ_X(x, y, pos->z);
					y = PROJ_Y(x, y, pos->z);
				}
				mlx_pixel_put(env->mlx, env->win, x, y, color);
			}
			j++;
		}
		i++;
	}
}

t_vec3		*new_vec3(int x, int y, int z)
{
	t_vec3 *result;

	if (!(result = (t_vec3*)malloc(sizeof(t_vec3))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
