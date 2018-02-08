/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:12:57 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 17:50:04 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*option_percent(t_env *env)
{
	int		i;
	char	*s;

	s = ft_memalloc((WIDTH ? WIDTH : 1) + 1);
	if (WIDTH > 1)
	{
		i = 0;
		while (i < WIDTH)
		{
			*(s + i) = F_ZERO ? '0' : ' ';
			++i;
		}
	}
	if (F_NEG)
		*s = '%';
	else
		*(s + (WIDTH ? WIDTH : 1) - 1) = '%';
	return (s);
}

void	percent(t_env *env, va_list ap)
{
	char	*s;
	char	*tmp;

	(void)ap;
	s = option_percent(env);
	tmp = s;
	save_endofs(env->beg, &s, ft_strlen(s), env);
	free(tmp);
}
