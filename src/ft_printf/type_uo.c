/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 00:13:16 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*option_uo(char *s, t_env *env)
{
	char	*ret;
	int		len;
	int		size;

	len = ft_strlen(s);
	size = WIDTH > PRECISION ? WIDTH : PRECISION;
	ret = ft_memalloc((size > len ? size : len) + 1 +
		(F_HASH && (TYPE == 'x' || TYPE == 'X') ? 1 : 0));
	env->nb || (!PRECISION && F_HASH) ? ret = apply_hash(ret, env) : 0;
	ret = apply_precision(s, ret, env);
	if (PRECISION || *s != '0')
		ret = ft_strcat(ret, s);
	ret = apply_width(ret, env);
	free(s);
	return (ret);
}

void	type_uo(t_env *env, va_list ap)
{
	unsigned long	tmp;
	char			*ret;
	char			*tmp2;

	if ((env->size & (1 << 2)) || (env->size & (1 << 3)) ||
	(env->type == 'U') || (env->type == 'O'))
		tmp = (unsigned long)va_arg(ap, long);
	else if (env->size & 1)
		tmp = (unsigned char)va_arg(ap, int);
	else if ((env->size & (1 << 1)))
		tmp = (unsigned short)va_arg(ap, int);
	else if (env->size & 1 << 4)
		tmp = va_arg(ap, uintmax_t);
	else if ((env->size & (1 << 5)))
		tmp = va_arg(ap, size_t);
	else
		tmp = (unsigned int)va_arg(ap, int);
	env->nb = tmp;
	if (env->type == 'u' || env->type == 'U')
		ret = option_uo(ft_ultoa_base(tmp, "0123456789"), env);
	else
		ret = option_uo(ft_ultoa_base(tmp, "01234567"), env);
	tmp2 = ret;
	save_endofs(env->beg, &ret, ft_strlen(ret), env);
	free(tmp2);
}
