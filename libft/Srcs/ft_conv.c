/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:34:40 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 11:16:28 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_conv *t, t_flags f)
{
	if (f.dot > f.pad && (f.pad >= t->len_d))
		t->len_space = 0;
	else if (f.pad >= f.dot)
	{
		if (f.dot > t->len_d && ((f.pad - f.dot) > 0))
			t->len_space = ((f.pad - f.dot) - ft_strlen(t->sign));
		else if (f.pad != f.dot)
		{
			if (f.dot >= (int)ft_strlen(t->nb))
				t->len_space = (f.pad - (f.dot + ft_strlen(t->sign)));
			else if (f.pad >= t->len_d)
				t->len_space = (f.pad - t->len_d);
		}
	}
	t->space = ft_strset(' ', t->len_space);
}

void	fill_zero(t_conv *t, t_flags f)
{
	if (f.dot > f.pad)
	{
		f.pad = (f.dot > f.pad) ? f.dot : f.pad;
		if (f.pad > (int)ft_strlen(t->nb))
			t->len_zero = f.pad - (ft_strlen(t->nb));
	}
	else if (f.pad >= f.dot)
	{
		if ((f.dot) > (int)ft_strlen(t->nb))
			t->len_zero = f.dot - ft_strlen(t->nb);
	}
	t->zero = ft_strset('0', t->len_zero);
}

char	*handle_zero(t_conv t, t_flags f)
{
	char *s;

	if (f.pre == 1)
	{
		t.nb = ft_strdup("");
		f = handle_d(f);
		fill_zero(&t, f);
		fill_space(&t, f);
		s = ft_strjoin(t.space, t.zero);
		s = ft_strjoin_free(&s, &t.nb, 1);
		return (ft_strjoin(s, t.sign));
	}
	return (t.nb);
}
