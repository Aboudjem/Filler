/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:26:05 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/26 14:03:33 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_limit	get_limits(t_map *map, char c)
{
	t_coord coord;
	t_limit lim;

	init_coord(&coord);
	lim.top = 0;
	lim.bot = map->height;
	lim.left = 0;
	lim.right = map->width - 1;
	while (coord.y < map->height)
	{
		if (line_contain(map->map[coord.y], c))
			break ;
		else
			lim.top++;
		coord.y++;
	}
	while (coord.x < map->width)
	{
		if (column_contain(*map, coord.x, c))
			break ;
		else
			lim.left++;
		coord.x++;
	}
	while (lim.bot > lim.top)
	{
		if (line_contain(map->map[lim.bot], c))
			break ;
		else
			lim.bot--;
	}
	while (lim.right > lim.left)
	{
		if (column_contain(*map, lim.right, c))
			break ;
		else
			lim.right--;
	}
	return (lim);
}

int		main(void)
{
	t_filler	filler;
	t_piece		piece;
	t_lst		*lst;
	t_coord		c;
	int			first_time;

	first_time = 0;
	init_coord(&c);
	get_player(&filler.players);
	while (42)
	{
		get_map(&filler.map);
		if (first_time == 0)
			start(&filler.players, filler.map, &first_time);
		get_piece(&piece);
		clean_piece(&piece, &c.y, &c.x);
		lst = check_map(&filler.map, piece, &filler.players);
		filler.me = get_limits(&filler.map, filler.players.player);
		filler.adv = get_limits(&filler.map, filler.players.adv);
		filler.place = check_piece(lst, &filler.map);
		resolve_all(filler, c);
	}
	return (0);
}
