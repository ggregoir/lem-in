/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/17 00:26:52 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

void		init_struct(t_struct *s)
{
	int x;

	x = 0;
	if ((s->rooms = ft_memalloc(sizeof(int*) * BSIZE)) == NULL)
		return(error(3, s));
	while (x != BSIZE)
		if ((s->rooms[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return(error(3, s));
	if ((s->names = ft_memalloc(sizeof(char*) * BSIZE)) == NULL)
		return(error(3, s));
	s->ni = 2;
	s->start = 0;
	s->end = 0;
	s->nbfourmi = 0;
	s->print = 1;
	s->safe = 0;
	s->esafe = 0;

}

int			main(int argc, char **argv)
{
	char		*line;
	t_struct	s;
	int i;
	int j;
	int 	fd;

	i = 0;
	j = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	argc = 0;
	init_struct(&s);
	init_buff(&s);
	if (ft_strequ(argv[1], "-mute"))
		s.print = 0;
	if (ft_strequ(argv[1], "-safe"))
		s.safe = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (line == 0)
			error(0, &s);
		else
		{
			//ft_putendl("line existe");
			parse_line(&s, line);
		}
	}
	if (s.esafe == 1)
		willudothis(&s);
	if (s.print == 1)
		print_buff(&s);
	while (s.names[i])
	{
		printf("nb = %d nom = %s\n", i, s.names[i]);
		i++;
	}
	i = 0;
	while (s.rooms[i])
	{
		while(s.rooms[i][j])
		{
			printf("%s link avec %s\n", s.names[i], s.names[s.rooms[i][j]]);
			j++;
		}
		j = 0;
		i++;
	}
	//printf("nbfourmi = %d\n", s.nbfourmi );
	return 0;
}
