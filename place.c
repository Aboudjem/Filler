/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:53:55 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/26 14:03:27 by plisieck         ###   ########.fr       */
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

int		can_place_piece(t_map *map, t_piece piece, t_coord coord, t_players *p)
{
	int py;
	int	px;
	int	touch;

	touch = 0;
	py = 0;
	while (py < piece.height && (coord.y + piece.height <= map->height))
	{
		px = 0;
		while (px < piece.width && (coord.x + piece.width <= map->width))
		{
			if (piece.piece[py][px] == '*')
			{
				if (map->map[coord.y + py][coord.x + px] == p->player)
					touch++;
				else if (map->map[coord.y + py][coord.x + px] == p->adv)
					return (0);
				px++;
			}
			else if (piece.piece[py][px] == '.')
			{
				if (map->map[coord.y + py][coord.x + px] == p->adv)
					return (0);
				px++;
			}
		}
		py++;
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

t_lst	*check_map(t_map *map, t_piece piece, t_players *players)
{
	t_coord coord;
	t_lst	*lst;

	coord.y = 0;
	lst = NULL;
	while (coord.y < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width)
		{
			if (can_place_piece(map, piece, coord, players) == 1)
				lst = add_placable(lst, coord.x, coord.y);
			coord.x++;
		}
		coord.y++;
	}
	return (lst);
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
