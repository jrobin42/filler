/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:35:55 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/20 15:21:24 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strnstr(const char *phrase, const char *mot, unsigned long n)
{
	unsigned long	i;
	int				j;
	int				s;

	i = 0;
	j = 0;
	s = 0;
	while (mot[0] && phrase[0] && i < n && phrase[i] && mot[j])
	{
		if (phrase[i] == mot[j])
			j++;
		else if (phrase[i] != mot[j])
		{
			i = s - 1;
			s++;
			j = 0;
		}
		if (mot[j] == '\0')
			return ((char *)&phrase[i - j + 1]);
		i++;
	}
	return (!mot[0] ? (char *)phrase : NULL);
}
