/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 18:13:26 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				parse_map(t_filler *filler, int index_line, char *line)
{
	if (get_next_line(0, &line) != 1 || ft_strlen(line) < 9)
	{
		ft_strdel(&line);
		return (-1);
	}
	M_MAX_Y = ft_atoi(line + 8);
	free(line);
	if ((MAP = ft_memalloc((M_MAX_Y + 1) * sizeof(char*))) == NULL)
		return (-1);
	if (get_next_line(0, &line) != 1)
		return (-2);
	free(line);
	while (++index_line < M_MAX_Y)
		if (get_next_line(0, &line) != 1)
			return (-2);
		else if (ft_strlen(line) < 5)
			return (-2);
		else
			*(MAP + index_line) = line + 4;
	M_MAX_X = ft_strlen(*MAP);
	return (0);
}

static void		intensity_for_each(t_filler *filler, int n)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < M_MAX_Y)
	{
		while (x < M_MAX_X)
		{
			if ((H_MAP[y][x] == -1 && n == 0) ||
				(H_MAP[y][x] == n && n))
			{
				y > 0 && H_MAP[y - 1][x] == 0 ? H_MAP[y - 1][x] = n + 1 : 0;
				y < M_MAX_Y - 1 && H_MAP[y + 1][x] == 0 ?
					H_MAP[y + 1][x] = n + 1 : 0;
				x > 0 && H_MAP[y][x - 1] == 0 ? H_MAP[y][x - 1] = n + 1 : 0;
				x < M_MAX_X - 1 && H_MAP[y][x + 1] == 0 ?
					H_MAP[y][x + 1] = n + 1 : 0;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

static int		heatmap_not_ready(t_filler *filler)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < M_MAX_Y)
	{
		while (x < M_MAX_X)
		{
			if (H_MAP[y][x] == 0)
				return (1);
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

static void		place_player(int value, char player, t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			if (MAP[i][j] == player)
				H_MAP[i][j] = value;
			++j;
		}
		++i;
	}
}

int				prepare_heatmap(t_filler *filler)
{
	int			i;
	int			j;
	int			score;

	i = 0;
	j = 0;
	score = 0;
	if ((H_MAP = ft_memalloc((M_MAX_Y + 1) * sizeof(int*))) == NULL)
		return (-5);
	while (i < M_MAX_Y)
	{
		if ((H_MAP[i] = ft_memalloc(M_MAX_X * sizeof(int))) == NULL)
			return (-6);
		++i;
	}
	place_player(-1, ADV, filler);
	while (heatmap_not_ready(filler))
	{
		intensity_for_each(filler, score);
		++score;
	}
	place_player(-2, ME, filler);
	return (0);
}
