/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/29 23:21:06 by ggregoir         ###   ########.fr       */
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
	{
		if ((s->rooms[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return(error(3, s));
		//ft_memset(s->rooms[x++], -1, BSIZE);
	}

	if ((s->names = ft_memalloc(sizeof(char*) * BSIZE)) == NULL)
		return(error(3, s));
	s->ni = 2;
	s->start = 0;
	s->end = 0;
	s->nbfourmi = 0;
	s->print = 1;
	s->safe = 0;

}



int			main(int argc, char **argv)
{
	char		*line;
	t_struct	s;
	t_path 		p;
	int i;
	int j;
	int 	fd;

	i = 0;
	j = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	argc = 0;
	ft_putendl("lol");
	init_struct(&s);
	init_buff(&s);
	ft_putendl("lal");
	if (ft_strequ(argv[1], "-mute"))
		s.print = 0;
	if (ft_strequ(argv[1], "-safe"))
		s.safe = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (line == 0)
			error(0, &s);
		else if (ft_strequ(line, "\n"))
			error(7, &s);
		else
		{
			//printf("safemode = %d\n", s.safe);
			parse_line(&s, line);
		}
	}
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
	resolve(&s, &p);
	printf("nb path = %d\n", p.nbpath);
	i = 1;
	j = 0;
	while (j != 5)
	{
		printf("path = %d\n",p.paths[0][j++]);
	}
	j = 0;
	while (j != 5)
	{
		printf("path = %d\n",p.paths[1][j++]);
	}
	j = 0;
	while (j != 5)
	{
		printf("path = %d\n",p.paths[2][j++]);
	}
	return 0;
}
