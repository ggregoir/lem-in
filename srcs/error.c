/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:38:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/08 18:48:01 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		error(int i)
{
	if (i == 0)
		ft_putendl_fd("input error", 1);
	if (i == 1)
		ft_putendl_fd("command error", 1);
	if (i == 3)
		ft_putendl_fd("malloc error", 1);

}