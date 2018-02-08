/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/01 16:33:34 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*option_c(t_env *env)
{
	char	*s;

	s = ft_memalloc(env->width);
	ft_memset(s, ' ', env->width);
	*s = 0;
	return (s);
}

char	*char_null(char *tmp, t_env *env)
{
	int		len;
	char	*tmp2;

	if (!F_NEG && !env->width && (len = ft_strlen(tmp) + 1))
		tmp2 = tmp;
	else if (F_NEG && env->width && (tmp = option_c(env)))
	{
		tmp2 = tmp;
		len = env->width;
	}
	else
	{
		tmp = option_s(tmp, env);
		*(tmp + env->width - 1) = 0;
		tmp2 = tmp;
		len = ft_strlen(tmp) + 1;
	}
	save_endofs(env->beg, &tmp, len, env);
	return (tmp2);
}

void	type_c(t_env *env, va_list ap)
{
	char	*tmp;
	char	*tmp2;

	if ((env->size & 1 << 2) || (env->size & 1 << 3))
	{
		type_cc(env, ap);
		return ;
	}
	tmp = ft_memalloc(2);
	if (!(*tmp = (char)va_arg(ap, int)))
	{
		tmp2 = char_null(tmp, env);
		free(tmp2);
		return ;
	}
	tmp = option_s(tmp, env);
	tmp2 = tmp;
	save_endofs(env->beg, &tmp, ft_strlen(tmp), env);
	free(tmp2);
}
