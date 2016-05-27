/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:07:04 by tguillem          #+#    #+#             */
/*   Updated: 2016/05/27 11:11:03 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))) || init_data(env, ac, av))
		return (1);
	init_display(env);
	return (destroy_env(env));
}
