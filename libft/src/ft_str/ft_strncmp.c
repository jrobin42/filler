/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 21:00:56 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 12:34:14 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = -1;
	while (n != 0 && (size_t)++i < n)
		if (((s1[i] || s2[i]) == '\0') || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
