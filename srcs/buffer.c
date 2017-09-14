/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:56:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 15:01:49 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		print_buff(t_struct *s)
{
	write(1, s->b, s->bi);
}

void		init_buff(t_struct *s)
{
	//printf("laul\n");
	ft_bzero(s->b, BUSIZE);
//	printf("lel\n");
}

void		str_buff(t_struct *s, char *str)
{
	int i;

	i = 0;
	if (str == 0)
		return ;
	if (s->bi < BUSIZE)
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
		write(1, s->b, BUSIZE);
		init_buff(s);
	}
}