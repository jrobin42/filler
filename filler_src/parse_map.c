/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 08:29:07 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 20:23:55 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse_map(char *line, int i, t_map *map, t_player *player)
{
	char	*pos_x;

	*(map->map + i) = ft_strdup(line);
	if ((pos_x = ft_strchr(*(map->map + i), player->char_player)))
	{
		player->last_pos = ft_memalloc(2 * sizeof(int));
		*(player->last_pos) = *(map->map + i) - pos_x;
		*(player->last_pos + 1) = i;
		return (1);
	}
//free(map->map) char*, verifier que ca n'a pas ete deja fait ds la fct filler
	return (0);
}
