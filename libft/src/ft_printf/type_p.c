/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/01 08:57:35 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_p(t_env *env, va_list ap)
{
	unsigned long	tmp;
	char			*tmp2;
	char			*s1;

	tmp = va_arg(ap, unsigned long);
	env->nb = tmp;
	s1 = ft_ultoa_base(tmp, "0123456789abcdef");
	env->opt = (env->opt | 1 << 3);
	s1 = option_x(s1, env);
	tmp2 = s1;
	save_endofs(env->beg, &s1, ft_strlen(s1), env);
	free(tmp2);
}
