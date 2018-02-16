/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:36:06 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/15 16:29:54 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_piece(t_piece *piece)
{
	int		index_line;
	char	*line;

//	int fd = open("./hop", O_RDWR | O_TRUNC);
	index_line = 0;
	get_next_line(0, &line);
//	dprintf(2, "%s\n", line);
	piece->max_y = ft_atoi(line + 6);
	piece->piece = ft_memalloc((piece->max_y + 1) * sizeof(char*));
	while (index_line < piece->max_y)
	{
		get_next_line(0, &line);
//	dprintf(2, "%s\n", line);
		*(piece->piece + index_line) = line;
		++index_line;
	}
}

void	put_piece(t_piece *piece, t_map *map)
{
	(void)piece;
	(void)map;
}
