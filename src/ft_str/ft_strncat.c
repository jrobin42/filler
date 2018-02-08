/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:30:32 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 12:07:26 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strncat(char *dest, const char *src, unsigned long n)
{
	int		len_dest;
	int		j;

	len_dest = ft_strlen((const char *)dest);
	j = -1;
	while (src[++j] && (unsigned long)j < n)
		dest[len_dest + j] = src[j];
	dest[len_dest + j] = '\0';
	return (dest);
}
