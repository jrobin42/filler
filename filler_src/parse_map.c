/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/19 08:06:42 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_score_around_wall_if_adv(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (MAP[y])
	{
		while (MAP[y][x])
		{
			if (MAP[y][x] == '3' || MAP[y][x] == '8')
			{
				y == 0 ? MAP[y][x] += 10 : 0;
				x == 0 ? MAP[y][x] += 10 : 0;
				y == MAX_Y ? MAP[y][x] += 10 : 0;
				x == MAX_X ? MAP[y][x] += 10 : 0;
			}
			++x;
		}
		x = 0;
		printf("%s\n", MAP[y]);
		++y;
	}
}

int		intensity_for_each(t_map *map, int score, int nb)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < MAX_Y)
	{
		while (x < MAX_X)
		{
			if (((H_MAP[y][x] == 99 + nb && nb != -1) || H_MAP[y][x] == nb) && H_MAP[y][x] != -2)
			{
				y > 0 && H_MAP[y - 1][x] == 50 ? H_MAP[y - 1][x] = score : 0;
				y < MAX_Y - 1 && H_MAP[y + 1][x] == 50 ? H_MAP[y + 1][x] = score : 0;
				x > 0 && H_MAP[y][x - 1] == 50 ? H_MAP[y][x - 1] = score : 0;
				x < MAX_X - 1 && H_MAP[y][x + 1] == 50 ? H_MAP[y][x + 1] = score : 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (nb + 1);
}

int		heatmap_not_ready(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < MAX_Y)
	{
		while (x < MAX_X)
		{
			if (H_MAP[y][x] == 50)
				return (1);
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

void	prepare_heatmap(t_map *map, t_player *my_p, t_player *bad_p)
{
(void)my_p;

	int		i;
	int		j;
	int		nb;
	int		score;

	i = 0;
	j = 0;
	nb = -1;
	score = 99;
	map->max_x += 1;
	map->max_y += 1;
	map->heatmap = ft_memalloc(map->max_y * sizeof(int*));				//penser a free
	while (i < map->max_y)
	{
		map->heatmap[i] = ft_memalloc(map->max_x * sizeof(int));			//penser a free
		while (j < map->max_x)
		{
			map->heatmap[i][j] = MAP[i][j] == bad_p->char_player ? -1 : -2;
			MAP[i][j] == '.' ? map->heatmap[i][j] = 50 : 0;
			++j;
		}
		j = 0;
		++i;
	}
	while (heatmap_not_ready(map)) // condition a revoir sa mere
	{
	ft_printf("max x %d  max y %dscore %d nb %d\n", MAX_X, MAX_Y, score, nb);
		nb = intensity_for_each(map, score, nb);
		++score;
	}
//	put_score_around_adv(map, -1);
	i = 0;
	j = 0;
	while (i < 23)
	{
		ft_printf("{");
		while (j < 40)
		{
			ft_printf("%4d", H_MAP[i][j]);
			++j;
		}
		j = 0;
		ft_printf("}\n");
		++i;
	}
}
