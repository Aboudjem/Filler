/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:31:52 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:32:21 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_p(t_conv *t)
{
	int					mod;
	char				*str;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "0123456789abcdef";
	nb = (unsigned long int)t->p;
	if (nb == 0)
		t->str = ft_strdup("0");
	else
	{
		str = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 16);
			str[i] = s[mod];
			i++;
			nb /= 16;
		}
		t->str = revert_str(str, i);
	}
}

void	conv_p(t_conv *t, t_flags f)
{
	ft_hexa_p(t);
	if (t->p == 0 && (f.pre == 1 && f.dot == 0))
		t->str = ft_strdup("");
	t->sign = ft_strdup("0x");
	if (f.pre == 1 && f.pad == 0 && t->u == 0 && f.dot == 0)
		t->str = ft_strdup(t->sign);
	else
	{
		t->len_d = (int)ft_strlen(t->str);
		if (f.pre == 0)
			p_fill_nodot(t, f);
		else
			p_join(t, f);
	}
	t->len_return = (int)ft_strlen(t->str);
}
