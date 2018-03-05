/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:32:43 by jrobin            #+#    #+#             */
/*   Updated: 2018/03/04 18:10:26 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_char_player(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (-1);
	if (ft_strlen(line) < 20 || (*(line + 10) != '1' && *(line + 10) != '2'))
	{
		free(line);
		return (-2);
	}
	filler->my_char = *(line + 10) == '1' ? 'O' : 'X';
	filler->adv_char = filler->my_char == 'X' ? 'O' : 'X';
	free(line);
	return (0);
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	if (map)
	{
		if (*map)
		{
			while (map[i] && map[i] - 4)
			{
				free(map[i] - 4);
				++i;
			}
		}
		free(map);
	}
}

void	free_all(t_filler *filler, int i)
{
	if (i < -1)
	{
		free_map(MAP);
		if (i < -2)
		{
			ft_free_tab((void***)&(PIECE));
			if (i < -3)
			{
				free(P_AXE_X);
				if (i < -4)
				{
					free(P_AXE_Y);
					if (i < -5)
					{
						ft_free_tab((void***)&(H_MAP));
					}
				}
			}
		}
	}
}

int		parse(t_filler *filler)
{
	int		ret;

	if ((ret = parse_map(filler, -1, NULL)) < 0 ||
		(ret = parse_piece(filler)) < 0 ||
		(ret = prepare_heatmap(filler)) < 0)
	{
		free_all(filler, ret);
		return (-1);
	}
	return (0);
}

int		main(void)
{
	int			ret;
	t_filler	filler;

	ft_bzero(&filler, sizeof(filler));
	if ((ret = get_char_player(&filler)) < 0)
		return (ret);
	while (1)
	{
		if (parse(&filler) == -1)
			return (-1);
		if ((ret = search_best_pos(&filler)) == 1)
			break ;
		else if (ret == -1)
			return (-1);
		ft_printf("%d %d\n", filler.best_y, filler.best_x);
		free_all(&filler, -6);
	}
	ft_printf("0 0\n");
	free_all(&filler, -6);
	return (0);
}
