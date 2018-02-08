/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:26:38 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 05:21:13 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_str.h" 
# include "libft_clear.h" 
# include <stdlib.h> 

void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putnbr(int n);

#endif
