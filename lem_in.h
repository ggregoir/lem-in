/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:43:24 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 15:00:18 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/includes/libft.h"

# define BSIZE	8192
# define BUSIZE	1 << 15

typedef struct	s_struct
{	
	char		**names;
	int			ni;
	int			ri;
	int			**rooms;
	int			nbrooms;
	char		b[BUSIZE];
	int			bi;
	int			start;
	int			end;
	int			nbfourmi;
	int			print;
	int			safe;
	int			link;
	int			path;
	int			name;
	int			debug;
	int 		color;
}				t_struct;

typedef	struct	s_path
{
	int			start;
	int			nbpath;
	int			**paths;
	int			*tmp;
	int			*already_path;
	int			*weights;
	int			*pathsize;
	int			over;
	int			i;
	int			pi;
	int			x;
}				t_path;

typedef	struct	s_ants
{
	int			*pos;
	int			*apath;
	int			*apathi;
	int 		*end;
}				t_ants;

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
void			willudothis(t_struct *s, char *str);
void			nb_path(t_struct *s, t_path *p);
int				already_path(t_path *p, int curr);
void			resolve(t_struct *s, t_path *p);
void			delete_single(t_struct *s);
void			get_weights(t_path *p, t_struct *s, int curr, int dist);
void			manage_path(int i, t_path *p, t_struct *s);
void			add_path_reset_weights(t_path *p, t_struct *s, int path);
void			showpaths(t_path *p);
void			showlinks(t_struct *s);
void			shownames(t_struct *s);
void			print_result(t_struct *s, t_path *p);
void			print_turn_color(t_ants *a, t_struct *s);

#endif
