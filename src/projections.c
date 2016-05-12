/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:02:51 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 07:44:29 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		proj_dummy_x(t_pos *pos)
{
	return (pos->x);
}

int		proj_dummy_y(t_pos *pos)
{
	return (pos->y);
}

int		proj_iso_x(t_pos *pos)
{
	return (ISO_C1 * pos->x - ISO_C2 * pos->y);
}

int		proj_iso_y(t_pos *pos)
{
	return (-pos->z + (ISO_C1 / 2) * pos->x + (ISO_C2 / 2) * pos->y);
}
