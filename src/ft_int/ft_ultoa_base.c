/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:48:45 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/07 21:46:40 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

static int		count_n(long n, size_t len)
{
	unsigned long	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / len;
		++i;
	}
	return (i);
}

char			*ft_ultoa_base(unsigned long n, char *base)
{
	unsigned long	i;
	int				mod;
	unsigned long	div;
	size_t			len;
	char			*s;

	len = ft_strlen(base);
	i = count_n(n, len);
	s = ft_memalloc((i + 1) * sizeof(char));
	i = 0;
	if (!n)
		*s = base[0];
	while (n)
	{
		div = n / len;
		mod = n % len;
		mod = mod < 0 ? -mod : mod;
		s[i] = base[mod];
		n = div;
		++i;
	}
	s = ft_reverse(s);
	return (s);
}
