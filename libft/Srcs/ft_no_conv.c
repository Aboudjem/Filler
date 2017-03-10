/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:27:45 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:28:06 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	noconv_join(t_conv *t, t_flags f)
{
	if (f.zero == 0 && f.pad >= 1)
	{
		t->space = ft_strset(' ', f.pad - 1);
		if (f.neg == 1)
			t->str = ft_strjoin(t->str, t->space);
		else
			t->str = ft_strjoin(t->space, t->str);
	}
	else if (f.zero == 1 && f.pad >= 1)
	{
		t->zero = ft_strset('0', f.pad - 1);
		t->str = ft_strjoin(t->zero, t->str);
	}
}

void	no_conv(const char *s, int i, t_conv *t, t_flags f)
{
	int k;

	k = 0;
	if (!s[i + 1] && s[i] == '%')
	{
		t->len_return = 0;
		t->str = ft_strdup("");
	}
	else
	{
		k = i;
		while (s[k + 1] != '%' && s[k + 1] != '\0')
			k++;
		t->str = ft_strsub(s, i, k - i);
		noconv_join(t, f);
		t->len_return = (int)ft_strlen(t->str);
		t->print = ft_strjoin_free(&t->print, &t->str, 3);
		t->count += (k - i);
	}
}
