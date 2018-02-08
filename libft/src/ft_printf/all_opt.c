/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 03:08:58 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 06:51:41 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(char *s, char *s2, t_env *env)
{
	int		len;

	len = (int)ft_strlen(s);
	if (!env->nb || !F_HASH || PRECISION > len)
	{
		while (env->precision - len - 1 >= 0)
		{
			s2[env->precision - len - 1] = '0';
			++len;
		}
	}
	return (s2);
}

char	*apply_sign(char *s, t_env *env)
{
	if (s && (F_PLUS || F_SPACE) && env->nb_signed >= 0)
		*after_space(s, env) = F_PLUS ? '+' : ' ';
	return (s);
}

char	*apply_hash(char *s, t_env *env)
{
	char	*tmp;

	if (F_HASH && s)
	{
		if ((TYPE == 'o' || TYPE == 'O') && ((!*s || *s != '0') ||
					(env->nb && PRECISION != -1)))
			*s = '0';
		else if (TYPE == 'p' || ((TYPE == 'x' || TYPE == 'X') && env->nb))
		{
			if (!enough_space(s) || (PRECISION != -1 &&
						WIDTH < (int)ft_strlen(s)))
				ft_memmove(s + 2, s, ft_strlen(s));
			tmp = after_space(s, env);
			ft_memcpy(tmp = tmp >= (s + 2) && !enough_space2(tmp) ? tmp - 2 :
					tmp, TYPE != 'X' ? "0x" : "0X", 2);
		}
	}
	return (s);
}

char	*apply_width(char *s, t_env *env)
{
	int		len;
	char	*width;

	if (WIDTH > (len = (int)ft_strlen(s)))
	{
		width = ft_memalloc(WIDTH + 1);
		ft_memset(width, (F_ZERO && !F_NEG && PRECISION == -1) ? '0' : ' ',
			WIDTH - len);
		if (F_NEG)
			s = ft_strcat(s, width);
		else
		{
			ft_memmove(s + (WIDTH - len), s, len);
			s = ft_memcpy(s, width, WIDTH - len);
		}
		free(width);
	}
	return (s);
}
