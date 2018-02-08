/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:57:16 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/21 03:49:19 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static int		ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] && ft_is_space(s[i]))
		i++;
	if (!s[i])
		return (ft_strdup(""));
	while (ft_is_space(s[len]))
		len--;
	return (ft_strsub(s, i, (len + 1 - i)));
}
