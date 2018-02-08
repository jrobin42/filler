/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 06:39:25 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 06:24:21 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

#include <fcntl.h>

int		add_stock(char *stock, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(ft_strlen(*line)))
		*line = ft_strdup(stock);
	else
		*line = ft_strjoin(*line, stock);
	free(tmp);
	return (*line == NULL ? -1 : 1);
}

int		read_fd(int fd, char *stock, int *ret, char *line)
{
	if ((*ret = read(fd, stock, BUFF_SIZE_GNL)) == -1)
		return (-1);
	stock[*ret] = 0;
	if (!(*ret) && !ft_strlen(line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int		is_nl(char *stock, int i, char **line, int ret)
{
	stock[i] = 0;
	ret = add_stock(stock, line);
	ft_strcpy(stock, &(stock[i + 1]));
	return (ret > 0 ? 1 : -1);
}

int		no_nl(char *stock, char ***line, int ret, int j)
{
	if (!add_stock(stock, *line))
		return (-1);
	while (++j < BUFF_SIZE_GNL)
		stock[j] = 0;
	if (ret < BUFF_SIZE_GNL && (ft_strchr(**line, '\n') - **line) < 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	int				ret;
	static char		stock[BUFF_SIZE_GNL];

	if (fd < 0 || line == NULL || BUFF_SIZE_GNL < 1)
		return (-1);
	ret = BUFF_SIZE_GNL;
	*line = ft_strnew(0);
	while (ret)
	{
		if ((i = (!ft_strlen(stock) ? read_fd(fd, stock, &ret, *line) : 1)) < 1)
			return (i);
		if ((i = (ft_strchr(stock, '\n') - stock)) < 0)
			if ((j = no_nl(stock, &line, ret, -1)))
				return (j);
		if ((i = (i >= 0 ? is_nl(stock, i, line, 1) : 0)))
			return (i);
	}
	return (0);
}
