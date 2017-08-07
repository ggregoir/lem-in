/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:43:24 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/07 18:56:44 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"

#define BSIZE 1024

typedef struct	s_struct
{
	char	*b;
	int		bi;
	int		start;
	int		end;
	int		fourmi;
}				t_struct;

int				get_next_line(const int fd, char **line);

#endif
