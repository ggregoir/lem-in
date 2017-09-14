/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:02:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/14 15:00:15 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void			init_astruct(t_ants *a, t_struct *s, t_path *p)
{
	int i;

	i = 0;
	if ((a->pos = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	if ((a->apath = ft_memalloc(sizeof(int) * s->nbfourmi + 1)) == NULL)
		return(error(3, s));
	if ((a->apathi = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	if ((a->end = ft_memalloc(sizeof(int) * (s->nbfourmi + 1))) == NULL)
		return(error(3, s));
	//ft_putendl("y u heff to be med");
	while (p->paths[i][1] != 0 && i != (p->nbpath - 1))
	{
		//printf("i = %d\n", i);
		i++;
	}
	p->nbpath = i + 1;
	//printf("i = %d\n", i);
}

void			get_ant_path(t_ants *a, t_struct *s, t_path *p, int i)
{
	int j;
	int x;

	j = 0;
	x = 1;
	//ft_putendl("get_ant_path");
	//printf("i = %d et a->apath[i] = %d\n",i, a->apath[i] );
	if (a->apath[i] == 0)
	{
		while (j < p->nbpath)
		{
			//printf("avant boucle x = %d\n", x);
			while (x != s->nbfourmi)
			{
				//printf("x = %d et a->pos[x] = %d\n", x, a->pos[x]);
				if (a->pos[x] == p->paths[j][1])
				{
					//ft_putendl("WRONG");
					j++;
					x = 1;
					break;
				}
				x++;
			}
			//printf("x = %d\n", x);
			if (x == s->nbfourmi)
			{
				a->apath[i] = j + 1;
				if (j == p->nbpath)
				{
					return ;
				}
				//ft_putendl("gg wp");
				return ;
			}
		}
	}
	return ;
}

void			play_turn_multipass(t_ants *a, t_struct *s, t_path *p)
{
	int i;
	int j;
	int x;

	i = 1;
	j = 0;
	x = 1;
	//ft_putendl("coucou");
	//printf("p->nbpath = %d\n", p->nbpath);
	while (i <= s->nbfourmi)
	{
		get_ant_path(a, s, p, i);
		if (a->apath[i] > 0 && a->pos[i] != 1)
		{
			//ft_putendl("dans le deuxieme if");
			a->pos[i] = p->paths[a->apath[i] - 1][++a->apathi[i]];
			//printf("pos fourmi %d = %d \n",i, a->pos[i]);
		}
		//ft_putendl("incrementation");
		i++;
	}
	//ft_putendl("fin de fonction");
}

void		print_turn(t_ants *a, t_struct *s)
{
	int i;

	i = 1;

	//ft_putendl("lolilol");
	while (i <= s->nbfourmi)
	{
		if (a->pos[i] > 0 && a->end[i] == 0)
		{
			write(1, "L", 1);
			ft_putnbr(i);
			write(1, "-", 1);
			ft_putstr(s->names[a->pos[i]]);
			write(1, " ", 1);
		}
		if (a->pos[i] == 1)
			a->end[i] = 1;
		i++;
	}
	write(1, "\n", 1);
}

void			print_result(t_struct *s, t_path *p)
{
	t_ants a;

	//ft_putendl("avant init");
	init_astruct(&a, s, p);
	//ft_putendl("apres init");
	while (a.pos[s->nbfourmi] != 1)
	{
		play_turn_multipass(&a, s, p);
		if (s->color == 1)
			print_turn_color(&a, s);
		else
			print_turn(&a, s);
	}
}