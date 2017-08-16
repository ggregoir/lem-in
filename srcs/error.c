/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:38:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/17 01:00:16 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		willudothis(t_struct *s)
{
	int i;
	char *line;

	i = 0;
	ft_putendl_fd("Shit gone wrong, will you continue ? (\"yes\" or \"no\")", 1);
	while (i != 1)
	{
		if (ft_gnl(0, &line) > 0)
		{
			if (ft_strequ(line ,"no"))
				error(6, s);
			if (ft_strequ(line ,"yes"))
				i = 1;
		}
		ft_putendl_fd("you typed the wrong word you dumb motherfucker...", 1);
	}
	s->print = 1;
}

void		check_room(t_struct *s, char *line)
{
	int i;

	i =0;
	while (s->names[i])
		if (ft_strequ(line, s->names[i++]))
			error(3, s);
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
		ft_putendl_fd("safemode error", 1);
		exit(1);
	}
	if (i == 7)
	{
		ft_putendl_fd("rooms error", 1);
		exit(1);
	}
}

void		error(int i, t_struct *s)
{
	if (i == 0)
	{
		ft_putendl_fd("input error", 1);
		exit(1);
	}
	if (i == 1)
	{
		if (s->safe == 1)
			s->esafe = 1;
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