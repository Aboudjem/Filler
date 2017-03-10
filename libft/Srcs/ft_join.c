/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:28:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 00:34:38 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_join(t_conv *t, t_flags f)
{
	int i;

	if (f.pre == 1 && f.dot == 0)
	{
		t->str = (f.zero == 1) ? ft_strdup("0") : ft_strdup(" ");
		f.pre = 0;
	}
	if (t->conv == 'S')
		i = s_pre(t, f);
	else
		i = f.dot;
	if (f.pre == 0)
		s_fill_nodot(t, f);
	else if (f.pre == 1)
	{
		if (f.dot < (int)ft_strlen(t->str))
			t->str = ft_strsub(t->str, 0, i);
		s_fill_space(t, f);
		if (f.neg == 1)
			t->str = ft_strjoin(t->str, t->space);
		else
			t->str = ft_strjoin(t->space, t->str);
	}
}

void	join(t_conv *t, t_flags f)
{
	char *s;

	if (((t->d == 0 && f.d_used == 1) ||
				(t->u == 0 && f.u_used == 1)) && f.pre == 1)
		t->str = handle_zero(*t, f);
	else
	{
		if (f.negdot == 1 || f.neg == 1)
			join_neg(t, f);
		else
		{
			s = ft_strjoin(t->space, t->sign);
			s = ft_strjoin_free(&s, &t->zero, 1);
			t->str = ft_strjoin_free(&s, &t->nb, 1);
		}
	}
}

void	join_neg(t_conv *t, t_flags f)
{
	char *s;

	if (f.negdot == 1)
	{
		if (ft_strlen(t->zero) > 0)
			t->space = ft_strset(' ',
					(ft_strlen(t->zero)) - ft_strlen(t->sign));
		else if (f.dot != 0)
			t->space = ft_strdup("");
		s = ft_strjoin(t->sign, t->nb);
		t->str = ft_strjoin_free(&s, &t->space, 1);
	}
	else if (f.neg == 1)
	{
		s = ft_strjoin(t->sign, t->zero);
		s = ft_strjoin_free(&s, &t->nb, 1);
		t->str = ft_strjoin_free(&s, &t->space, 1);
	}
}

void	p_join(t_conv *t, t_flags f)
{
	p_fill_space(t, f);
	p_fill_zero(t, f);
	t->str = ft_strjoin(t->zero, t->str);
	t->str = ft_strjoin(t->sign, t->str);
	if (f.neg == 1)
		t->str = ft_strjoin(t->str, t->space);
	else
		t->str = ft_strjoin(t->space, t->str);
}
