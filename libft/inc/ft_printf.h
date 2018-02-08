/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:03:08 by jrobin            #+#    #+#             */
/*   Updated: 2018/02/08 05:21:34 by jrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft_int.h"
# include "libft_str.h"
# include "libft_mem.h"
# include "libft_put.h"


# define BUFF_SIZE 400

# define F_NEG (env->opt & 1)
# define F_PLUS (env->opt & 1 << 1)
# define F_ZERO (env->opt & 1 << 2)
# define F_HASH (env->opt & 1 << 3)
# define F_SPACE (env->opt & 1 << 4)

# define WIDTH (env->width)
# define PRECISION (env->precision)
# define TYPE (env->type)
# define SIGN (sign == -1 || F_SPACE || F_PLUS)

typedef struct	s_env
{
	int					len;
	int					actual_len;
	char				beg[BUFF_SIZE];
	char				opt;
	int					width;
	int					precision;
	char				size;
	char				type;
	unsigned long		nb;
	long				nb_signed;
}				t_env;

char			*option_s(char *tmp, t_env *env);
char			*after_space(char *s, t_env *env);
char			*after_zero(char *s);
char			*option_x(char *tmp, t_env *env);
char			*option_uo(char *s, t_env *env);
int				ft_printf(const char *s, ...);
int				enough_space(char *s);
int				enough_space2(char *s);
int				save_begofs(char *beg, char **s, t_env *env);
int				save_endofs(char *beg, char **s, size_t size, t_env *env);
int				check_percent(char *s);
int				parse_percent(char **s, t_env *env);
char			*trad_cc(int nb);
void			trad_percent(t_env *env, va_list ap);
void			percent(t_env *env, va_list ap);
void			type_s(t_env *env, va_list ap);
void			type_ss(t_env *env, va_list ap);
void			type_uo(t_env *env, va_list ap);
void			type_c(t_env *env, va_list ap);
void			type_cc(t_env *env, va_list ap);
void			type_p(t_env *env, va_list ap);
void			type_x(t_env *env, va_list ap);
void			type_di(t_env *env, va_list ap);
char			*sign(int signe, char *nb, char *s, t_env *env);
char			*precision_di(char *s, char *s2, t_env *env);
char			*apply_precision(char *s, char *s2, t_env *env);
char			*apply_hash(char *s, t_env *env);
char			*apply_sign(char *s, t_env *env);
char			*apply_width(char *s, t_env *env);
char			*inverse(int signe, char *nb, char *s, t_env *env);
char			*after_space(char *s, t_env *env);
char			*after_zero(char *s);
char			*option_di(char *tmp, t_env *env);
int				put_sign(int signe, char *s, t_env *env);
char			*opt_zero(char *s, t_env *env);
extern void		(*const g_tab[127])(t_env *, va_list);
#endif
