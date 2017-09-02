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
#include <stdio.h>

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
		//ft_memset(p->paths[x++], -1, BSIZE);
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
	p->x = 0;
}

void			get_path(t_struct *s, t_path *p, int curr, int last)
{
	int x = 0;
	int 	j;
	printf("curr = %d\n", curr);
	j = 0;
	if (curr == 1)
	{
		ft_putendl("chemin trouvé");
		j = 0;
		manage_path(p);
		printf("tmp[0] = %d\n",p->tmp[p->i]);
		p->tmp[p->i] = 0;
		p->i--;
		printf("tmp[0] = %d\n",p->tmp[0]);
		printf("tmp[1] = %d\n",p->tmp[1]);
		printf("tmp[2] = %d\n",p->tmp[2]);
		return ;
	}
	printf("room = %d\n", s->rooms[curr][j]);
	while (s->rooms[curr][j] != 0 && s->rooms[curr][j] != last)
	{
		ft_putendl("dans le while");
		if (already_path(p, s->rooms[curr][j]))
		{
			while(p->tmp[x])
				printf("tmp = %d\n",p->tmp[x++]);
			x = 0;
			return ;
		}
		ft_putendl("apres le return");
		p->tmp[p->i++] = s->rooms[curr][j];
		get_path(s, p, s->rooms[curr][j], curr);
		j++;
	}
	p->tmp[p->i] = 0;
	p->i--;
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
	ft_putendl("apres get_path");
}