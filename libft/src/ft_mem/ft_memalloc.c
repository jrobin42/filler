/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:07:10 by jrobin            #+#    #+#             */
/*   Updated: 2018/01/30 06:53:11 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mem.h"

void	*ft_memalloc(size_t size)
{
	void			*tab;

	if (!(tab = (void *)malloc(size)))
		exit(1);
	ft_bzero(tab, size);
	return (tab);
}
