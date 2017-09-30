/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/30 13:01:31 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		init_struct(t_struct *s)
{
	int x;

	x = 0;
	if ((s->rooms = ft_memalloc(sizeof(int*) * BSIZE)) == NULL)
		return (error(3, s));
	while (x != BSIZE)
		if ((s->rooms[x++] = ft_memalloc(sizeof(int) * BSIZE)) == NULL)
			return (error(3, s));
	if ((s->names = ft_memalloc(sizeof(char*) * BSIZE)) == NULL)
		return (error(3, s));
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
	s->color = 0;
}

void		output(t_struct *s, t_path *p)
{
	if (startendlink(s, p))
		resolve(s, p);
	if (s->name || s->debug)
		shownames(s);
	if (s->link || s->debug)
		showlinks(s);
	if (s->path || s->debug)
		showpaths(p, s);
	if (s->print == 1)
		print_buff(s);
	if (startendlink(s, p))
		print_result(s, p);
	else
		print_start_end(s);
	ft_memdel((void**)s->names);
	ft_memdel((void**)s->rooms);
}

void		handle_tags(t_struct *s, int *fd, int argc, char **argv)
{
	int i;

	i = -1;
	if (ft_strequ(argv[1], "-f"))
	{
		*fd = open(argv[argc - 1], O_RDONLY);
		i = 1;
	}
	while (++i < argc)
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
		if (ft_strequ(argv[i], "--color"))
			s->color = 1;
	}
}

int			main(int argc, char **argv)
{
	char		*line;
	t_struct	s;
	t_path		p;
	int			fd;
	int			ret;

	fd = 0;
	init_struct(&s);
	init_buff(&s);
	handle_tags(&s, &fd, argc, argv);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line == 0)
			error(0, &s);
		else if (ft_strequ(line, "\n"))
			error(7, &s);
		else
			parse_line(&s, line);
		free(line);
	}
	if (ret < 1 && s.nbfourmi == 0)
		error(0, &s);
	output(&s, &p);
	free_struct(&s, &p);
	return (0);
}
