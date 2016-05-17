/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:16 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/13 14:41:40 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*compute_pixel_size(t_env *env)
{
	void	*result;
	int		line_size;
	int		bits;
	int		endian;

	mlx_get_data_addr(env->render_cache, &bits, &line_size, &endian);
	env->byte_per_pixel = bits / 8;
	return (result);
}
