/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:21:46 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/22 17:32:48 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	try_place_piece(int *yx, t_piece *piece, t_map *map, t_filler *filler)
{
	int		i;
	int		link;
	long	score;

	i = 0;
	link = 0;
	score = 0;
	while (i < piece->nb_stars)
	{
		if (*yx + piece->y[i] - filler->offset_y < MAX_Y && // < 0 possible ?
				yx[1] + piece->x[i]	- filler->offset_x < MAX_X && *yx + piece->y[i] - filler->offset_y >= 0 && // < 0 possible ?
				yx[1] + piece->x[i]	- filler->offset_x >= 0)
		{
		if (H_MAP[*yx + piece->y[i] - filler->offset_y][yx[1] + piece->x[i] - filler->offset_x] == -2)
				++link;
			else if (H_MAP[*yx + piece->y[i] - filler->offset_y]
					[yx[1] + piece->x[i] - filler->offset_x] == -1)
				return ;
			score += H_MAP[*yx + piece->y[i] - filler->offset_y]
				[yx[1] + piece->x[i] - filler->offset_x];
		}
		else
			return ;
		++i;
	}
	if (link == 1 && score < filler->best_score)
	{
		filler->best_score = score;
		filler->best_x = yx[1]/* - filler->offset_x*/;
		filler->best_y = *yx/* - filler->offset_y*/;
	}
}

int		search_best_pos(t_piece *piece, t_map *map, t_filler *filler)
{
	int		x;
	int		y;
	int		coord[2];

	x = 0;
	y = 0;
	filler->best_score = LONG_MAX; 
	while (y < MAX_Y)
	{
		while (x < MAX_X)
		{
			coord[0] = y;
			coord[1] = x;
			try_place_piece(coord, piece, map, filler);
			++x;
		}
		x = 0;
		++y;
	}
	if (filler->best_score ==  LONG_MAX)
	{
//		ft_printf("%d, %d", filler->best_y, filler->best_x);
		return (1);
	}
	else
		return (0);
}
