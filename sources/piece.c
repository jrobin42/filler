/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:36:06 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 18:31:03 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_coord_piece(t_filler *filler)
{
	int			i;
	int			x;
	int			y;

	if ((P_AXE_X = ft_memalloc((NB_STARS) * sizeof(*P_AXE_X))) == NULL)
		return (-3);
	if ((P_AXE_Y = ft_memalloc((NB_STARS) * sizeof(*P_AXE_Y))) == NULL)
		return (-4);
	i = 0;
	y = 0;
	while (PIECE[y])
	{
		x = 0;
		while (PIECE[y][x])
		{
			if (PIECE[y][x] == '*')
			{
				P_AXE_X[i] = x;
				P_AXE_Y[i++] = y;
			}
			++x;
		}
		++y;
	}
	return (0);
}

static void		get_offset(t_filler *filler)
{
	int			i;
	int			x;

	i = 0;
	x = P_MAX_X;
	OFF_Y = *P_AXE_Y;
	OFF_X = *P_AXE_X;
	while (x + 1 && OFF_X)
	{
		P_AXE_X[i] < OFF_X ? OFF_X = P_AXE_X[i] : 0;
		--x;
	}
}

static void		count_stars(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	NB_STARS = 0;
	while (PIECE[i])
	{
		while (PIECE[i][j])
		{
			if (PIECE[i][j] == '*')
				++NB_STARS;
			++j;
		}
		j = 0;
		++i;
	}
}

int				parse_piece(t_filler *filler)
{
	int			ret;
	int			index_line;
	char		*line;

	index_line = 0;
	if (get_next_line(0, &line) != 1)
		return (-2);
	P_MAX_Y = ft_atoi(line + 6);
	free(line);
	if ((PIECE = ft_memalloc((P_MAX_Y + 1) * sizeof(char*))) == NULL)
		return (-2);
	while (index_line < P_MAX_Y)
	{
		if (get_next_line(0, &line) != 1)
			return (-3);
		*(PIECE + index_line) = line;
		++index_line;
	}
	*(PIECE + index_line) = NULL;
	P_MAX_X = ft_strlen(line);
	count_stars(filler);
	if ((ret = get_coord_piece(filler)) < 0)
		return (ret);
	get_offset(filler);
	return (0);
}
