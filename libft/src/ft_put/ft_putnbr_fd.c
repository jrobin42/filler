/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:41:37 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 11:08:30 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	int		cpy_nb;
	int		tmp;

	i = 1;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb *= -1;
		}
		cpy_nb = nb;
		while (cpy_nb / i >= 10)
			i = i * 10;
		while (i > 0)
		{
			tmp = nb / i + 48;
			write(fd, &tmp, 1);
			nb = nb % i;
			i = i / 10;
		}
	}
}
