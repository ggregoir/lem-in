/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:02:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/30 13:20:10 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			init_astruct(t_ants *a, t_struct *s, t_path *p)
{
	int i;

	i = 0;
	if ((a->pos = ft_memalloc(sizeof(int) * (s->nbfourmi + 1))) == NULL)
		return (error(3, s));
	if ((a->apath = ft_memalloc(sizeof(int) * (s->nbfourmi + 1))) == NULL)
		return (error(3, s));
	if ((a->apathi = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
		return (error(3, s));
	if ((a->end = ft_memalloc(sizeof(int) * (s->nbfourmi + 1))) == NULL)
		return (error(3, s));
	while (p->paths[i][1] != 0 && i != (p->nbpath - 1))
		i++;
	p->nbpath = i + 1;
}

void			get_ant_path(t_ants *a, t_struct *s, t_path *p, int i)
{
	int j;
	int x;

	j = 0;
	x = 1;
	if (a->apath[i] == 0)
		while (j < p->nbpath)
		{
			while (x != s->nbfourmi)
			{
				if (a->pos[x] == p->paths[j][1])
				{
					j++;
					x = 1;
					break ;
				}
				x++;
			}
			if (x == s->nbfourmi)
			{
				a->apath[i] = j + 1;
				return ;
			}
		}
	return ;
}

void			play_turn_multipass(t_ants *a, t_struct *s, t_path *p)
{
	int i;
	int j;
	int x;

	i = 1;
	j = 0;
	x = 1;
	while (i <= s->nbfourmi)
	{
		get_ant_path(a, s, p, i);
		if (a->apath[i] > 0 && a->pos[i] != 1)
			a->pos[i] = p->paths[a->apath[i] - 1][++a->apathi[i]];
		i++;
	}
}

void			print_turn(t_ants *a, t_struct *s)
{
	int i;

	i = 1;
	while (i <= s->nbfourmi)
	{
		if (a->pos[i] > 0 && a->end[i] == 0)
		{
			write(1, "L", 1);
			ft_putnbr(i);
			write(1, "-", 1);
			ft_putstr(s->names[a->pos[i]]);
			write(1, " ", 1);
		}
		if (a->pos[i] == 1)
			a->end[i] = 1;
		i++;
	}
	write(1, "\n", 1);
}

void			print_result(t_struct *s, t_path *p)
{
	t_ants a;

	init_astruct(&a, s, p);
	while (a.pos[s->nbfourmi] != 1)
	{
		play_turn_multipass(&a, s, p);
		if (s->color == 1)
			print_turn_color(&a, s);
		else
			print_turn(&a, s);
	}
	free(a.pos);
	free(a.apath);
	free(a.apathi);
	free(a.end);
}
