/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:26:38 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 06:22:25 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft_mem.h"

# define BUFF_SIZE_GNL 1500

int				get_next_line(const int fd, char **line);
char			*ft_freejoin(char *s1, char *s2, int sfr);
char			*ft_reverse(char *s);
void			ft_bzero(void *s, unsigned long n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *phrase, const char *mot);
char			*ft_strnstr(const char *phrase, const char *mot, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, unsigned long size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strsplit(char const *str, char c);

#endif
