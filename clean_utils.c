/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:49:29 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/26 13:49:30 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_line_empty(char *line, char c)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] != c)
			return (0);
		x++;
	}
	return (1);
}

int		is_piece_column_empty(t_piece piece, int column, char c)
{
	int y;

	y = 0;
	while (y < piece.height)
	{
		if (piece.piece[y][column] != c)
			return (0);
		y++;
	}
	return (1);
}

int		is_column_empty(t_map map, int column, char c)
{
	int y;

	y = 0;
	while (y < map.height)
	{
		if (map.map[y][column] != c)
			return (0);
		y++;
	}
	return (1);
}

int		line_contain(char *line, char c)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] == c)
			return (1);
		x++;
	}
	return (0);
}

int		column_contain(t_map map, int column, char c)
{
	int y;

	y = 0;
	while (y < map.height)
	{
		if (map.map[y][column] == c)
			return (1);
		y++;
	}
	return (0);
}