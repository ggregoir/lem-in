/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:34:58 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/07 14:39:22 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

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
//	printf("s->rooms[j][%d] = %d\n", x, s->rooms[j][x]);
	while (s->rooms[j][x] != 0)
	{
		s->rooms[j][x] = s->rooms[j][x + 1];
		x++;
	}
	s->rooms[room][0] = 0;
	x = 0;
	while (s->rooms[j][x] != 0)
	{
		//printf("after delete s->rooms[j][%d] = %d\n", x, s->rooms[j][x]);
		x++;
	}
}

void				delete_single(t_struct *s)
{
	int x;
	int 	i;
	int		j;
	int		*killmepls;

	x = 0;
	i = 1;
	if ((killmepls = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	j = -1;
	while (s->rooms[0][++j] != 0)
		killmepls[s->rooms[0][j]] = 1;
	x = 0;
	//printf("nb rooms = %d\n",s->nbrooms);
	while (++i <= s->nbrooms + 1)
	{
	//	printf("i = %d\n",i );
		if (killmepls[i] == 1)
			//printf("SAMERELAPUTE\n");
		while (s->rooms[i][x] != 0)
		{
			//printf("s->rooms[i][%d] = %d\n", x, s->rooms[i][x]);
			x++;
		}
		x = 0;
		//printf("condition1 = %d\ncondition2 = %d\ncondition3 = %d\n", s->rooms[i][0] != 0, s->rooms[i][1] == 0, killmepls[i] == 0);
		if(s->rooms[i][0] != 0 && s->rooms[i][1] == 0 && killmepls[i] == 0)
		{
			//printf("s->rooms[i][0] = %d\n",s->rooms[i][0]);
			delete_link(s, i);
			killmepls[i] = 1;
			i = 1;
			ft_putendl(s->names[i]);
			//printf("s->rooms[i][0] = %d\n",s->rooms[i][0]);
		}
	}
	free(killmepls);
}
		
