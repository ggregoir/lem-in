/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:55:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/12 02:16:14 by ggregoir         ###   ########.fr       */
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

}
void		handle_command(t_struct *s, char *line)
{
		if (ft_strequ(line ,"##start") == 0 && ft_strequ(line ,"##end") == 0)
		{
			str_buff(s, line);
			error(1);
		}
		else
		{
			ft_putendl("start ou end");
			if (ft_strequ(line ,"##start"))
				s->start = 1;
			if (ft_strequ(line ,"##end"))
				s->end = 1;
		}
}

void		handle_link(t_struct *s, char *line)
{
	int i;
	int j;
	int x;

	x = 0;
	ft_putendl("handle_link");
	if (ft_strchr(line,'-'))
	{
		ft_putendl("link first");
		if ((i = link_first(s, line)) == -1)
			error(4);
		ft_putendl("link second");
		if ((j = link_second(s, line)) == -1)
			error(4);
		printf("assign\n");
		printf("room[i][x] = %d\n",s->rooms[i][x] );
		while (x < BSIZE)
		{
			if (s->rooms[i][x] == 0)
				break;
			x++;
		}
		if (x > BSIZE)
			error(4);
		s->rooms[i][x] = j;
		x = 0;
		while (x < BSIZE)
		{
			if (s->rooms[j][x] == 0)
				break;
			x++;
		}
		if (x > BSIZE)
			error(4);
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
		printf("lol\n");
		while(line[x] && line[x] != ' ' && x < 50)
			x++;
		if (x > 50)
			return(error(0));
		j = x++;
		while (ft_isdigit(line[x]))
			x++;
		if (line[x++] != ' ')
			return(error(1));
		while (ft_isdigit(line[x]))
			x++;
		if (x != (int)ft_strlen(line))
			return(error(0));
		add_name(s, ft_strcut(line, 0, j));
	}
}
void		parse_line(t_struct *s, char *line)
{
	printf("%s\n",line );
	if (line[0] == '#' && line [1] != '#')
		str_buff(s, line);
	ft_putendl("apres comment verif");
	if (s->nbfourmi == 0)
	{
		ft_putendl("get fourmi number");
		if (ft_isdigit(line[0]) == 0)
		{
			ft_putendl("probleme nb fourmi");
			error(0);
		}
		else
		{
			ft_putendl("atoi nb fourmi");
			s->nbfourmi = atoi(line);
			return ;
		}
	}
	if (line[0] == '#' && line [1] == '#')
	{
		ft_putendl("commande detect");
		handle_command(s, line);
		return ;
	}
	ft_putendl("avant handle room");
	handle_room(s, line);
	handle_link(s, line);
}