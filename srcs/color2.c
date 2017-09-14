/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:04:26 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 14:05:16 by ggregoir         ###   ########.fr       */
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
