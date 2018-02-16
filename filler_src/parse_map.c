/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/16 13:21:41 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	up_walls_score(t_map *map, t_player *my_p)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	printf("*my_p [%d]  %s\n", *(my_p->last_pos + 1), *MAP);
	while (MAP && MAP[y] && y <= *(my_p->last_pos + 1)) //besoin des 2 premieres conditions ?
	{
		i = 10;
		j = 0;
		while (MAP[y][x + j] && x + j <= MAX_X / 2 && i > 0)
		{
			MAP[y][x + j] += MAP[y][x + j] == '.' ? i : 0;
			MAP[y][MAX_X - j] += MAP[y][MAX_X - j] == '.' ? i : 0;
			i = y ? i - 2 : i;
			++j;
		}
		printf("y = %d\n", y);
		++y;
	}
}

void	down_walls_score(t_map *map, t_player *my_p)
{
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	printf("max y %d [%s]\n", MAX_Y, MAP[MAX_Y]);
	while (MAP && MAP[MAX_Y - y] && MAX_Y - y >= *(my_p->last_pos + 1)) //besoin des 2 premieres conditions ?
	{
		i = 10;
		j = 0;
		while (MAP[MAX_Y - y][x + j] && x + j <= MAX_X / 2 && i > 0)
		{
			MAP[MAX_Y - y][x + j] += MAP[MAX_Y - y][x + j] == '.' ? i : 0;
			MAP[MAX_Y - y][MAX_X - j] += MAP[MAX_Y - y][MAX_X - j] == '.' ? i : 0;
			i = y ? i - 2 : i;
			++j;
		}
		++y;
	}
	x = 1;
	y = MAX_Y - 1;
	i = 6;
	j = 1;
	while (i >= 0)
	{
		while (MAP[y][x + j])
		{
			MAP[y][x] = i;
			++x;
		}
		i = i - 2;
		++j;
		++y;
	}
}

void	prepare_map(t_map *map, t_player *my_p, t_player *bad_p)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	(void)my_p;
	(void)bad_p;
	*(my_p->last_pos + 1) > *(bad_p->last_pos + 1) ?
		up_walls_score(map, my_p) : down_walls_score(map, my_p);
	while (MAP[y])
	{
		printf("MAP[%d]\t[%s]\n", y, MAP[y]);
		++y;
	}
}
