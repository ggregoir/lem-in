/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:43:24 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/10 23:03:32 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"

#define BSIZE 1 << 15

typedef struct	s_struct
{	
	char	**names;
	int		ni;
	int		ri;
	int		*rooms;
	char	*b;
	int		bi;
	int		start;
	int		end;
	int		nbfourmi;
}				t_struct;

int				get_next_line(const int fd, char **line);
void			error(int i);
void			parse_line(t_struct *s, char *line);
void			str_buff(t_struct *s, char *str);

#endif
