/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:41:15 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/28 20:46:55 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

int				already_path(t_path *p, int curr)
{
	ft_putendl("already_path");
	printf("curr = %d\n", curr);
	int x;
	int y;

	x = 0;
	if (curr == 0)
	{
		while (x != BSIZE)
		{
			p->tmp[x++] = 0;
		}
		printf("APRES BZERO\n");
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
				{
					ft_putendl("ap ret 1 result");
					return(1);
				}
				x++;
			}
			x = 0;
			y++;
		}
	}
	while(p->tmp[x] != 0)
	{
		printf("%d\n",p->tmp[x] );
		if (p->tmp[x] == 1)
			return(0);
		if (p->tmp[x] == curr)
		{
			ft_putendl("ap ret 1 tmp");
			return(1);
		}
		x++;
	}
	ft_putendl("ap ret 0");
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
	printf("coucou\n");
	int x;

	x = 0;
	while (p->tmp[x])
		x++;
	if (p->pathsize[i] > x)
	{
		x = 0;
		printf("hello\n");
		while (p->tmp[x])
		{
			printf("lolilol = %d\n", p->paths[i][x]);
			p->paths[i][x] = p->tmp[x];
			x++;
		}
		p->pathsize[i] = pathsize(i, p);
		printf("NANI ?!\n");
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
		printf("LOLOLOLOLOL\n");
		printf("tmp[0] = %d\n",p->tmp[0]);
		printf("tmp[1] = %d\n",p->tmp[1]);
		printf("tmp[2] = %d\n",p->tmp[2]);
		while (p->tmp[j])
		{
			p->paths[p->x][j] = p->tmp[j];
			j++;
		}
		printf("p->paths[0] = %d\n",p->paths[p->x][0]);
		printf("p->paths[1] = %d\n",p->paths[p->x][1]);
		printf("p->paths[2] = %d\n",p->paths[p->x][2]);
		p->pathsize[p->x] = pathsize(p->x, p);
		p->x++;
		j = 0;
		return ;
	}
	printf("apres while\n");
	while (++x != p->x)
		if (p->pathsize[x] > worst)
			worst = x;
	printf("apres worst\n");
	replace_path(worst, p);
	printf("apres replacepath\n");

}