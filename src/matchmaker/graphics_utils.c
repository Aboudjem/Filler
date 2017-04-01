/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:04:25 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 20:04:26 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"
#include <curses.h>
#include <ncurses.h>

void	clean_player(char *player)
{
	int i;

	i = 0;
	if (player[i])
		player[i] = player[i] - 32;
	while (player[i] && player[i] != '.')
		i++;
	if (player[i] == '.')
		player[i] = '\0';
}

void	get_player_name(char *line, t_print *print)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1 : [players/"))
			print->p1 = ft_strdup(line + 23);
		else if (ft_strstr(line, "$$$ exec p2 : [players/"))
		{
			print->p2 = ft_strdup(line + 23);
			break ;
		}
	}
	clean_player(print->p1);
	clean_player(print->p2);
}

void	get_height(char *line, t_coord *c)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			c->y = (ft_atoi(line + 8)) + 1;
			c->x = (ft_atoi(line + (ft_len_int(c->y)) + 8)) + 1;
			break ;
		}
	}
}

void	size_map(char *map, t_mapw *mapw)
{
	int i;

	i = ft_strlen(map);
	if (i < 17)
	{
		mapw->o = "OOO";
		mapw->x = "XXX";
		mapw->dot = "   ";
	}
	else if (i < 26)
	{
		mapw->o = "OO";
		mapw->x = "XX";
		mapw->dot = "  ";
	}
	else
	{
		mapw->o = "O";
		mapw->x = "X";
		mapw->dot = " ";
	}
}