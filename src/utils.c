/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 11:34:14 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		internal_draw_line2d(t_env *env, int *data)
{
	int		x;
	int		y;
	int		i;

	x = data[3];
	y = data[4];
	i = 1;
	while (i <= data[2])
	{
		mlx_pixel_put(env->mlx, env->win, x, y, data[5]);
		x += data[0];
		y += data[1];
		i++;
	}
}

void		draw_line_2d(t_env *env, t_pos *start, t_pos *end, int color)
{
	int		data[6];

	data[0] = ABS(end->x - start->x);
	data[1] = ABS(end->y - start->y);
	data[2] = data[0] >= data[1] ? data[0] : data[1];
	data[0] /= data[2];
	data[1] /= data[2];
	data[3] = start->x;
	data[4] = start->y;
	data[5] = color;
	internal_draw_line2d(env, data);
}

t_pos		*new_pos(int x, int y, int z)
{
	t_pos *result;

	if (!(result = (t_pos*)malloc(sizeof(t_pos))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
