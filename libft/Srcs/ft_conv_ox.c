/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:32:38 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/08 23:38:07 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_x(t_conv *t, t_flags f)
{
	init(t);
	ft_hashtag(t, f);
	ft_hexa(t);
	t->len_d += ft_strlen(t->nb);
	if (f.pre == 0)
		x_fill_nodot(t, f);
	else
	{
		f = handle_d(f);
		fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	if (t->conv == 'X')
		ft_strtoupper(t->str);
	t->len_return = (int)ft_strlen(t->str);
}

void	conv_o(t_conv *t, t_flags f)
{
	init(t);
	ft_hashtag(t, f);
	ft_octal(t);
	t->len_d += ft_strlen(t->nb);
	if (f.pre == 0)
		x_fill_nodot(t, f);
	else
	{
		f = handle_d(f);
		u_fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}

void	conv_b(t_conv *t, t_flags f)
{
	init(t);
	if (t->conv == 'b')
		ft_binary(t);
	else if (t->conv == 'q')
		ft_quintal(t);
	t->len_d += ft_strlen(t->nb);
	if (f.pre == 0)
		x_fill_nodot(t, f);
	else
	{
		u_fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
