/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/17 14:40:50 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

static void	draw_line1(int nbr[2], int error[2], t_pos *p2, int n)
{
	if ((error[0] << 1) >= n)
	{
		nbr[0] += (p2->x - nbr[0]) >= 0 ? 1 : -1;
		error[0] -= n;
	}
	if ((error[1] << 1) >= n)
	{
		nbr[1] += (p2->y - nbr[1]) >= 0 ? 1 : -1;
		error[1] -= n;
	}
}

void		draw_line_2d(t_env *env, t_pos *p1, t_pos *p2, int color)
{
	int i;
	int n;
	int nbr[2];
	int error[2];
	int delta[2];

	i = -1;
	nbr[0] = p1->x;
	nbr[1] = p1->y;
	delta[0] = (p2->x - p1->x) < 0 ? -(p2->x - p1->x) : (p2->x - p1->x);
	delta[1] = (p2->y - p1->y) < 0 ? -(p2->y - p1->y) : (p2->y - p1->y);
	n = delta[0] > delta[1] ? delta[0] : delta[1];
	ft_bzero(error, sizeof(error));
	while (++i < n)
	{
		put_pixel(env, nbr[0], nbr[1], color + 0x020202 * ft_min(i, W_SC));
		error[0] += delta[0];
		error[1] += delta[1];
		draw_line1(nbr, error, p2, n);
	}
}

void		draw_line_3d(t_env *env, t_pos *start, t_pos *end, int color)
{
	t_pos	*tmp1;
	t_pos	*tmp2;

	if (!start || !end)
		return ;
	tmp1 = new_pos(proj_iso_x(start), proj_iso_y(start), start->z);
	tmp2 = new_pos(proj_iso_x(end), proj_iso_y(end), end->z);
	draw_line_2d(env, tmp1, tmp2, color);
	free(tmp1);
	free(tmp2);
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

t_posdata	*data_put(t_posdata *root, t_pos *array)
{
	t_posdata		*result;
	t_posdata		*tmp;

	tmp = root;
	if (!(result = (t_posdata*)ft_memalloc(sizeof(t_posdata))))
		return (NULL);
	result->data = array;
	result->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = result;
		return (root);
	}
	return (result);
}
