/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:56:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/07 21:42:11 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		init_buff(t_struct *s)
{
	int i;

	f->ret = 0;
	f->bi = 0;
	i = 0;
	while (i != BSIZE)
	{
		f->b[i] = '\0';
		i++;
	}
}

void		str_buff(t_format *f, char *str)
{
	int i;

	i = 0;
	if (str == 0)
		return ;
	if (f->bi < BSIZE)
	{
		while (str[i])
		{
			f->b[f->bi] = str[i];
			i++;
			f->bi++;
		}
		f->b[f->bi] = '\n'
		f->bi++;
	}
	else
	{
		write(1, f->b, BSIZE);
		init_buff(f);
	}
}