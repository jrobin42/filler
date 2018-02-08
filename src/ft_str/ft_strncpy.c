/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:17:34 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 12:38:13 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		i;

	i = -1;
	while (src[++i] && (size_t)i < n)
		dest[i] = src[i];
	i = i - 1;
	while ((size_t)++i < n)
		dest[i] = 0;
	return (dest);
}
