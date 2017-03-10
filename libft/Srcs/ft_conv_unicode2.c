/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unicode2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:49:33 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 12:49:35 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	one_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(1);
	t->str[0] = c;
}

void	two_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(2);
	t->str[0] = (192 | (c >> 6));
	t->str[1] = (128 | (c & 63));
}

void	three_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(3);
	t->str[0] = (224 | (c >> 12));
	t->str[1] = (128 | ((c >> 6) & 63));
	t->str[2] = (128 | (c & 63));
}

void	four_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(4);
	t->str[0] = (240 | (c >> 18));
	t->str[1] = (128 | ((c >> 12) & 63));
	t->str[2] = (128 | ((c >> 6) & 63));
	t->str[3] = (128 | (c & 63));
}

void	how_long2(unsigned long int c, t_conv *t)
{
	if (c < 128 && c > 0)
		one_bytes(c, t);
	else if (c < 2048)
		two_bytes(c, t);
	else if (c < 65536)
		three_bytes(c, t);
	else if (c < 1114112)
		four_bytes(c, t);
}
