/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:42:55 by jrobin            #+#    #+#             */
/*   Updated: 2017/06/21 02:45:20 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

char	*ft_strstr(const char *phrase, const char *mot)
{
	int		i;
	int		j;
	int		s;

	i = -1;
	j = 0;
	s = 0;
	while (phrase[++i])
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
	}
	return (!phrase[0] && !mot[0] ? ((char *)phrase) : 0);
}
