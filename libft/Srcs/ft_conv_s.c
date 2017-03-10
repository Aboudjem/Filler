/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:30:19 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 01:32:22 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s_zero(t_conv *t, t_flags f)
{
	if (f.zero == 0 && f.pad)
		t->str = ft_strset(' ', f.pad);
	else if (f.zero == 1 && f.pad)
		t->str = ft_strset('0', f.pad);
	else
	{
		t->str = ft_strdup("(null)");
		t->str = ft_strsub(t->str, 0, f.dot);
	}
	t->print = ft_strjoin(t->print, t->str);
	t->len_return = ft_strlen(t->str);
	t->str = ft_strdup("");
}

void	conv_s(t_conv *t, t_flags f)
{
	if (!t->s && f.pre == 0)
	{
		t->str = ft_strdup("(null)");
		t->len_return = 6;
	}
	else if (!t->s && f.pre == 1)
		conv_s_zero(t, f);
	else
	{
		t->str = ft_strdup(t->s);
		s_join(t, f);
		t->len_return = ft_strlen(t->str);
	}
}
