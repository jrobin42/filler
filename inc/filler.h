/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 07:34:05 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/19 03:20:22 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


# include "libft_str.h"
# include "ft_printf.h"
# include <stdio.h>

# define MAP map->map
# define H_MAP map->heatmap
# define MAX_X map->max_x
# define MAX_Y map->max_y

typedef struct	s_player
{
	char		char_player;
	int			last_pos[2]; //0 -> x & 1 -> y
}				t_player;

typedef struct	s_map
{
	int			max_x;
	int			max_y;
	char		**map;
	int			**heatmap;
}				t_map;

typedef struct	s_piece
{
	char		**piece;
	int			max_x;
	int			max_y;
}				t_piece;

//int				parse_map(char *line, int i, t_map *map, t_player *player);
void			parse_piece(t_piece *piece);
void			prepare_heatmap(t_map *map, t_player *my_p, t_player *bad_p);
//void			put_piece(t_piece *piece, t_map *map);

#endif
