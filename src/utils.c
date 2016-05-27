/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:59:30 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/27 11:17:10 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_posdata		*data_put(t_posdata *root, t_pos *array)
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

t_pos			*new_pos(int x, int y, int z)
{
	t_pos *result;

	if (!(result = (t_pos*)malloc(sizeof(t_pos))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

static void		destroy_data(t_posdata *data)
{
	t_posdata	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		ft_memdel((void**)&tmp);
	}
}

int				destroy_env(t_env *env)
{
	if (env->render)
	{
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_image(env->mlx, env->render->ptr);
	}
	ft_memdel((void*)&env->render);
	destroy_data(env->data);
	ft_memdel((void*)&env);
	return (EXIT_SUCCESS);
}
