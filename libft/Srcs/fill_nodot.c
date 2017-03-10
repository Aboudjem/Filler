/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:35:36 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:35:49 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_fill_nodot(t_conv *t, t_flags f)
{
	int len;

	len = (int)ft_strlen(t->str);
	if (len == 0 && t->conv != 's')
		len++;
	if (f.pre == 0 || t->conv == 'c' || t->conv == 's')
	{
		if (f.zero == 0 && f.pad > len)
			t->space = ft_strset(' ', f.pad - len);
		else if (f.zero == 1 && f.pad > len)
			t->zero = ft_strset('0', f.pad - len);
	}
	s_nodot_join(t, f);
}

void	s_nodot_join(t_conv *t, t_flags f)
{
	if (f.neg == 1)
	{
		if (t->zero)
			t->str = ft_strjoin(t->zero, t->str);
		if (t->space)
			t->str = ft_strjoin(t->str, t->space);
	}
	else
	{
		if (t->zero)
			t->str = ft_strjoin(t->zero, t->str);
		if (t->space)
			t->str = ft_strjoin(t->space, t->str);
	}
}

void	x_fill_nodot(t_conv *t, t_flags f)
{
	if (f.pre == 0 && f.neg == 0)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->zero = ft_strset('0', f.pad - t->len_d);
	}
	else if (f.pre == 0 && f.neg == 1)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
	}
}

void	p_fill_nodot(t_conv *t, t_flags f)
{
	if (t->len_d == 0)
		t->len_d++;
	if (f.pre == 0)
	{
		if (f.zero == 0 && f.pad > (t->len_d + 2))
			t->space = ft_strset(' ', f.pad - (t->len_d + 2));
		else if (f.zero == 1 && f.pad > (t->len_d + 2))
			t->zero = ft_strset('0', f.pad - (t->len_d + 2));
	}
	t->str = ft_strjoin(t->zero, t->str);
	t->str = ft_strjoin(t->sign, t->str);
	if (f.neg == 1)
		t->str = ft_strjoin(t->str, t->space);
	else
		t->str = ft_strjoin(t->space, t->str);
}

void	fill_nodot(t_conv *t, t_flags f)
{
	if (f.pre == 0)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->zero = ft_strset('0', f.pad - t->len_d);
	}
}
