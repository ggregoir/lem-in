/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:55:45 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/08 18:44:57 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		handle_command(t_struct s, char *line)
{
		if (line != "##start" || line != "##end")
			error(1);
		else
		{
			if (ft_strequ(line ,"##start"))
				s->start = 1;
			if (ft_strequ(line ,"##end"))
				s->end = 1;
		}
}

void		handle_link(t_struct s, char *line)
{
	
}

void		handle_room(t_struct s, char *line)
{
	int x;
	int j;

	x = 0;
	if (line[0] != ' ' || line[0] != 'L'|| line[0] != '#' || line[x] != '-' )
	{	
		while(line[x])
		{
			while(line[x] != ' ' || x > 50)
			{
				x++;
			}
			if (x > 50)
				return ;
			j = x;
			x++;
		}


	}
}
void		parse_line(t_struct s, char *line)
{
	if (line[0] == '#' && line [1] != '#')
		str_buff(line);
	if (s->nbfourmi = 0)
	{
		if (ft_isdigit(line[0]) == 0)
			error(1);
		else
		{
			s->nbfourmi = atoi(line[0])
		}
	}
	if (line[0] == '#' && line [1] == '#')
		handle_command(line;)
	handle_room(s, line);
	handle_link(s, line);


}