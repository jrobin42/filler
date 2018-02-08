/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:27:25 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/03 07:03:12 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int		save_begofs(char *beg, char **s, t_env *env)
{
	while (*s && **s && **s != '%')
	{
		if (env->actual_len == BUFF_SIZE)
		{
			write(1, beg, BUFF_SIZE);
			ft_bzero(beg, BUFF_SIZE);
			env->len = env->len + BUFF_SIZE;
			env->actual_len = 0;
		}
		beg[env->actual_len] = **s;
		++(*s);
		++(env->actual_len);
	}
	if (*s && **s && **s == '%')
		++(*s);
	else
		return (0);
	return (1);
}

int		save_endofs(char *beg, char **s, size_t size, t_env *env)
{
	while (size)
	{
		if (env->actual_len == BUFF_SIZE)
		{
			write(1, beg, BUFF_SIZE);
			ft_bzero(beg, BUFF_SIZE);
			env->len = env->len + BUFF_SIZE;
			env->actual_len = 0;
		}
		beg[env->actual_len] = **s;
		++(*s);
		++(env->actual_len);
		--size;
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	t_env	env;
	char	*cpy;

	if (!s)
		return (0);
	ft_bzero(&env, sizeof(t_env));
	cpy = (char*)s;
	va_start(ap, s);
	if (check_percent(cpy) < 0)
	{
		ft_putstr(cpy);
		return (ft_strlen(cpy));
	}
	while (save_begofs(env.beg, &cpy, &env))
	{
		parse_percent(&cpy, &env);
		if (g_tab[(int)env.type])
			g_tab[(int)env.type](&env, ap);
	}
	va_end(ap);
	write(1, env.beg, env.actual_len);
	return (env.len + env.actual_len);
}
