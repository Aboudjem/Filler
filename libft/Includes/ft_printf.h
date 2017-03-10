/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:12:24 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/08 23:58:53 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <locale.h>

typedef struct	s_type
{
	unsigned long long int	u;
	long long				d;
	unsigned int			c;
	wchar_t					*w;
	va_list					arguments;
	char					*s;
	void					*p;
	int						len;
	int						count;
	int						neg;
	char					*space;
	char					*zero;
	char					*nb;
	char					*sign;
	int						len_d;
	int						len_space;
	int						len_zero;
	int						len_return;
	char					conv;
	char					*str;
	char					*print;
	int						i;
	int						j;
	int						ret;
}				t_conv;

typedef struct	s_flags
{
	int zero;
	int space;
	int neg;
	int plus;
	int prcnt;
	int hash;
	int dot;
	int l;
	int ll;
	int h;
	int hh;
	int j;
	int z;
	int pad;
	int pre;
	int negdot;
	int champs;
	int len_pre;
	int len_pad;
	int u_used;
	int d_used;
}				t_flags;

/*
 ** ft_printf.c
*/
void			len_return(t_conv *t, t_flags f);
void			len_return2(t_conv *t, t_flags f);
void			printstr(const char *s, t_conv *t);
int				ft_printf(const char *format, ...);
void			get_conv(const char *s, int i, t_conv *t, t_flags f);

/*
 ** modif_length.c
*/
void			which_length(const char *s, int i, t_flags *f);
void			modif_length2(t_flags *f, t_conv *t);
void			modif_length(t_flags *f, t_conv *t);
void			get_length_u(t_flags *f, t_conv *t);
void			get_length(t_flags *f, t_conv *t);

/*
 ** ft_no_conv.c
*/
void			noconv_join(t_conv *t, t_flags f);
void			no_conv(const char *s, int i, t_conv *t, t_flags f);

/*
 ** fill_nodot.c
*/
void			s_fill_nodot(t_conv *t, t_flags f);
void			s_nodot_join(t_conv *t, t_flags f);
void			x_fill_nodot(t_conv *t, t_flags f);
void			p_fill_nodot(t_conv *t, t_flags f);
void			fill_nodot(t_conv *t, t_flags f);

/*
 ** ft_checkconv.c
*/
void			which_conv(const char *s, int i, t_conv *t, t_flags f);
void			which_flags(const char *s, int i, t_conv t, t_flags *f);

/*
 ** ft_conv.c
*/
void			fill_space(t_conv *t, t_flags f);
void			fill_zero(t_conv *t, t_flags f);
char			*handle_zero(t_conv t, t_flags f);

/*
 ** ft_conv_bigu.c
*/
void			nb_sign_u(t_conv *t, t_flags f);
void			conv_u(t_conv *t, t_flags f);

/*
 ** ft_conv_percent.c
*/
void			conv_percent(t_conv *t, t_flags f);

/*
 ** ft_conv_s.c
*/
void			conv_s(t_conv *t, t_flags f);

/*
 ** ft_conv_unicode.c
*/
int				len_wc(unsigned int c);
int				s_pre(t_conv *t, t_flags f);
void			conv_ws(t_conv *t, t_flags f);
void			conv_wc(unsigned long int c, t_conv *t);
void			how_long(unsigned long int c, t_conv *t);

/*
 ** ft_conv_unicode2.c
*/
void			one_bytes(unsigned long int c, t_conv *t);
void			two_bytes(unsigned long int c, t_conv *t);
void			three_bytes(unsigned long int c, t_conv *t);
void			four_bytes(unsigned long int c, t_conv *t);
void			how_long2(unsigned long int c, t_conv *t);

/*
 ** ft_join.c
*/
void			s_join(t_conv *t, t_flags f);
void			join(t_conv *t, t_flags f);
void			p_join(t_conv *t, t_flags f);
void			join_neg(t_conv *t, t_flags f);

/*
 ** fill.c
*/
void			u_fill_space(t_conv *t, t_flags f);
void			u_fill_zero(t_conv *t, t_flags f);
void			s_fill_space(t_conv *t, t_flags f);
void			p_fill_zero(t_conv *t, t_flags f);
void			p_fill_space(t_conv *t, t_flags f);

/*
 ** ft_utils.c
*/
int				ft_wstrcmp(const wchar_t *s1, const wchar_t *s2);
char			*ft_litoa(unsigned long long int n);
void			*ft_strset(int c, size_t len);
void			init_flags(t_flags *f);
int				ft_len_int(int nbr);

/*
 ** ft_utils2.c
*/
void			get_padding(const char *s, int i, t_flags *f);
void			get_precision(const char *s, int i, t_flags *f);
int				is_flag(const char *s, int i);
char			next_conv(const char *s, int i);
void			init(t_conv *t);

/*
 ** ft_utils3.c
*/
void			ft_hexa(t_conv *t);
void			ft_octal(t_conv *t);
void			init_start(t_conv *t);
char			*revert_str(char *str, int i);
void			ft_hashtag(t_conv *t, t_flags f);

/*
 ** ft_utils4.c
*/
void			ft_quintal(t_conv *t);
void			ft_binary(t_conv *t);
void			how_long3(unsigned long int c, t_conv *t);
/*
 ** ft_conv_d.c
*/
void			conv_d(t_conv *t, t_flags f);
t_flags			handle_d(t_flags f);
void			nb_sign(t_conv *t, t_flags f);

/*
 ** ft_conv_ox.c
*/
void			conv_x(t_conv *t, t_flags f);
void			conv_o(t_conv *t, t_flags f);
void			conv_b(t_conv *t, t_flags f);

/*
 ** ft_conv_c.c
*/
void			conv_c(t_conv *t, t_flags f);

/*
 ** ft_conv_p.c
*/
void			ft_hexa_p(t_conv *t);
void			conv_p(t_conv *t, t_flags f);

#endif
