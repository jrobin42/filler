/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:58:48 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/02 18:18:27 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	(*const g_tab[127])(t_env *, va_list) =
{
	['%'] = &percent,
	['d'] = &type_di,
	['D'] = &type_di,
	['i'] = &type_di,
	['c'] = &type_c,
	['C'] = &type_cc,
	['o'] = &type_uo,
	['O'] = &type_uo,
	['p'] = &type_p,
	['s'] = &type_s,
	['S'] = &type_ss,
	['u'] = &type_uo,
	['U'] = &type_uo,
	['x'] = &type_x,
	['X'] = &type_x
};
