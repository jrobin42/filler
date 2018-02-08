/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:37:34 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/01 18:22:34 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
