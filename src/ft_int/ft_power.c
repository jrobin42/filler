/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 06:09:42 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/07 21:45:25 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_int.h"

int		ft_power(int nb, int power)
{
	int		save_nb;

	save_nb = nb;
	if (!power)
		return (1);
	while (power > 1)
	{
		nb = nb * save_nb;
		--power;
	}
	return (nb);
}
