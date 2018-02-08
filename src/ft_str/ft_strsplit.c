/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 04:27:27 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 02:28:01 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

static char		**ft_malloc_tab(const char *str, char c, int i)
{
	char	**tab;
	int		mot;
	int		j;
	int		nb_de_mots;

	j = 0;
	mot = -1;
	nb_de_mots = 0;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			i++;
			if ((str[i] == c || str[i] == 0) && str[i - 1] != c)
				nb_de_mots++;
		}
		while (str[i] && str[i] == c)
			i++;
	}
	if (!(tab = (char **)malloc((nb_de_mots + 1) * sizeof(char *))))
		exit(1);
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	int		mot;
	int		lettre;
	char	**tab;

	i = 0;
	lettre = 0;
	mot = 0;
	if (!str || !(tab = ft_malloc_tab(str, c, i)))
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i++] != c)
			if ((str[i] == 0 && str[i - 1] != c) || str[i] == c)
				tab[mot++] = ft_strsub(str, j, (i - j));
	}
	tab[mot] = 0;
	return (tab);
}
