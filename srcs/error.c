/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:38:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/11 22:35:54 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		error(int i)
{
	if (i == 0)
	{
		ft_putendl_fd("input error", 1);
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl_fd("command error", 1);
		exit(1);
	}
	if (i == 2)
	{
		ft_putendl_fd("malloc error", 1);
		exit(1);
	}
	if (i == 3)
	{
		ft_putendl_fd("rooms error", 1);
		exit(1);
	}
	if (i == 4)
	{
		ft_putendl_fd("link error", 1);
		exit(1);
	}
}