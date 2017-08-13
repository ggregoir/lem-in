/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:38:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/13 17:46:25 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		check_room(t_struct *s, char *line)
{
	int i;

	i =0;
	while (s->names[i])
		if (ft_strequ(line, s->names[i++]))
			error(3);
}

void		error2(int i)
{
	if (i == 4)
	{
		ft_putendl_fd("link error", 1);
		exit(1);
	}
	if (i == 5)
	{
		ft_putendl_fd("ants error", 1);
		exit(1);
	}
	if (i == 6)
	{
		ft_putendl_fd("malloc error", 1);
		exit(1);
	}
	if (i == 7)
	{
		ft_putendl_fd("rooms error", 1);
		exit(1);
	}
}

void		error(int i)
{
	if (i == 0)
	{
		ft_putendl_fd("input error", 1);
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl_fd("command error", 1);
		exit(1);
	}
	if (i == 2)
	{
		ft_putendl_fd("malloc error", 1);
		exit(1);
	}
	if (i == 3)
	{
		ft_putendl_fd("rooms error", 1);
		exit(1);
	}
	error2(i);
}