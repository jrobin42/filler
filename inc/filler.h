/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 07:34:05 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 20:18:19 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft_str.h"

typedef struct	s_player
{
	char		char_player;
	int			*last_pos;
}				t_player;

typedef struct	s_map
{
	int			max_x;		//
	int			max_y;		//plutot en char* ou int*
	char		**map;
}				t_map;

typedef struct	s_piece
{
	char		*piece;
	int			max_x;		//
	int			max_y;		//plutot en char* ou int*
}				t_piece;

typedef struct	s_env
{
	t_player	*player;
}				t_env;

int				parse_map(char *line, int i, t_map *map, t_player *player);
void			parse_piece(void);
void			put_piece(t_map *map, t_player *first_p, t_player *second_p);

#endif
