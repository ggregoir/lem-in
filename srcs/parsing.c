/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:55:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/30 13:03:28 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		handle_command(t_struct *s, char *line)
{
	if (ft_strequ(line, "##start"))
		s->start = 1;
	else if (ft_strequ(line, "##end"))
		s->end = 1;
	else if (ft_strequ(line, "##mute"))
		s->print = 0;
	else if (ft_strequ(line, "##safe"))
		s->safe = 1;
	else if (ft_strequ(line, "##color"))
		s->color = 1;
	else if (s->safe == 1)
		error(1, s);
}

void		handle_link2(t_struct *s, int *i, int *j)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++x < BSIZE)
		if (s->rooms[*j][x] == 0)
			break ;
	if (x > BSIZE)
		error(4, s);
	while (s->rooms[*j][++y] != 0)
		if (s->rooms[*j][y] == *j)
			*i = 0;
	s->rooms[*j][x] = *i;
}

void		handle_link(t_struct *s, char *line)
{
	int i;
	int j;
	int x;
	int y;

	x = -1;
	y = -1;
	if (ft_strchr(line, '-'))
	{
		if ((i = link_first(s, line)) == -1)
			return (error(8, s));
		if ((j = link_second(s, line)) == -1)
			return (error(8, s));
		while (++x < BSIZE)
			if (s->rooms[i][x] == 0)
				break ;
		if (x > BSIZE)
			error(4, s);
		while (s->rooms[i][++y] != 0)
			if (s->rooms[i][y] == j)
				j = 0;
		s->rooms[i][x] = j;
		handle_link2(s, &i, &j);
	}
}

void		handle_room(t_struct *s, char *line, int x, int j)
{
	char *atfree;

	if (line[0] == 'L' || line[0] == ' ')
		error(0, s);
	if (line[0] != '#' && !ft_strchr(line, '-'))
	{
		while (line[x] && line[x] != ' ' && x < 100)
			x++;
		x > 100 ? error(0, s) : 1;
		j = x++;
		while (line[x] == ' ')
			x++;
		while (ft_isdigit(line[x]))
			x++;
		while (line[x] == ' ')
			x++;
		while (ft_isdigit(line[x]))
			x++;
		x != (int)ft_strlen(line) ? error(0, s) : 1;
		check_room(s, (atfree = ft_strcut(line, 0, j)));
		free(atfree);
		add_name(s, ft_strcut(line, 0, j));
	}
	if (s->start || s->end)
		error(3, s);
}

void		parse_line(t_struct *s, char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (str_buff(s, line));
	else
		str_buff(s, line);
	if (s->nbfourmi == 0)
	{
		if (ft_isdigit(line[0]) == 0)
			error(5, s);
		else
		{
			if ((s->nbfourmi = atoi(line)) <= 0)
				error(5, s);
			return ;
		}
	}
	s->nbfourmi > BSIZE - 1 ? error(5, s) : 1;
	if (line[0] == '\0')
		return (error(7, s));
	else if (line[0] == '#' && line[1] == '#')
		return (handle_command(s, line));
	if (!ft_strchr(line, '#'))
	{
		handle_room(s, line, 0, 0);
		handle_link(s, line);
	}
}
