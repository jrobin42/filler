/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:26:38 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 05:23:28 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include "libft_str.h"
# include <stdlib.h>

void			*ft_memmove(void *dest, const void *src, unsigned long n);
void			*ft_memcpy(void *dest, const void *src, unsigned long n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memset(void *dest, int c, unsigned long n);
void			*ft_memchr(const void *s, int c, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, unsigned long n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

#endif
