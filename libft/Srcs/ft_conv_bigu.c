/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:33:34 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:33:44 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nb_sign_u(t_conv *t, t_flags f)
{
	t->nb = ft_litoa(t->u);
	if (t->u > 0 && f.plus == 1)
		t->sign = "";
	else if (f.space == 1)
		t->sign = "";
	t->len_d = ft_strlen(t->nb) + ft_strlen(t->sign);
}

void	conv_u(t_conv *t, t_flags f)
{
	init(t);
	nb_sign_u(t, f);
	if (f.pre == 0)
		fill_nodot(t, f);
	else
	{
		fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
