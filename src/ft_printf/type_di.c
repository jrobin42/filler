/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:48:57 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 06:42:23 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*inverse(int sign, char *nb, char *s, t_env *env)
{
	int		i;

	i = after_zero(s + (SIGN ? 1 : 0)) - s;
	ft_strcpy(s + i, nb);
	put_sign(sign, s, env);
	if (WIDTH - (int)ft_strlen(s) > 0)
		ft_memset(s + ft_strlen(s), ' ', WIDTH - (int)ft_strlen(s));
	return (s);
}

void	init_size_n_sign(int *sign, int *size, char **tmp, t_env *env)
{
	*sign = **tmp == '-' ? -1 : 0;
	if (**tmp == '-')
		*tmp = *tmp + 1;
	if (**tmp == '0' && PRECISION == 0)
		**tmp = 0;
	*size = PRECISION > (int)ft_strlen(*tmp) ? PRECISION : (int)ft_strlen(*tmp);
	*size = *size < WIDTH ? WIDTH : *size;
}

char	*malloc_s(int *sign, int *size, t_env *env)
{
	char	*s;

	s = ft_memalloc(*size + (*sign == -1 || F_PLUS || F_SPACE ? 1 : 0) + 1);
	*size = !F_NEG && WIDTH - PRECISION - 1 > 0 ? WIDTH - PRECISION - 1 : 0;
	F_NEG && (*sign == -1 || F_PLUS || F_SPACE) && !*size ? ++*size : 0;
	return (s);
}

char	*option_di(char *s, t_env *env)
{
	char	*s2;
	int		sign;
	char	*tmp;
	int		sz;
	int		np;

	tmp = s;
	init_size_n_sign(&sign, &sz, &s, env);
	s2 = malloc_s(&sign, &sz, env);
	np = (!F_NEG && WIDTH - PRECISION >= 0 ? WIDTH - PRECISION : 0) +
	(!F_NEG && SIGN && WIDTH - PRECISION < 0 ? 1 : 0) + (F_NEG && SIGN ? 1 : 0);
	if (apply_precision(s, s2 + np, env) && !F_NEG && (np = (int)ft_strlen(s)))
	{
		if (!F_ZERO && sz > WIDTH)
			put_sign(sign, s2 + ((sz - np - 1) > 0 ? (sz - np) : 0), env);
		if (WIDTH > PRECISION && WIDTH > np)
			ft_memset(s2, F_ZERO && PRECISION == -1 ?
					'0' : ' ', WIDTH - (PRECISION > np ? PRECISION : np));
		(F_ZERO || sz <= WIDTH) ? put_sign(sign, after_space(s2, env), env) : 0;
		ft_strcat(after_zero(after_space(s2, env)), s);
	}
	else
		s2 = inverse(sign, s, s2, env);
	free(tmp);
	return (s2);
}

void	type_di(t_env *env, va_list ap)
{
	long			tmp;
	char			*ret;
	char			*s;

	if (env->size & 1)
		tmp = (signed char)va_arg(ap, int);
	else if ((env->size & (1 << 1)))
		tmp = (short)va_arg(ap, int);
	else if ((env->size & (1 << 2)) || (env->size & (1 << 3)) ||
			(env->type == 'D'))
		tmp = va_arg(ap, long);
	else if (env->size & 1 << 4)
		tmp = va_arg(ap, intmax_t);
	else if ((env->size & (1 << 5)))
		tmp = va_arg(ap, size_t);
	else
		tmp = va_arg(ap, int);
	env->nb_signed = tmp;
	ret = ft_itoa_base(tmp, "0123456789");
	s = option_di(ret, env);
	ret = s;
	save_endofs(env->beg, &s, ft_strlen(s), env);
	free(ret);
}
