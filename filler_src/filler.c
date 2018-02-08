/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:32:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 21:50:06 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	filler(t_player *first_p, t_player *second_p, t_env *env)
{
	int		i;
	int		index_line;
	char	*line;
//	char	*size_map_y;
	t_map	map;

	index_line = 0;
	i = 8;
	env->player = first_p;
	get_next_line(0, &line);
	map.max_x = ft_atoi(line + 8);
/*	while (ft_isdigit(line + i))
		++i;
	size_map_y = ft_atoi(line + i); //char *map : pas utile de connaitre position max --> strdup de chacune des ligne ds parse_map
	map.max_y = ft_atoi(line + 8);*/
	i = map.max_x + 1;
	map.map = ft_memalloc((map.max_x + 1) * sizeof(char*));
	while (--i && index_line++ && !env->player->last_pos)			//indexline == 0 au 1er passage ?
	{
		get_next_line(0, &line);
		if (parse_map(line, index_line, &map, env->player))
		{
			env->player = second_p;
			++i;						//au cas ou X et O sur une meme ligne
		}
	}
	map.max_y = ft_strlen((map.map[0]));
	parse_piece();
	put_piece(&map, first_p, second_p);
//free(map.map) (char**)
}

int		main(void)
{
	char	*line;
	t_player	first_p;
	t_player	second_p;
	t_env		env;

	get_next_line(0, &line);
	first_p.char_player = *(line + 10) == '1' ? 'X' : 'O';
	second_p.char_player = first_p.char_player == 'X' ? 'O' : 'X';
	filler(&first_p, &second_p, &env);
	return (0);
}
