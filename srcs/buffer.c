/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:56:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/10 19:18:15 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		init_buff(t_struct *s)
{
	int i;

	s->bi = 0;
	i = 0;
	while (i != BSIZE)
	{
		s->b[i] = '\0';
		i++;
	}
}

void		str_buff(t_struct *s, char *str)
{
	int i;

	i = 0;
	if (str == 0)
		return ;
	if (s->bi < BSIZE)
	{
		while (str[i])
		{
			s->b[s->bi] = str[i];
			i++;
			s->bi++;
		}
		s->b[s->bi] = '\n';
		s->bi++;
	}
	else
	{
		write(1, s->b, BSIZE);
		init_buff(s);
	}
}