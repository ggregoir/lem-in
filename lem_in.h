/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:43:24 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/17 00:01:01 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"

#define BSIZE 2000
#define BUSIZE 1 << 15

typedef struct	s_struct
{	
	char		**names;
	int			ni;
	int			ri;
	int			**rooms;
	char		b[1 << 15];
	int			bi;
	int			start;
	int			end;
	int			nbfourmi;
	int			print;
	int			safe;
	int			esafe;
}				t_struct;

typedef struct	s_line
{
	char			*tab;
	int				fd;
	struct s_line	*next;
}				t_line;

int				get_next_line(const int fd, char **line);
void			error(int i, t_struct *s);
void			parse_line(t_struct *s, char *line);
void			str_buff(t_struct *s, char *str);
char			*ft_strjoin_and_free(char *s1, char *s2, char c, int at);
size_t			ft_strlenchr(const char *s, char c);
int				link_first(t_struct *s, char *line);
int				link_second(t_struct *s, char *line);
void			init_buff(t_struct *s);
void			print_buff(t_struct *s);
void			check_room(t_struct *s, char *line);
void			willudothis(t_struct *s);

#endif
