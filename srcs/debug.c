/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:25:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/11 18:25:42 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		shownames(t_struct *s)
{
	int i;

	i = 0;
	ft_colorendl(HCYAN,"\n		[START SHOW NAMES]\n", EOC);
	while (s->names[i])
	{
		ft_color(HBLUE, "room number ", EOC);
		ft_color(HGREEN, NULL, EOC);
		ft_color(RED,"[", HRED);
		ft_putnbr(i);
		ft_color(EOC, NULL, NULL);
		ft_color(RED,"] ", EOC);
		ft_color(EOC, NULL, NULL);
		ft_color(HBLUE, "name is ", EOC);
		ft_color(RED,"[", HRED);
		ft_color(HGREEN, s->names[i], EOC);
		ft_color(EOC, NULL, NULL);
		ft_colorendl(RED,"] ", EOC);
		i++;
	}
}

void		showlinks(t_struct *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_colorendl(HCYAN,"\n		[START SHOW LINKS]\n", EOC);
	while (i != s->nbrooms)
	{
		ft_color(RED,"[", HRED);
		ft_putnbr(i);
		ft_color(EOC, NULL, NULL);
		ft_color(RED,"] ", EOC);
		ft_color(HBLUE, s->names[i], EOC);
		ft_color(MAGENTA, " link with | ", EOC);
		while(s->rooms[i][j])
		{
			ft_color(GREEN, s->names[s->rooms[i][j]], EOC);
			ft_color(MAGENTA, " | ", EOC);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void		showpaths_while(int i, int j, t_path *p)
{
	while (p->paths[i][j + 1])
		{
			if (j == 0)
			{
				ft_color(RED,"[", HRED);
				ft_putnbr(p->paths[i][j]);
				ft_color(EOC, NULL, NULL);
				ft_color(RED,"] ", EOC);
			}
			else 
			{
				ft_color(BLUE,"[", HBLUE);
				ft_putnbr(p->paths[i][j]);
				ft_color(EOC, NULL, NULL);
				ft_color(BLUE,"] ", EOC);
			}
			ft_color(YELLOW, "-> ", EOC);
			j++;
		}
}

void		showpaths(t_path *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_colorendl(HCYAN,"\n		[START SHOW PATHS]\n", EOC);
	while (i != p->nbpath)
	{
		ft_color(MAGENTA, "path ", EOC);
		ft_color(YELLOW,"[", HYELLOW);
		ft_putnbr(i);
		ft_color(EOC, NULL, NULL);
		ft_color(YELLOW,"] = ", EOC);
		showpaths_while(i, j, p);
		ft_color(GREEN,"[", HGREEN);
		ft_putnbr(p->paths[i][j]);
		ft_color(EOC, NULL, NULL);
		ft_color(GREEN,"]\n", EOC);
		j = 0;
		i++;
	}
}