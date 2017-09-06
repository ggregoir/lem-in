/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:55:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/06 17:22:29 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include	<stdio.h>

void		add_name(t_struct *s, char *str)
{
	if (s->start == 1)
	{
		s->names[0] = str;
		s->start = 0;
		return ;
	}
	if (s->end == 1)
	{
		s->names[1] = str;
		s->end = 0;
		return ;
	}
	s->names[s->ni++] = str;
	s->nbrooms++;

}
void		handle_command(t_struct *s, char *line)
{

//			ft_putendl("start ou end");
	if (ft_strequ(line ,"##start"))
		s->start = 1;
	else if (ft_strequ(line ,"##end"))
		s->end = 1;
	else if (ft_strequ(line ,"##mute"))
		s->print = 0;
	else if (ft_strequ(line ,"##safe"))
		s->safe = 1;
	else
		if (s->safe ==1)
			error(1, s);

}

void		handle_link(t_struct *s, char *line)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = - 1;
	ft_putendl("handle_link");
	if (ft_strchr(line,'-'))
	{
		ft_putendl("link first");
		if ((i = link_first(s, line)) == -1)
		{
			ft_putendl("ayyyyy lmao");
			return (error(8, s));
		}
		ft_putendl("link second");
		if ((j = link_second(s, line)) == -1)
			return (error(8, s));
		printf("assign\n");
		while (x < BSIZE)
		{
			if (s->rooms[i][x] == 0)
				break;
			x++;
		}
		if (x > BSIZE)
			error(4, s);
		while (s->rooms[i][++y] != 0)
			if (s->rooms[i][y] == j)
				j = 0;
			y = -1;
		s->rooms[i][x] = j;
		printf("room[i][x] = %d\n",s->rooms[i][x] );
		x = 0;
		while (x < BSIZE)
		{
			if (s->rooms[j][x] == 0)
				break;
			x++;
		}
		if (x > BSIZE)
			error(4, s);
		while (s->rooms[j][++y] != 0)
			if (s->rooms[j][y] == j)
				i = 0;
		s->rooms[j][x] = i;
	}
}

void		handle_room(t_struct *s, char *line)
{
	int x;
	int j;

	x = 0;
	j = 0;
	if (*line != ' ' && *line != 'L' && *line != '#' && !ft_strchr(line,'-'))
	{	
		//printf("lol\n");
		while(line[x] && line[x] != ' ' && x < 50)
			x++;
		if (x > 50)
			return(error(0, s));
		j = x++;
		while (ft_isdigit(line[x]))
			x++;
		if (line[x++] != ' ')
			return(error(0, s));
		while (ft_isdigit(line[x]))
			x++;
		if (x != (int)ft_strlen(line))
			return(error(0, s));
		check_room(s, ft_strcut(line, 0, j));
		add_name(s, ft_strcut(line, 0, j));
	}
	if (s->start || s->end)
		error(3, s);
	//ft_putendl("lolilolololilolilol");
}
void		parse_line(t_struct *s, char *line)
{
	str_buff(s, line);
	ft_putendl(line);
	if (s->nbfourmi == 0)
	{
		ft_putendl("get fourmi number");
		if (ft_isdigit(line[0]) == 0)
		{
			ft_putendl("probleme nb fourmi");
			error(5, s);
		}
		else
		{
			ft_putendl("atoi nb fourmi");
			if ((s->nbfourmi = atoi(line)) <= 0)
				error(5, s);
			return ;
		}
	}
	if (line[0] == '\0')
	{
		error(7, s);
		return ;
	}
	else if (line[0] == '#' && line [1] == '#')
	{
		ft_putendl(line);
		handle_command(s, line);
		return ;
	}
	ft_putendl("avant handle room");
	if (!ft_strchr(line,'#'))
	{
		handle_room(s, line);
		handle_link(s, line);
	}
	ft_putendl("ptdr");
}