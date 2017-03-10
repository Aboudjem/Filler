/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:36:08 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:36:23 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_fill_zero(t_conv *t, t_flags f)
{
	if (f.dot > t->len_d)
		t->len_zero = f.dot - t->len_d;
	else
		t->len_space = 0;
	t->zero = ft_strset('0', t->len_zero);
}

void	p_fill_space(t_conv *t, t_flags f)
{
	if (f.pad > (t->len_d + 2))
		t->len_space = f.pad - (t->len_d + 2);
	else
		t->len_space = 0;
	t->space = ft_strset(' ', t->len_space);
}

void	s_fill_space(t_conv *t, t_flags f)
{
	if (f.pad > (int)ft_strlen(t->str))
		t->len_space = f.pad - (int)ft_strlen(t->str);
	else
		t->len_space = 0;
	t->space = ft_strset(' ', t->len_space);
}

void	u_fill_space(t_conv *t, t_flags f)
{
	if (f.dot > f.pad && (f.pad >= t->len_d))
		t->len_space = 0;
	else if (f.pad >= f.dot)
	{
		if (f.dot > t->len_d && ((f.pad - f.dot) > 0))
			t->len_space = ((f.pad - f.dot) - ft_strlen(t->sign));
		else if (f.pad == f.dot)
			t->space = t->space;
		else
		{
			if (f.dot >= (int)ft_strlen(t->nb))
				t->len_space = (f.pad - (f.dot + ft_strlen(t->sign)));
			else if (f.pad >= t->len_d)
				t->len_space = (f.pad - t->len_d);
		}
	}
	t->space = ft_strset(' ', t->len_space);
}

void	u_fill_zero(t_conv *t, t_flags f)
{
	if (f.dot > f.pad)
	{
		f.pad = (f.dot > f.pad) ? f.dot : f.pad;
		if (f.pad > t->len_d)
			t->len_zero = f.pad - t->len_d;
	}
	else if (f.pad >= f.dot)
	{
		if ((f.dot) > t->len_d)
			t->len_zero = f.dot - t->len_d;
	}
	t->zero = ft_strset('0', t->len_zero);
}
