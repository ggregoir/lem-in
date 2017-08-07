/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:12:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/07 18:30:46 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main(int argc, char **argv)
{
	char *line;
	while (get_next_line(0, &line) > 0)
	{
		if (line == 0)
			error(0);
		else
		{
			parse_line(line);
		}
	}
	return 0;
}
