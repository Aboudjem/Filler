/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:29:41 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/08 23:06:20 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_wc(unsigned int c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 1114112)
		return (4);
	return (0);
}

void	conv_wc(unsigned long int c, t_conv *t)
{
	how_long(c, t);
	if (c == 0)
		t->len_return = 1;
	else
		t->len_return = len_wc(c);
}

void	conv_ws(t_conv *t, t_flags f)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	t->len_return = 0;
	if (!t->w || ft_wstrcmp(t->w, L"(null)") == 0)
	{
		t->len_return = 6;
		t->str = ft_strdup("(null)");
	}
	else
	{
		while (t->w[i] != '\0')
		{
			conv_wc(t->w[i], t);
			if (t->ret != -1)
				tmp = ft_strjoin_free(&tmp, &t->str, 0);
			i++;
		}
		t->str = ft_strdup(tmp);
		s_join(t, f);
		t->len_return = (int)ft_strlen(t->str);
	}
}

int		s_pre(t_conv *t, t_flags f)
{
	int i;

	i = 0;
	while (i + len_wc(t->w[i]) <= f.dot)
		i += len_wc(t->w[i]);
	return (i);
}

void	how_long(unsigned long int c, t_conv *t)
{
	if (c == 0)
	{
		write(1, t->print, ft_strlen(t->print) + 1);
		t->print = ft_strnew(1);
	}
	else if (MB_CUR_MAX == 1 && c <= 127)
		one_bytes(c, t);
	else if (MB_CUR_MAX == 2 && c < 2048)
	{
		if (c < 128 && c > 0)
			one_bytes(c, t);
		else if (c < 2048)
			two_bytes(c, t);
	}
	else if (MB_CUR_MAX == 3 && c < 65536)
		how_long3(c, t);
	else if (MB_CUR_MAX == 4 && c < 1114112)
		how_long2(c, t);
	else
		t->ret = -1;
}
