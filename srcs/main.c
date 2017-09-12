/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/12 22:54:41 by ggregoir         ###   ########.fr       */
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
	s->nbrooms = 2;
	s->name = 0;
	s->path = 0;
	s->link = 0;
	s->debug = 0;

}

void		output(t_struct *s, t_path *p)
{
	if (s->print == 1)
		print_buff(s);
	resolve(s, p);
	if (s->name || s->debug)
		shownames(s);
	if (s->link || s->debug)
		showlinks(s);
	if (s->path || s->debug)
		showpaths(p);
	print_result(s, p);
}

void		handle_tags(t_struct *s, int *fd, int argc, char **argv)
{
	int i;

	i = 0;
	if (ft_strequ(argv[1], "-f"))
	{
		*fd = open(argv[argc - 1], O_RDONLY);
		i = 2;
	}
	while (i < argc)
	{
		if (ft_strequ(argv[i], "--mute"))
			s->print = 0;
		if (ft_strequ(argv[i], "--safe"))
			s->safe = 1;
		if (ft_strequ(argv[i], "--names"))
			s->name = 1;
		if (ft_strequ(argv[i], "--links"))
			s->link = 1;
		if (ft_strequ(argv[i], "--paths"))
			s->path = 1;
		if (ft_strequ(argv[i], "--debug"))
			s->debug = 1;
		i++;
	}
}

int			main(int argc, char **argv)
{
	char		*line;
	t_struct	s;
	t_path 		p;
	int			i;
	int 		fd;

	i = 0;
	fd = 0;
	init_struct(&s);
	init_buff(&s);
	handle_tags(&s, &fd, argc, argv);
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
	output(&s, &p);
	return 0;
}
