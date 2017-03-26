/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:19:17 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/26 14:00:51 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_place	check_piece(t_lst *lst, t_map *map)
{
	t_place	place;

	place.top = get_top(lst, map);
	place.left = get_left(lst, map);
	place.bot = get_bot(lst, map);
	place.right = get_right(lst, map);
	return (place);
}

void	resolve_all(t_filler f, t_coord c)
{
	get_diff(&f.me, f.adv);
	if (f.players.pos_player_y < f.players.pos_adv_y)
		starting_at_top(f, c);
	else
		starting_at_bot(f, c);
}

void	starting_at_top(t_filler f, t_coord c)
{
	int div;

	if (f.map.height >= 100)
		div = f.map.height / 10;
	else
		div = 1;
	if (f.me.diff_y > div)
		ft_printf("%d %d\n", f.place.right.bot.y - c.y, f.place.right.bot.x - c.x);
	else
	{
		if (f.me.right == f.map.width - 1 || f.me.top == 0)
		{
			if (f.me.left != 0)
				ft_printf("%d %d\n", f.place.left.top.y - c.y, f.place.left.top.x - c.x);
			else
				ft_printf("%d %d\n", f.place.bot.right.y - c.y, f.place.bot.right.x - c.x);
		}
		else
			ft_printf("%d %d\n", f.place.top.right.y - c.y, f.place.top.right.x - c.x);
	}
}

void	starting_at_bot(t_filler f, t_coord c)
{
	int	i;

	i = 0;
	get_diff(&f.me, f.adv);
	if (f.me.top + 2 > f.adv.bot)
		ft_printf("%d %d\n", f.place.left.top.y - c.y, f.place.left.top.x - c.x);
	else if (f.me.right != f.map.width - 1)
		ft_printf("%d %d\n", f.place.right.top.y - c.y, f.place.right.top.x - c.x);
	else if (f.me.left != 0)
		ft_printf("%d %d\n", f.place.left.top.y - c.y, f.place.left.top.x - c.x);
	else if (f.me.top != 0)
		ft_printf("%d %d\n", f.place.top.left.y - c.y, f.place.top.left.x - c.x);
	else
	{
		if (i < 10)
			ft_printf("%d %d\n", f.place.right.top.y - c.y, f.place.right.top.x - c.x);
		else
			ft_printf("%d %d\n", f.place.top.left.y - c.y, f.place.top.left.x - c.x);
	}
}
