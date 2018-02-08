/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:04:11 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/07 18:12:00 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

int		ft_strequ(char const *s1, char const *s2)
{
	return (s1 && s2 ? (ft_strcmp(s1, s2) == 0) : 0);
}
