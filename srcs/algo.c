/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:13:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/29 23:23:59 by ggregoir         ###   ########.fr       */
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
	ft_putendl("avant while");
	while (x + 1 <= p->nbpath)
	{
		if ((p->paths[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return(error(3, s));
		ft_putendl("avant memset");
		ft_memset(p->paths[x++], -1, BSIZE);
		ft_putendl("apres memset");
	}
	ft_putendl("apres while");
	if ((p->tmp = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
		return(error(3, s));
	if ((p->pathsize = ft_memalloc(sizeof(int) * p->nbpath)) == NULL)
		return(error(3, s));
	ft_putendl("apres mallocs");
	p->i = 0;
	p->pi = 0;
}

void			get_path(t_struct *s, t_path *p, int curr, int last)
{
	int 	j;
ft_putendl("get_path");
	j = 0;
	if (curr == 1)
		return (manage_path(p));
	while (s->rooms[curr][j] != 0 && s->rooms[curr][j] != last)
	{
		ft_putendl("dans le while");
		if (curr == 0 || already_path(p, curr))
			return ;
		p->tmp[p->i++] = s->rooms[curr][j];
		get_path(s, p, s->rooms[curr][j], curr);
		j++;
	}
	p->tmp[p->i] = -1;
	p->pi--;
	return ;
}

void			resolve(t_struct *s, t_path *p)
{
	ft_putendl("resolve");
	nb_path(s, p);
	ft_putendl("apres nb_path");
	init_path(p, s);
	ft_putendl("apres init_path");
	get_path(s, p, 0 ,0);
}