/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 00:13:51 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*take_arg(va_list ap, t_env *env)
{
	char			base[16];
	unsigned long	tmp;

	ft_strcpy(base, TYPE == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	if (env->size & 1)
		tmp = (unsigned char)va_arg(ap, int);
	else if (env->size & (1 << 1))
		tmp = (unsigned short)va_arg(ap, int);
	else if ((env->size & (1 << 2)) || (env->size & (1 << 3)))
		tmp = va_arg(ap, unsigned long);
	else if (env->size & (1 << 4))
		tmp = va_arg(ap, uintmax_t);
	else if (env->size & (1 << 5))
		tmp = va_arg(ap, size_t);
	else
		tmp = va_arg(ap, unsigned int);
	env->nb = tmp;
	return (ft_ultoa_base(tmp, base));
}

char	*option_x(char *s, t_env *env)
{
	char	*ret;
	int		len;
	int		size;

	len = ft_strlen(s);
	size = WIDTH > env->precision ? WIDTH : env->precision;
	ret = ft_memalloc((size > len ? size : len) + 1 +
		(F_HASH ? 2 : 0));
	if (PRECISION >= 1)
		apply_precision(s, ret, env);
	!(!PRECISION && *s == '0') ? ret = ft_strcat(ret, s) : 0;
	free(s);
	if ((!F_HASH && !F_ZERO) && WIDTH >= PRECISION)
	{
		ret = apply_hash(ret, env);
		ret = apply_width(ret, env);
	}
	else
	{
		WIDTH >= 2 && F_NEG ? WIDTH = WIDTH - 2 : 0;
		ret = apply_width(ret, env);
		ret = apply_hash(ret, env);
	}
	return (ret);
}

void	type_x(t_env *env, va_list ap)
{
	char			*ret;
	char			*tmp;

	ret = take_arg(ap, env);
	ret = option_x(ret, env);
	tmp = ret;
	save_endofs(env->beg, &ret, ft_strlen(ret), env);
	free(tmp);
}
