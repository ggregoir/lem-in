/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:25:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 14:38:47 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char		*get_color(t_ants *a, int i)
{
	int j;

	j = a->apath[i];
	while (j > 9)
		j = (j % 10) + 1;
	if (j == 1)
		return (RED);
	if (j == 2)
		return (HRED);
	if (j == 3)
		return (YELLOW);
	if (j == 4)
		return (HYELLOW);
	if (j == 5)
		return (GREEN);
	if (j == 6)
		return (HGREEN);
	if (j == 7)
		return (HBLUE);
	if (j == 8)
		return (BLUE);
	return (MAGENTA);
}

void		print_turn_color(t_ants *a, t_struct *s)
{
	int i;

	i = 1;

	while (i <= s->nbfourmi)
	{
		if (a->pos[i] > 0 && a->end[i] == 0)
		{
			ft_color(get_color(a, i),"L",NULL);
			ft_putnbr(i);
			write(1, "-", 1);
			ft_putstr(s->names[a->pos[i]]);
			write(1, " ", 1);
			ft_color(NULL, NULL, EOC);
		}
		if (a->pos[i] == 1)
			a->end[i] = 1;
		i++;
	}
	write(1, "\n", 1);
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