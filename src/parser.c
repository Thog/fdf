/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 07:38:22 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 10:28:16 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_file(char *file, t_env *e)
{
	int		fd;
	int		i;
	char	*line;
	char	**tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error_retint("File not found\n", 1));
	while ((i = get_next_line(fd, &line)) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		i = 0;
		while (*(tmp + i))
		{
			e->data = data_put(e->data, new_pos(i, e->y, ft_atoi(tmp[i])));
			i++;
		}
		e->x = i;
		e->y++;
	}
	return (0);
}

int			init_data(t_env *env, int ac, char **av)
{
	int	ret;

	env->x = 0;
	env->y = 0;
	env->data = NULL;
	if (ac != 2)
		return (ft_error_retint("Invalid args\nUsage: ./fdf file.fdf\n", 1));
	if ((ret = parse_file(av[1], env)) || !(env->modifier = new_pos(0, 0, 0)))
		return (1);
	return (0);
}
