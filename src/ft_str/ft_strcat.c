/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:30:32 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/01 02:15:49 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strcat(char *dest, const char *src)
{
	int				len_dest;
	unsigned long	j;

	len_dest = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[len_dest] = src[j];
		++len_dest;
		++j;
	}
	dest[len_dest] = '\0';
	return (dest);
}
