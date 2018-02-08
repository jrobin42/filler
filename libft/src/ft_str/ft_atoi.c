/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:21:56 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/07 21:51:45 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static int		ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == ' ' || c == '\r' || c == '\v'
			|| c == '\f');
}

int				ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] < '0' && str[i] > '9' && str[i] != '+' && str[i] != '-')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '+' ? 1 : -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = 10 * nb + (str[i] - 48) * sign;
		i++;
	}
	return (nb);
}
