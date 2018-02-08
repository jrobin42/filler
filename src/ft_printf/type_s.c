/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 15:19:05 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*option_s(char *tmp, t_env *env)
{
	char	*s;
	char	*s2;

	s = tmp;
	if (tmp && env->precision > -1 && env->precision < (int)ft_strlen(tmp))
	{
		s = ft_memalloc(env->precision + 1);
		ft_memcpy(s, tmp, env->precision);
		free(tmp);
	}
	if (env->width > (int)ft_strlen(s))
	{
		s2 = ft_memalloc(env->width - ft_strlen(s) + 1);
		if (F_ZERO)
			s2 = ft_memset(s2, '0', env->width - ft_strlen(s));
		else
			s2 = ft_memset(s2, ' ', env->width - ft_strlen(s));
		if (F_NEG)
			s = ft_freejoin(s, s2, 1);
		else
			s = ft_freejoin(s2, s, 2);
		free(s2);
	}
	return (s);
}

void	type_s(t_env *env, va_list ap)
{
	char	*tmp;
	char	*s;

	if (env->size & 1 << 2 || env->size & 1 << 3)
		type_ss(env, ap);
	else
	{
		tmp = va_arg(ap, char*);
		tmp = !tmp ? ft_strdup("(null)") : ft_strdup(tmp);
		s = option_s(tmp, env);
		tmp = s;
		save_endofs(env->beg, &s, ft_strlen(s), env);
		free(tmp);
	}
}
