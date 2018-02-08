/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:22:19 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/01 05:44:53 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		option(char **s, t_env *env)
{
	while (*s && (**s == '-' || **s == '+' || **s == '#' || **s == '0'
	|| **s == ' '))
	{
		if (**s == '-')
			env->opt = (env->opt | (1 << 0));
		else if (**s == '+')
			env->opt = (env->opt | (1 << 1));
		else if (**s == '0')
			env->opt = (env->opt | (1 << 2));
		else if (**s == '#')
			env->opt = (env->opt | (1 << 3));
		else if (**s == ' ')
			env->opt = (env->opt | (1 << 4));
		++(*s);
	}
	return (0);
}

int		width(char **s, t_env *env)
{
	env->width = ft_atoi(*s);
	while (*s && **s >= '0' && **s <= '9')
		++(*s);
	return (0);
}

int		precision(char **s, t_env *env)
{
	++(*s);
	env->precision = ft_atoi(*s);
	while (*s && **s >= '0' && **s <= '9')
		++(*s);
	return (0);
}

void	size(char **s, t_env *env)
{
	if (**s == 'h')
	{
		if (*(*s + 1) && (*(*s + 1) == 'h'))
		{
			env->size = (env->size | 1);
			++(*s);
		}
		else
			env->size = (env->size | (1 << 1));
	}
	else if (**s == 'l')
	{
		if (*(*s + 1) && (*(*s + 1) == 'l'))
		{
			env->size = (env->size | 1 << 2);
			++(*s);
		}
		else
			env->size = (env->size | (1 << 3));
	}
	else if (**s == 'j')
		env->size = (env->size | (1 << 4));
	else if (**s == 'z')
		env->size = (env->size | (1 << 5));
	++(*s);
}

int		parse_percent(char **s, t_env *env)
{
	env->opt = 0;
	env->size = 0;
	env->width = 0;
	env->precision = -1;
	if (*s && (**s == '-' || **s == '+' || **s == '#' || **s == '0'
	|| **s == ' '))
		option(s, env);
	if (*s && (**s >= '0' && **s <= '9'))
		width(s, env);
	if (*s && **s == '.')
		precision(s, env);
	if (*s && (**s == 'l' || **s == 'z' || **s == 'h' || **s == 'j'))
		size(s, env);
	if (*s)
	{
		env->type = **s;
		++(*s);
	}
	return (0);
}
