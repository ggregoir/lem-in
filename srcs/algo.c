/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:13:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/24 18:32:04 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	nb_path(t_struct *s, t_path *p)
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

void	init_path(t_path *p, int ***paths)
{
	if ((p->paths = ft_memalloc(sizeof(int*) * p->nbpath)) == NULL)
		return(error(3, s));
	while (x + 1 <= p->nbpath)
		if ((p->paths[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return(error(3, s));
}

void	get_path(t_struct *s, t_path *p, int i, int j)
{
	while (t->rooms[i][j] != 1)
	{
		
	}
}

void	resolve(t_struct *s, t_path *p)
{

	init_path(p)

}