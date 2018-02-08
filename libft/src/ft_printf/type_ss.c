/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:36:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 18:11:20 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_ss(t_env *env, va_list ap)
{
	wchar_t		*s1;
	char		**s2;
	char		*s3;
	int			i;
	char		*tmp;

	s2 = NULL;
	if ((s1 = va_arg(ap, wchar_t*)))
	{
		!(i = ft_wchar_t(s1)) ? ++i : 0;
		s2 = ft_memalloc((i + 1) * sizeof(char*));
		s3 = ft_memalloc((i * 4 + 1) * sizeof(char));
	}
	if (!(i = 0) && !s1)
		s3 = ft_strdup("(null)");
	while (s1 && *s1 && s2 && s3 && ++i)
	{
		*(s2 + i - 1) = trad_cc(*s1++);
		s3 = ft_strcat(s3, *(s2 + i - 1));
	}
	tmp = option_s(s3, env);
	s3 = tmp;
	save_endofs(env->beg, &tmp, ft_strlen(tmp), env);
	ft_free_tab(s2);
	free(s3);
}
