/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:40:14 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 07:56:53 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	int		i;

	i = -1;
	if (n > 0)
	{
		if (dest < src)
			while ((unsigned long)++i < n)
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		else if (dest > src)
			while (n-- > 0)
				((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
