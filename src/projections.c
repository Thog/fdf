/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:02:51 by tguillem          #+#    #+#             */
/*   Updated: 2016/03/30 15:58:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		proj_dummy_x(int x, int y, int z)
{
	(void)y;
	(void)z;
	return (x);
}

int		proj_dummy_y(int x, int y, int z)
{
	(void)x;
	(void)z;
	return (y);
}

int		proj_iso_x(int x, int y, int z)
{
	(void)z;
	return (ISO_C1 * x - ISO_C2 * y);
}

int		proj_iso_y(int x, int y, int z)
{
	return (z + ((ISO_C1 * x) / 2) + ((ISO_C2 * y) / 2));
}
