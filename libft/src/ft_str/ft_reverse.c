/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:03:44 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 15:35:09 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stdio.h>

char	*ft_reverse(char *s)
{
	int		i;
	int		len;
	char	*rev;

	i = 0;
	len = ft_strlen(s);
	rev = ft_memalloc((len + 1) * sizeof(char));
	while (len)
	{
		rev[i] = s[len - 1];
		--len;
		++i;
	}
	rev[i] = 0;
	free(s);
	return (rev);
}
