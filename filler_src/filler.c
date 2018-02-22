/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:32:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/22 20:39:50 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_map(t_map *map)
{
	int		index_line;
	char	*line;

	index_line = 0;
	get_next_line(0, &line);
		dprintf(2, "FIRST\tline{%s}\n", line);
	map->max_y = ft_atoi(line + 8);
//	ft_strdel(&line);
	MAP = ft_memalloc((map->max_y + 1) * sizeof(char*));
	get_next_line(0, &line);
	dprintf(2, "SECOND\tline{%s}\n", line);
//	ft_strdel(&line);
	while (index_line < map->max_y)
	{
		get_next_line(0, &line);
		*(MAP + index_line) = ft_strdup(line + 4);
		dprintf(2, "\tMAP{%s}\n", line);
	//	ft_strdel(&line);
		++index_line;
	}
	map->max_x = ft_strlen(*MAP) - 1;
	map->max_y = map->max_y - 1;
}

void	get_char_player(t_player *my_p, t_player *bad_p)
{
	char	*line;

	get_next_line(0, &line);
	my_p->char_player = *(line + 10) == '1' ? 'O' : 'X';
	bad_p->char_player = my_p->char_player == 'X' ? 'O' : 'X';
}

/*void	get_pos_player(t_player *my_p, t_player *bad_p, t_map *map)
{
	int		i;
	char	*position;

	i = 0;
	ft_memset(my_p->last_pos, 0, 2);
	ft_memset(bad_p->last_pos, 0, 2);
	while (*(MAP + i) && (!*(my_p->last_pos) || !*(bad_p->last_pos)))
	{
		if ((position = ft_strchr(*(MAP + i), my_p->char_player)))
		{
			*(my_p->last_pos) = position - *(MAP + i);
			*(my_p->last_pos + 1) = i;
		}
		if ((position = ft_strchr(*(MAP + i), bad_p->char_player)))
		{
			*(bad_p->last_pos) = position - *(MAP + i);
			*(bad_p->last_pos + 1) = i;
		}
		++i;
	}
}*/

int		main(void)
{
	t_player	my_p;
	t_player	bad_p;
	t_piece		*piece;
	t_map		map;
	t_filler	*filler;

	get_char_player(&my_p, &bad_p);
	while (1)
	{

		parse_map(&map);
//		dprintf(2, "ii {%s}\n\n", map.map[14]);
		filler = parse_piece(&piece);
		prepare_heatmap(&map, &my_p, &bad_p);
		if (search_best_pos(piece, &map, filler))
			break ;
		else
			ft_printf("%d %d\n", filler->best_y, filler->best_x);
//		free_all();
	}
	return (0);
}
