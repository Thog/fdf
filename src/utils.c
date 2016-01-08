/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/08 14:01:40 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#define PROJ_X(X, Y, Z) ((X/2) - (Y/2) + 200)
#define PROJ_Y(X, Y, Z) (-(Z/2) + (X/4) + (Y/4) + 100)
#define ABS(X) X < 0 ? (-X) : X
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
				x = PROJ_X(pos->x + i, pos->y + j, pos->z);
				y = PROJ_Y(pos->x, pos->y + j, pos->z);
				mlx_pixel_put(env->mlx, env->win, x, y, color);
			}
			j++;
		}
		i++;
	}
}

void		draw_line(t_env *env, t_vec3 *start, t_vec3 *end, int color)
{

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
