/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:45:45 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 07:39:42 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memccpy(void *dest, const void *src, int c, unsigned long n)
{
	unsigned long	i;
	unsigned char	*cpydst;
	unsigned char	*cpysrc;

	i = 0;
	cpydst = (unsigned char *)dest;
	cpysrc = (unsigned char *)src;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		if (cpysrc[i] == (unsigned char)c)
			return ((char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
