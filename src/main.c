/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:07:04 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/20 15:16:15 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))) ||
			!(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, 480, 480, "fdf")))
		return (1);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	free(env);
	return (0);
}
