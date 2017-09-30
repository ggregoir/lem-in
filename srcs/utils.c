/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:18:25 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/30 13:17:53 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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
	s->nbrooms++;
	if (s->nbrooms == BSIZE - 1)
		error(3, s);
}

char		*ft_strjoin_and_free(char *s1, char *s2, char c, int at)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlenchr(s2, c);
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != c)
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (at == 1 || at == 3)
		ft_strdel(&s1);
	if (at == 2 || at == 3)
		ft_strdel(&s2);
	return (ret);
}

int			link_first(t_struct *s, char *line)
{
	int		i;
	int		j;
	char	*atfree;

	i = 0;
	while (line[i] != '-')
		i++;
	j = 0;
	while (s->names[j])
	{
		if (ft_strequ(s->names[j], (atfree = ft_strcut(line, 0, i))))
		{
			free(atfree);
			return (j);
		}
		free(atfree);
		j++;
	}
	return (-1);
}

int			link_second(t_struct *s, char *line)
{
	int		i;
	int		j;
	char	*atfree;

	i = 0;
	while (line[i] != '-')
		i++;
	j = 0;
	while (s->names[j])
	{
		if (ft_strequ(s->names[j],
			(atfree = ft_strcut(line, i + 1, ft_strlen(line)))))
		{
			free(atfree);
			return (j);
		}
		free(atfree);
		j++;
	}
	return (-1);
}

size_t		ft_strlenchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
