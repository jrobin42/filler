/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:48:34 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/21 06:53:21 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

int		ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (i == n ? 0 : ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
