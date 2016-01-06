/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:07:04 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/06 13:33:14 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))) || !(env->mlx = mlx_init()) ||
			!(env->win = mlx_new_window(env->mlx, 1240, 1240, "fdf")))
		return (1);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	free(env);
	return (0);
}
