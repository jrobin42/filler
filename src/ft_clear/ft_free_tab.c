/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 07:40:54 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 04:52:30 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_clear.h"

void	ft_free_tab(char **tab)
{
	int		i;

	if (tab)
	{
		if (*tab)
		{
			i = 0;
			while (tab[i])
				free(tab[i++]);
		}
		free(tab);
	}
}
