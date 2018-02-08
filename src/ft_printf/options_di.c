/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 06:55:14 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_sign(int signe, char *s, t_env *env)
{
	if (signe == -1)
		*s = '-';
	else if (F_PLUS)
		*s = '+';
	else if (F_SPACE)
		*s = ' ';
	else
		return (0);
	return (1);
}

char	*after_zero(char *s)
{
	int		i;

	i = 0;
	if (s)
		while (*s && *(s + i) && *(s + i) == '0')
			++i;
	return (s + i);
}

char	*after_space(char *s, t_env *env)
{
	int		i;

	i = 0;
	if (s)
	{
		while (*s && *(s + i) && *(s + i) == ' ')
			++i;
		if (i >= 2 && (TYPE == 'x' || TYPE == 'x'))
			i = i - 2;
		else if (i >= 1 && (TYPE == 'd' || TYPE == 'D' || TYPE == 'i'))
			i = i - 1;
	}
	return (s + i);
}
