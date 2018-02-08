/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 21:22:21 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*trad_cc(int nb)
{
	int				i;
	unsigned char	*b1;

	i = 0;
	b1 = ft_memalloc(5);
	if (nb <= 0x7f)
		*b1 = nb;
	if (nb > 0x7f && ++i && nb <= 0x7ff)
		*b1 = (((nb << 2) & 0x1f00) >> 8) | 0xc0;
	if (nb > 0x7ff && ++i && nb <= 0xffff)
		*b1 = (nb >> 12) | 0xe0;
	if (nb > 0xffff && ++i)
	{
		*b1 = (((nb >> 18) & 0x7) | 0xf0);
		*(b1 + 1) = (((nb >> 12) & 0x3f) | 0x80);
	}
	if (nb > 0x7f && nb <= 0x10ffff)
		*(b1 + i - 1) = nb > 0x7ff ? ((nb >> 6) & 0x3f) | 0x80 : *(b1 + i - 1);
	*(b1 + i) = nb > 0x7f ? ((nb & 0x3f) | 0x80) : *(b1 + i);
	return ((char *)b1);
}

void	type_cc(t_env *env, va_list ap)
{
	int				nb;
	char			*b1;
	char			*tmp;

	nb = va_arg(ap, int);
	b1 = trad_cc(nb);
	b1 = option_s(b1, env);
	tmp = b1;
	if (nb == 0)
		save_endofs(env->beg, &b1, ft_strlen(tmp) ? ft_strlen(tmp) : 1, env);
	else
		save_endofs(env->beg, &b1, ft_strlen(tmp), env);
	free(tmp);
}
