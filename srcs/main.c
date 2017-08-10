/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/10 23:44:30 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

void		init_struct(t_struct *s)
{
	if ((s->rooms = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
		return(error(3));
	if ((s->names = ft_memalloc(sizeof(char*) * BSIZE)) == NULL)
		return(error(3));
	s->ni = 2;
	s->start = 0;
	s->end = 0;

}

int			main()
{
	char		*line;
	t_struct	s;
	int i;

	i = 0;

	init_struct(&s);
	//ft_putendl("ameno");
	while (get_next_line(0, &line) > 0)
	{
		if (line == 0)
			error(0);
		else
		{
			//ft_putendl("line existe");
			parse_line(&s, line);
		}
	}
	while (s.names[i])
	{
		printf("nb = %d nom = %s\n", i, s.names[i]);
		i++;
	}
	return 0;
}
