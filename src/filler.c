/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:01:48 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/30 19:07:11 by aboudjem         ###   ########.fr       */
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

t_lst	*check_map(t_filler f)
{
	t_coord coord;
	t_lst	*lst;

	coord.y = 0;
	lst = NULL;
	while (coord.y < f.map.height)
	{
		coord.x = 0;
		while (coord.x < f.map.width)
		{
			if (can_place_piece(f, coord) == 1)
				lst = add_placable(lst, coord.x, coord.y);
			coord.x++;
		}
		coord.y++;
	}
	return (lst);
}

void	free_some_things(t_filler *f, t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	while (i <= f->piece.original_height)
	{
		free(f->piece.piece[i]);
		i++;
	}
	free(f->piece.piece);
	i = 0;
	while (i <= f->map.height)
	{
		free(f->map.map[i]);
		i++;
	}
	free(f->map.map);
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int		main(void)
{
	t_filler	filler;
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
		get_piece(&filler.piece);
		clean_piece(&filler.piece, &c.y, &c.x);
		lst = check_map(filler);
		filler.me = get_limits(&filler.map, filler.players.player);
		filler.adv = get_limits(&filler.map, filler.players.adv);
		filler.p = check_piece(lst, &filler.map);
		resolve_all(filler, c);
		free_some_things(&filler, lst);
	}
	return (0);
}
