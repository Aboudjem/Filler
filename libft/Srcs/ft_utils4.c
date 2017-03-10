/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 22:56:30 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/08 23:44:57 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	how_long3(unsigned long int c, t_conv *t)
{
	if (c < 128 && c > 0)
		one_bytes(c, t);
	else if (c < 2048)
		two_bytes(c, t);
	else if (c < 65536)
		three_bytes(c, t);
}

void	ft_binary(t_conv *t)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	s = "01";
	nb = t->u;
	i = 0;
	if (nb == 0)
		t->nb = ft_strdup("0");
	else
	{
		t->nb = ft_strnew(32);
		while (nb > 0)
		{
			mod = (nb % 2);
			t->nb[i] = s[mod];
			i++;
			nb /= 2;
		}
		t->nb = revert_str(t->nb, i);
	}
}

void	ft_quintal(t_conv *t)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	s = "012345";
	nb = t->u;
	i = 0;
	if (nb == 0)
		t->nb = ft_strdup("0");
	else
	{
		t->nb = ft_strnew(14);
		while (nb > 0)
		{
			mod = (nb % 5);
			t->nb[i] = s[mod];
			i++;
			nb /= 5;
		}
		t->nb = revert_str(t->nb, i);
	}
}
