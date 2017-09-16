/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:34:58 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/16 17:07:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void				free_struct(t_struct *s, t_path *p)
{
	int i;

	i = 0;
	while (i != BSIZE)
	{
		if (i < p->nbpath)
			free(p->paths[i]);
		free(s->rooms[i]);
		free(s->names[i]);
		i++;
	}
	free(s->rooms);
	free(s->names);
	free(p->paths);
	free(p->already_path);
	free(p->pathsize);
	free(p->tmp);
	free(p->weights);
}

void				delete_link(t_struct *s, int room)
{
	int			j;
	int			x;

	x = 0;
	j = s->rooms[room][0];
	while (s->rooms[j][x] != room)
	{
		x++;
	}
	while (s->rooms[j][x] != 0)
	{
		s->rooms[j][x] = s->rooms[j][x + 1];
		x++;
	}
	s->rooms[room][0] = 0;
	x = 0;
	while (s->rooms[j][x] != 0)
		x++;
}

void				delete_single(t_struct *s)
{
	int		i;
	int		j;
	int		*killmepls;

	i = 1;
	if ((killmepls = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return (error(3, s));
	j = -1;
	while (s->rooms[0][++j] != 0)
		killmepls[s->rooms[0][j]] = 1;
	while (++i <= s->nbrooms + 1)
	{
		if (killmepls[i] == 1)
			if (s->rooms[i][0] != 0 && s->rooms[i][1] == 0 && killmepls[i] == 0)
			{
				delete_link(s, i);
				killmepls[i] = 1;
				i = 1;
			}
	}
	free(killmepls);
}
