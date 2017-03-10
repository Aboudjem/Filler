/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:19:56 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 00:35:34 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_padding(const char *s, int i, t_flags *f)
{
	int j;

	j = 0;
	f->zero = (s[i] == '0') ? 1 : f->zero;
	f->champs = 1;
	while (ft_isdigit(s[i]) == 0)
	{
		j++;
		i++;
	}
	f->zero = (s[i] == '0') ? 1 : f->zero;
	f->pad = ft_atoi(s + i);
	while (ft_isdigit(s[i]) == 1)
	{
		j++;
		i++;
	}
	f->plus = (s[i] == '+') ? 1 : f->plus;
	f->neg = (s[i] == '-') ? 1 : f->neg;
	f->len_pad = j;
}

void	get_precision(const char *s, int i, t_flags *f)
{
	f->pre = (s[i] == '.') ? 1 : f->pre;
	i++;
	f->negdot = (s[i] == '-') ? 1 : f->negdot;
	f->dot = ft_atoi(s + i);
	f->len_pre = i + f->pre + f->negdot;
}

int		is_flag(const char *s, int i)
{
	int		j;
	char	*flag;

	j = 0;
	flag = " -#+.0123456789lhjz";
	while (flag[j] != '\0')
	{
		if (s[i] != flag[j])
			j++;
		else
			return (1);
	}
	return (0);
}

char	next_conv(const char *s, int i)
{
	int		j;
	char	*conv;

	j = 0;
	conv = "qbsSpdDioOuUxXcC%";
	while (conv[j] != '\0')
	{
		if (s[i] == conv[j])
			return (conv[j]);
		j++;
	}
	if (is_flag(s, i) == 0)
		return (1);
	return (0);
}

void	init(t_conv *t)
{
	t->len_d = 0;
	t->len_space = 0;
	t->len_zero = 0;
	t->sign = "";
	t->space = "";
	t->zero = "";
	t->str = NULL;
	t->len_return = 0;
}
