/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:19:00 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/05 17:25:45 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strsub(char const *s, unsigned int start, size_t l)
{
	int		i;
	char	*s2;

	if (s && l > ft_strlen(s))
	{
		if (!(s2 = (char *)malloc((l + 1) * sizeof(char))))
			exit(1);
		i = -1;
		while ((size_t)++i < l)
			s2[i] = s[start + i];
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
