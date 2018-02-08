/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:48:45 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 04:36:25 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && ++j)
		n = -n;
	tmp = n;
	while (tmp != 0 && ++i)
		tmp = tmp / 10;
	i = n == 0 ? 1 : i;
	if (!(nb = (char *)malloc((i + j + 1) * sizeof(char))))
		exit(1);
	nb[0] = j == 1 ? '-' : ' ';
	nb[i + j] = 0;
	while (i-- > 0)
	{
		nb[i + j] = (n % 10) + 48;
		n = n / 10;
	}
	return (nb);
}
