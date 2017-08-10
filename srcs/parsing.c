/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:55:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/10 23:44:44 by ggregoir         ###   ########.fr       */
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
			if (ft_strequ(line ,"##start"))
				s->start = 1;
			if (ft_strequ(line ,"##end"))
				s->end = 1;
		}
}

//void		handle_link(t_struct s, char *line)
//{
	
//}

void		handle_room(t_struct *s, char *line)
{
	int x;
	int j;

	x = 0;
	j = 0;
	if (*line != ' ' && *line != 'L' && *line != '#' && !ft_strchr(line,'-'))
	{	
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
	if (line[0] == '#' && line [1] != '#')
		str_buff(s, line);
	if (s->nbfourmi == 0)
	{
		if (ft_isdigit(line[0]) == 0)
			error(0);
		else
		{
			s->nbfourmi = atoi(line);
			return ;
		}
	}
	if (line[0] == '#' && line [1] == '#')
	{
		handle_command(s, line);
		return ;
	}
	handle_room(s, line);
}