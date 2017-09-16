/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:41:15 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/16 16:44:48 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			get_weights(t_path *p, t_struct *s, int curr, int dist)
{
	int i;

	i = 0;
	if (p->already_path[curr] && curr != 1)
		return ;
	if (p->weights[curr] != 0 && p->weights[curr] <= dist)
		return ;
	p->weights[curr] = dist;
	while (s->rooms[curr][i] != 0)
	{
		get_weights(p, s, s->rooms[curr][i], dist + 1);
		i++;
	}
	if (curr == 1)
	{
		p->over = 1;
		return ;
	}
}

int				startendlink(t_struct *s, t_path *p)
{
	int i;

	i = 0;
	while (s->rooms[0][i] > 0)
	{
		if (s->rooms[0][i] == 1)
		{
			p->sel = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int				pathsize(int j, t_path *p)
{
	int i;

	i = 0;
	while (p->paths[j][i])
		i++;
	return (i);
}

void			add_path_reset_weights(t_path *p, t_struct *s, int path)
{
	int	j;

	j = 0;
	while (p->paths[path][++j])
		p->already_path[p->paths[path][j]] = 1;
	j = 0;
	p->already_path[1] = 0;
	while (j != s->nbrooms)
		p->weights[j++] = 0;
}

void			manage_path(int i, t_path *p, t_struct *s)
{
	int x;
	int j;

	j = 0;
	x = 0;
	while (p->tmp[x])
		x++;
	while (x != -1)
	{
		p->paths[i][j] = p->tmp[x];
		x--;
		j++;
	}
	p->paths[i][j] = 1;
	add_path_reset_weights(p, s, i);
	pathsize(i, p);
}
