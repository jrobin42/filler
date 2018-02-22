/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:36:06 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/22 20:06:49 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_coord_piece(t_piece *piece)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
		dprintf(2, "%d y maximum\n", piece->max_y);
	while (i < piece->max_y + 1)
	{
		dprintf(2, "{{%s}}\n", piece->piece[i]);
		++i;
	}
	dprintf(2, "etoilesssss %d\n", piece->nb_stars);
	i = 0;
	piece->x = ft_memalloc(piece->nb_stars * sizeof(*(piece->x)));
	piece->y = ft_memalloc(piece->nb_stars * sizeof(*(piece->y)));
	while (piece->piece[y])
	{
	dprintf(2, "piece->piece[y] = %s\n", piece->piece[y]);
		while (piece->piece[y][x])
		{
			if (piece->piece[y][x] == '*')
			{
				piece->x[i] = x;
				piece->y[i] = y;
	dprintf(2, "ICIICIpiece->y[%d] = %d\n", i, piece->y[i]);
				++i;
			}
			++x;
		}
		x = 0;
		++y;
	}
}

t_filler	*get_offset(t_piece *piece)
{
	int			i;
	int			x;
	t_filler	*filler;

	i = 0;
	x = piece->max_x;
	filler = ft_memalloc(sizeof(t_filler));
	dprintf(2, "offset piece->y = %d\n", piece->y[i]);
	filler->offset_y = piece->y[0];
	filler->offset_x = *(piece->x);
		dprintf(2, "piece->x ======= %d\n", *(piece->x));
	while (x + 1 && filler->offset_x)              //filler->offset_x == 0 ! 
	{
		dprintf(2, "set off_set_x\n");
		piece->x[i] < filler->offset_x ? filler->offset_x = piece->x[i] : 0;
		--x;
	}
		dprintf(2, "hAoy\n");
	return (filler);
}

void		count_stars(t_piece *piece)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	piece->nb_stars = 0;
	while (piece->piece[i])
	{
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
				++piece->nb_stars;
			++j;
		}
		j = 0;
		++i;
	}
}

t_filler	*parse_piece(t_piece **piece)
{
	int			index_line;
	char		*line;

	*piece = ft_memalloc(sizeof(t_piece));
	index_line = 0;
	get_next_line(0, &line);
	(*piece)->max_y = ft_atoi(line + 6);
//	dprintf(2, "hereuh %d {%s}\n", (*piece)->max_y, line + 6);
	(*piece)->piece = ft_memalloc(((*piece)->max_y + 1) * sizeof(char*));
	//ft_strdel(&line);
	dprintf(2, "avt gnl max_y %d\n", (*piece)->max_y);
	while (index_line < (*piece)->max_y || ((*piece)->max_y == 0 && !index_line))
	{
		get_next_line(0, &line);
		*((*piece)->piece + index_line) = ft_strdup(line);
	dprintf(2, "aaaaaaaaaaaaaaaapiece->y = %s\n", (*piece)->piece[0]);
//		dprintf(2, "cccccccccc {%s}\n", *((*piece)->piece + index_line));
	//	ft_strdel(&line);
		++index_line;
	}
	(*piece)->max_x = ft_strlen(line);
	count_stars(*piece);
	get_coord_piece(*piece);
	return (get_offset(*piece));
}
