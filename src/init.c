/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:08:41 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/30 19:14:15 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_limit	init_limit(int top, int bot, int left, int right)
{
	t_limit	l;

	l.top = top;
	l.bot = bot;
	l.left = left;
	l.right = right;
	return (l);
}

void	init_coord(t_coord *coord)
{
	coord->y = 0;
	coord->x = 0;
}
