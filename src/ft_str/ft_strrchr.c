/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 21:22:43 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 15:45:01 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;

	len = ft_strlen((char *)str) + 1;
	while (str && --len >= 0)
		if (str[len] == c)
			return ((char *)&str[len]);
	return (NULL);
}
