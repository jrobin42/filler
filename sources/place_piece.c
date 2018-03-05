/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:21:46 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 15:34:43 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		save_best_pos(t_filler *filler, int score, int x, int y)
{
	BEST_SCORE = score;
	BEST_X = x - OFF_X;
	BEST_Y = y - OFF_Y;
}

static int		is_in_map(t_filler *filler, int x, int y, int i)
{
	return ((y + P_AXE_Y[i] - OFF_Y < M_MAX_Y) &&
			(x + P_AXE_X[i] - OFF_X < M_MAX_X)
			&& (y + P_AXE_Y[i] - OFF_Y >= 0) && (x + P_AXE_X[i] - OFF_X >= 0));
}

void			try_place_piece(int x, int y, t_filler *filler)
{
	int		i;
	int		current;
	int		link;
	long	score;

	i = 0;
	link = 0;
	score = 0;
	while (i < NB_STARS && link >= 0)
	{
		if (is_in_map(filler, x, y, i))
		{
			current = H_MAP[y + P_AXE_Y[i] - OFF_Y][x + P_AXE_X[i] - OFF_X];
			if (current == -2 || current == -1)
				link = current == -1 ? -1 : link + 1;
			else
				score += current;
		}
		else
			link = -1;
		++i;
	}
	if (link != 1 || score > filler->best_score)
		return ;
	save_best_pos(filler, score, x, y);
}

int				search_best_pos(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	BEST_SCORE = LONG_MAX;
	while (y < M_MAX_Y)
	{
		while (x < M_MAX_X)
		{
			try_place_piece(x, y, filler);
			++x;
		}
		x = 0;
		++y;
	}
	return (BEST_SCORE < LONG_MAX ? 0 : 1);
}
