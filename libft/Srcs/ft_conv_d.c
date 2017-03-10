/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:34:10 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 00:24:30 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	handle_d(t_flags f)
{
	if (f.pre == 1 && f.champs == 0)
		f.pad = 0;
	if (f.plus == 1)
		f.space = 0;
	if (f.neg == 1 && f.zero == 1)
		f.zero = 0;
	return (f);
}

void	nb_sign(t_conv *t, t_flags f)
{
	t->nb = (t->d >= 0) ? ft_itoa(t->d) : ft_litoa(-t->d);
	if (t->d >= 0 && f.plus == 1)
		t->sign = "+";
	else if (t->d < 0)
		t->sign = "-";
	else if (f.space == 1)
		t->sign = " ";
	else
		t->sign = "";
	t->len_d = (int)ft_strlen(t->nb) + (int)ft_strlen(t->sign);
}

void	conv_d(t_conv *t, t_flags f)
{
	init(t);
	f = handle_d(f);
	nb_sign(t, f);
	if (f.pre == 0)
		fill_nodot(t, f);
	else
	{
		fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
