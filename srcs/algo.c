/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:13:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 15:00:02 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			nb_path(t_struct *s, t_path *p)
{
	int		i;

	i = 0;
	p->nbpath = s->nbfourmi;
	while (s->rooms[0][i])
	{
		if (s->rooms[0][i] == 1)
		{
			p->nbpath = 1;
			return ;
		}
		i++;
	}
	if (p->nbpath > i)
		p->nbpath = i;
	i = 0;
	while (s->rooms[1][i])
		i++;
	if (p->nbpath > i)
		p->nbpath = i;
}

void			init_path(t_path *p, t_struct *s)
{
	int x;

	x = 0;
	if ((p->paths = ft_memalloc(sizeof(int*) * p->nbpath)) == NULL)
		return(error(3, s));
	while (x + 1 <= p->nbpath)
	{
		if ((p->paths[x++] = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
			return(error(3, s));
	}
	if ((p->tmp = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	if ((p->already_path = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	if ((p->pathsize = ft_memalloc(sizeof(int) * p->nbpath)) == NULL)
		return(error(3, s));
	p->i = 0;
	p->pi = 0;
	p->x = 0;
	p->over = 0;
}

void			get_path(t_struct *s, t_path *p, int path)
{
	int best;
	int i;
	int curr;
	int j;

	curr = 1;
	j = -1;
	while (p->weights[curr] != 2)
	{
		i = -1;
		best = 1;
		while (s->rooms[curr][++i] != 0)
			if (p->weights[s->rooms[curr][i]] < p->weights[best] && p->weights[s->rooms[curr][i]] != 0)
				best = s->rooms[curr][i];
		p->tmp[++j] = best;
		curr = best;
	}
	manage_path(path, p, s);
}

void			resolve(t_struct *s, t_path *p)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if ((p->weights = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	delete_single(s);
	nb_path(s, p);
	init_path(p, s);
	while (++i != p->nbpath)
	{
		get_weights(p, s, 0, 1);
		if (i == 1)
			while (j != s->nbrooms)
				j++;
		if (p->over == 1)
		{	
			p->over = 0;
			get_path(s, p, i);
		}
	}
}