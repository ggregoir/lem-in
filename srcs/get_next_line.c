/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:49:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/05 18:56:21 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				check_line(char **str, char **line, int rt)
{
	char		*tmp;
	int			i;
	char		*at_free;

	i = 0;
	if ((tmp = ft_strchr(*str, '\n')) || rt < BUFF_SIZE)
	{
		at_free = *str;
		if (!tmp)
			*line = ft_strdup(*str);
		else
			*line = ft_strsub(*str, 0, tmp - *str);
		if (tmp && *tmp)
			*str = ft_strdup(tmp + 1);
		else
			*str = ft_strnew(0);
		free(at_free);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*buffer;
	int			rt;

	rt = BUFF_SIZE;
	if (!str)
		str = ft_strnew(0);
	buffer = ft_strnew(BUFF_SIZE);
	while (rt > -1)
	{
		if (check_line(&str, line, rt))
		{
			free(buffer);
			return (1);
		}
		if ((rt = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		else if (rt == 0 && !*str)
			return (0);
		buffer[rt] = '\0';
		str = ft_strjoin_free(str, buffer, 1);
	}
	return (-1);
}
