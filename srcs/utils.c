/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 00:18:25 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 14:59:19 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

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
	int i;
	int j;

	i = 0;
	while (line[i] != '-')
		i++;
	j = 0;
	//ft_putendl("before while");
	while (s->names[j])
	{
		//printf("||%s||%s||\n",ft_strcut(line, 0, i), s->names[j]);
		if (ft_strequ(s->names[j] ,ft_strcut(line, 0, i )))
			return(j);
		j++;
	}
	//ft_putendl("after while");
	return(-1);
}

int			link_second(t_struct *s, char *line)
{
	int i;
	int j;

	i = 0;
	while (line[i] != '-')
		i++;
	j = 0;
	//ft_putendl("before while");
	while (s->names[j])
	{
		//printf("%s||%s||\n",ft_strcut(line, i + 1, ft_strlen(line)), s->names[j]);
		if (ft_strequ(s->names[j] ,ft_strcut(line, i + 1, ft_strlen(line))))
			return(j);
		j++;
	}
	//ft_putendl("after while");
	return(-1);
}

size_t		ft_strlenchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}