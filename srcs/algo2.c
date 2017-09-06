/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:41:15 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/06 16:48:56 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

int				already_path(t_path *p, int curr)
{
	//write(1,"bzb\n", 4);
	int x;
	int y;
	x = 0;
	if (curr == 0)
	{
		while (x != BSIZE)
		{
			p->tmp[x++] = 0;
		}
	}
	x = 0;
	y = 0;
	if(curr != 1)
	{
		while (y != p->nbpath)
		{
			while(p->paths[y][x])
			{
				if(p->paths[y][x] == curr)
					return(1);
				x++;
			}
			x = 0;
			y++;
		}
	}
	while(p->tmp[x] != 0)
	{
		if (p->tmp[x] == 1)
			return(0);
		if (p->tmp[x] == curr)
			return(1);
		x++;
	}
	return (0);
}

int				pathsize(int j, t_path *p)
{
	int i;

	i = 0;
	while (p->paths[j][i])
		i++;
	return (i);
}
void			replace_path(int i, t_path *p)
{
	int x;

	x = 0;
	while (p->tmp[x])
		x++;
	if (p->pathsize[i] > x)
	{
		x = 0;
		while (p->tmp[x])
		{
			p->paths[i][x] = p->tmp[x];
			x++;
		}
		p->pathsize[i] = pathsize(i, p);
	}
}

void			manage_path(t_path *p)
{
	int x;
	int j;
	int worst;

	j = 0;
	x = -1;
	while (p->x != p->nbpath)
	{
		while (p->tmp[j])
		{
			p->paths[p->x][j] = p->tmp[j];
			j++;
		}
		p->pathsize[p->x] = pathsize(p->x, p);
		p->x++;
		j = 0;
		return ;
	}
	while (++x != p->x)
		if (p->pathsize[x] > worst)
			worst = x;
	replace_path(worst, p);
}