/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:31:16 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:31:19 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(t_conv *t, t_flags f)
{
	if (f.neg == 1)
		f.zero = 0;
	t->str = ft_strdup("%");
	noconv_join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
