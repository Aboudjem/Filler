/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:18:56 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:18:59 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*revert_str(char *str, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_strnew(i + 1);
	while (str[i] == '\0')
		i--;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	ft_strdel(&str);
	return (tmp);
}

void	ft_hexa(t_conv *t)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	s = "0123456789abcdef";
	nb = t->u;
	i = 0;
	if (nb == 0)
		t->nb = ft_strdup("0");
	else
	{
		t->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 16);
			t->nb[i] = s[mod];
			i++;
			nb /= 16;
		}
		t->nb = revert_str(t->nb, i);
	}
}

void	ft_octal(t_conv *t)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "01234567";
	nb = t->u;
	if (t->u == 0)
		t->nb = ft_strdup("0");
	else
	{
		t->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 8);
			t->nb[i] = s[mod];
			i++;
			nb /= 8;
		}
		t->nb = revert_str(t->nb, i);
	}
}

void	ft_hashtag(t_conv *t, t_flags f)
{
	if (f.hash == 1)
	{
		if (t->conv == 'x' || t->conv == 'X')
		{
			if (t->u > 0)
				t->sign = "0x";
			else
				t->sign = "";
		}
		else if (t->conv == 'o' && t->u > 0)
			t->sign = "0";
		else if (t->conv == 'o' && f.hash == 1 && f.pre == 1)
			t->sign = "0";
		t->len_d += (int)ft_strlen(t->sign);
	}
}

void	init_start(t_conv *t)
{
	t->i = 0;
	t->j = 0;
	t->print = ft_strdup("");
}
