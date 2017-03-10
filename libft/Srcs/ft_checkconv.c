/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:18:03 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 00:37:06 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	which_conv(const char *s, int i, t_conv *t, t_flags f)
{
	t->count = 0;
	if (s[i] && s[i + 1])
	{
		i++;
		t->count++;
	}
	while (next_conv(s, i) == 0 && s[i + 1])
	{
		t->count++;
		i++;
	}
	if (next_conv(s, i) == 1)
		t->count--;
	t->conv = next_conv(s, i);
	get_conv(s, i, t, f);
}

void	which_flags(const char *s, int i, t_conv t, t_flags *f)
{
	init_flags(f);
	t.count = 0;
	i++;
	while (is_flag(s, i) == 1 && s[i] != '\0' && i < (int)ft_strlen(s))
	{
		f->space = (s[i] == ' ') ? 1 : f->space;
		f->neg = (s[i] == '-') ? 1 : f->neg;
		f->plus = (s[i] == '+') ? 1 : f->plus;
		f->hash = (s[i] == '#') ? 1 : f->hash;
		if (s[i] >= '0' && s[i] <= '9' && f->pre == 0)
		{
			get_padding(s, i, f);
			i += f->len_pad;
		}
		if (s[i] == '.')
		{
			get_precision(s, i, f);
			i += f->len_pre;
		}
		which_length(s, i, f);
		t.count++;
		i++;
	}
}
