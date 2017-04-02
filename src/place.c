/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:34:20 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/02 05:51:21 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	start(t_players *players, t_map map, int *first_time)
{
	int y;
	int x;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == players->player)
			{
				players->pos_player_y = y;
				players->pos_player_x = x;
			}
			else if (map.map[y][x] == players->adv)
			{
				players->pos_adv_y = y;
				players->pos_adv_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	*first_time = 1;
}

int		norme_can_place_piece(t_filler f, t_coord coord, t_coord c, int *touch)
{
	if (f.map.map[coord.y + c.y][coord.x + c.x] == f.players.player)
		*touch += 1;
	else if (f.map.map[coord.y + c.y][coord.x + c.x] ==
			f.players.adv)
		return (1);
	return (0);
}

int		can_place_piece(t_filler f, t_coord coord)
{
	t_coord c;
	int		touch;

	touch = 0;
	c.y = 0;
	while (c.y < f.piece.height && (coord.y + f.piece.height <= f.map.height))
	{
		c.x = 0;
		while (c.x < f.piece.width && (coord.x + f.piece.width <= f.map.width))
		{
			if (touch > 1)
				return (0);
			if (f.piece.piece[c.y][c.x] == '*')
			{
				if (norme_can_place_piece(f, coord, c, &touch) == 1)
					return (-1);
			}
			else if (f.piece.piece[c.y][c.x] == '.' && f.map.map[coord.y
					+ c.y][coord.x + c.x] == f.players.adv)
				return (-1);
			c.x++;
		}
		c.y++;
	}
	return (touch == 1 ? 1 : 0);
}

t_lst	*add_placable(t_lst *lst, int x, int y)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->next = lst;
	}
	return (tmp);
}

void	check_advers(t_map *map, t_players *players)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (map->map[y][x] != players->adv && map->map[y][x] != '\0')
	{
		while (map->map[y][x] != players->adv && map->map[y][x] != '\0')
			x++;
		if (map->map[y][x] == players->adv)
			break ;
		else
		{
			x = 0;
			y++;
		}
	}
	players->pos_adv_y = y;
	players->pos_adv_x = x;
}
