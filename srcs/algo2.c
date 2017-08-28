/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:41:15 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/28 19:36:19 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				already_path(int *path, int curr)
{
	int x;

	x = 0;
	while(path[x] != -1)
	{
		if (path[x++] == curr)
			return(1);
	}
	return (0);
}

int				pathsize(int j, t_path *p)
{
	int i;

	i = 0;
	while (p->paths[j] != -1)
		i++;
	return (i);
}
void			replace_path(int i, t_path *p)
{
	if (p->pathsize[i] > p->i)
	{
		p->paths[i] = p->tmp;
		p->pathsize[i] = pathsize(i, p);
	}
}

void			manage_path(t_path *p)
{
	int x
	int j;
	int worst;

	x = -1;
	j = 0;
	while (p->pi != p->nbpath)
	{
		p->paths[p->pi] = p->tmp;
		p->pathsize[p->pi] = pathsize(p->pi++, p);
		return ;
	}
	while (++x != p->pi)
		if (p->pathsize[x] > worst)
			worst = x;
	replace_path(worst, p)

}