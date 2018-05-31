/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 07:34:05 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/05 18:54:33 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft_str.h"
# include "ft_printf.h"

# define MAP filler->map.map
# define H_MAP filler->map.heatmap
# define M_MAX_X filler->map.max_x
# define M_MAX_Y filler->map.max_y

typedef struct	s_map
{
	int			max_x;
	int			max_y;
	char		**map;
	int			**heatmap;
}				t_map;

# define PIECE filler->piece.piece
# define P_MAX_X filler->piece.max_x
# define P_MAX_Y filler->piece.max_y
# define NB_STARS (filler->piece.nb_stars)
# define P_AXE_X (filler->piece.axe_x)
# define P_AXE_Y (filler->piece.axe_y)

typedef struct	s_piece
{
	char		**piece;
	int			nb_stars;
	int			max_x;
	int			max_y;
	int			*axe_x;
	int			*axe_y;
}				t_piece;

# define OFF_X filler->offset_x
# define OFF_Y filler->offset_y
# define ADV filler->adv_char
# define ME filler->my_char
# define BEST_SCORE filler->best_score
# define BEST_X filler->best_x
# define BEST_Y filler->best_y

typedef struct	s_filler
{
	int			best_x;
	int			best_y;
	long		best_score;
	int			offset_x;
	int			offset_y;
	int			not_finish;
	char		my_char;
	char		adv_char;
	t_piece		piece;
	t_map		map;
}				t_filler;

int				parse_piece(t_filler *filler);
int				parse_map(t_filler *filler, int index_line, char *line);
int				prepare_heatmap(t_filler *filler);
int				search_best_pos(t_filler *filler);

#endif
