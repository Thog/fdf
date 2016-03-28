/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/20 15:18:33 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_quad(t_env *env, t_pos *pos, int size, int color)
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

void		draw_line_2d(t_env *env, t_pos *start, t_pos *end, int color)
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			i;
	int			pixel;

	dx = ABS(end->x - start->x);
    dy = ABS(end->y - start->y);

    if (dx >= dy)
		pixel = dx;
    else
		pixel = dy;

    dx = dx / pixel;
    dy = dy / pixel;

    x = start->x;
    y = start->y;

    i = 1;
    while (i <= pixel)
    {
          mlx_pixel_put(env->mlx, env->win, x, y, color);
          x = x + dx;
          y = y + dy;
          i++;
    }
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
