/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:54:16 by tguillem          #+#    #+#             */
/*   Updated: 2016/06/07 15:45:36 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		compute_pixel_size(t_image *img)
{
	int		line_size;
	int		bits;
	int		endian;

	img->data = mlx_get_data_addr(img->ptr, &bits, &line_size, &endian);
	img->byte_per_pixel = bits / 8;
	img->endian = endian;
	img->line_size = line_size;
}

t_image		*new_img(t_env *env, int width, int height)
{
	t_image *result;

	if ((result = (t_image*)ft_memalloc(sizeof(t_image))))
	{
		result->ptr = mlx_new_image(env->mlx, width, height);
		compute_pixel_size(result);
		return (result);
	}
	return (NULL);
}
