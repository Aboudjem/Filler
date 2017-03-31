/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:14:30 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/31 21:23:14 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_players *players)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
	if (ft_strncmp("# -----", line, 6) == 0)
	{
		while (ft_strncmp("launched players/ab", line, 19) != 0)
		{
			get_next_line(0, &line);
			free(line);
		}
		get_next_line(0, &line);
		if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
		{
			free(line);
			get_next_line(0, &line);
			free(line);
			get_next_line(0, &line);
			free(line);
		}
	}
	players->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
	players->adv = players->player == 'O' ? 'X' : 'O';
}

void	norme_get_limits(t_limit *lim, t_coord *coord, t_map *map, char c)
{
	while (coord->x < map->width)
	{
		if (column_contain(*map, coord->x, c))
			break ;
		else
			lim->left++;
		coord->x++;
	}
	while (lim->bot > lim->top)
	{
		if (line_contain(map->map[lim->bot], c))
			break ;
		else
			lim->bot--;
	}
	while (lim->right > lim->left)
	{
		if (column_contain(*map, lim->right, c))
			break ;
		else
			lim->right--;
	}
}

t_limit	get_limits(t_map *map, char c)
{
	t_coord coord;
	t_limit lim;

	init_coord(&coord);
	lim.top = 0;
	lim.bot = map->height - 1;
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
	norme_get_limits(&lim, &coord, map, c);
	return (lim);
}
