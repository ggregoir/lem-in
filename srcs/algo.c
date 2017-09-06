/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:13:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/06 16:48:35 by ggregoir         ###   ########.fr       */
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
	while (x + 1 <= p->nbpath)
	{
		if ((p->paths[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return(error(3, s));
	}
	if ((p->tmp = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
		return(error(3, s));
	if ((p->already_path = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
		return(error(3, s));
	if ((p->pathsize = ft_memalloc(sizeof(int) * p->nbpath)) == NULL)
		return(error(3, s));
	p->i = 0;
	p->pi = 0;
	p->x = 0;
}

void			get_path(t_struct *s, t_path *p, int curr, int last)
{
	//write(1,"lol\n", 4);
	int j;
	j = 0;


	if (s->rooms[curr][j] < 1)
	{
		write(1,"ntm fdp\n", 8);
		return ;
	}

	write(1,"curr\n", 5);
	ft_putnbr(curr);
	write(1,"\nlol", 4);
	ft_putnbr(s->rooms[curr][j]);
	write(1,"lol\n", 4);
	write(1,"lol", 4);
	while(p->tmp[j] > 0)
	{
		ft_putnbr(p->tmp[j++]);
		write(1, " ", 1);
	}
	j = 0;
	write(1,"lol\n", 4);
	if (already_path(p, curr))
		{
		//	write(1,"lal\n", 4);
			ft_putnbr(p->i);
			p->tmp[p->i] = 0;
			p->i--;
			//write(1,"lql\n", 4);
			//printf("return already path\n");
			return ;
		}
	//write(1,"lel\n", 4);
	//write(1,"lbl\n", 4);
	while (s->rooms[curr][j] != 0)
	{
		//write(1,"lil\n", 4);
		if (s->rooms[curr][j] == last)
			j++;
		//write(1,"lwl\n", 4);
		if (curr > 0)
			p->tmp[p->i++] = curr;
		//write(1,"lgl\n", 4);
		if (s->rooms[curr][j] == 1)
		{
			manage_path(p);
			p->tmp[p->i] = 0;
			p->i--;
			return ;
		}
		/*if(last != 0 && s->rooms[curr][0] > 0 && s->rooms[curr][1] == 0)
		{
			printf("LOLILOL\n");
			p->tmp[p->i] = 0;
			p->i--;
			return ;
		}*/
		//write(1,"lzl\n", 4);
		get_path(s, p, s->rooms[curr][j], curr);
		//write(1,"lpl\n", 4);
		j++;	
	}
	p->tmp[p->i] = 0;
	p->i--;
	return ;
}

void			resolve(t_struct *s, t_path *p)
{
	//delete_single(s);
	nb_path(s, p);
	init_path(p, s);
	get_path(s, p, 0 ,0);
}