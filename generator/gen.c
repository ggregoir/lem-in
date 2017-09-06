/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:34:15 by iburel            #+#    #+#             */
/*   Updated: 2017/09/06 14:33:50 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		main(int ac, char **av)
{
	int		nb_rooms;
	int		nb_cnxs;
	int		i;
	int		rand1;
	int		rand2;

	if (ac != 4)
		return (0);
	printf("%s\n", av[1]);
	nb_rooms = atoi(av[2]);
	nb_cnxs = atoi(av[3]);
	printf("##start\n");
	printf("start 0 1\n");
	printf("##end\n");
	printf("end 1 0\n");
	i = 0;
	while (i < nb_rooms - 2)
	{
		printf("%d %d %d\n", i, i, i);
		i++;
	}
	i = 0;
	while (i < nb_cnxs)
	{
start:
		rand1 = rand() % nb_rooms;
		rand2 = rand() % nb_rooms;
		if ((rand1 == 0 && rand2 == 1) || rand1 == 1 && rand2 == 0)
			goto start;
		if (rand1 == 0)
			printf("start-");
		else if (rand1 == 1)
			printf("end-");
		else
			printf("%d-", rand1 - 2);
		if (rand2 == 0)
			printf("start\n");
		else if (rand2 == 1)
			printf("end\n");
		else
			printf("%d\n", rand2 - 2);
		i++;
	}
	return (0);
}