/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:35:08 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 07:54:09 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	int		i;

	i = -1;
	while ((unsigned long)++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
