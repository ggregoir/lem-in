/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 19:02:04 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/13 00:04:04 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"
#include <stdio.h>

void			init_astruct(t_ants *a, t_struct *s, t_path *p)
{
	int i;

	i = 0;
	if ((a->pos = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	if ((a->apath = ft_memalloc(sizeof(int) * p->nbpath)) == NULL)
		return(error(3, s));
	if ((a->apathi = ft_memalloc(sizeof(int) * s->nbrooms)) == NULL)
		return(error(3, s));
	ft_putendl("vay u heff to be med");
	while (i < p->nbpath)
	{
		if (p->paths[i][1] != 0)
		{
			p->nbpath = i;
			return ;
		}
		printf("i = %d\n", i);
		i++;
	}
}

void			play_turn_multipass(t_ants *a, t_struct *s, t_path *p)
{
	int i;
	int j;
	int x;

	i = 1;
	j = 0;
	x = 1;
	ft_putendl("coucou");
	printf("p->nbpath = %d\n", p->nbpath);
	while (i <= s->nbfourmi)
	{
		printf("i = %d\n", i);
		ft_putendl("dans le while");
		while (j < p->nbpath)
		{
			ft_putendl("dans le deuxieme while");
			while (x != s->nbrooms)
			{
				if (a->pos[x] != p->paths[j][1])
					break;
				x++;
			}
			printf("x = %d\n", x);
			if (x == s->nbrooms)
			{
				printf("IN DA CONDITION");
				a->apath[i] = j + 1;
				j = 0;
				break ;
			}
			x = 0;
			j++;
		}
		ft_putendl("apres le deuxieme while");
		if (a->apath[i] > 0 && a->pos[i] != 1)
		{
			ft_putendl("dans le deuxieme if");
			a->pos[i] = p->paths[a->apath[i] - 1][++a->apathi[i]];
		}
		ft_putendl("incrementation");
		i++;
	}
	ft_putendl("fin de fonction");
}

void		print_turn(t_ants *a, t_struct *s)
{
	int i;

	i = 1;

	while (i != s->nbfourmi)
	{
		if (a->pos[i] > 0 && a->pos[i] != 1)
		{
			write(1, "L", 1);
			ft_putnbr(i);
			write(1, "-", 1);
			ft_putstr(s->names[a->pos[i]]);
			write(1, " ", 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void			print_result(t_struct *s, t_path *p)
{
	t_ants a;

	ft_putendl("avant init");
	init_astruct(&a, s, p);
	ft_putendl("apres init");
	while (a.pos[s->nbfourmi] != 1)
	{
		//if (p->nbpath > 1)
		//{
			play_turn_multipass(&a, s, p);
		//}
		//else
		//	play_turn_multipass(&a, s, p);
		print_turn(&a, s);
		return;
	}
}