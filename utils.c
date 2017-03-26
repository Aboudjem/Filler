/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:50:36 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/26 13:59:16 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	get_size_map(map);
	get_next_line(0, &line);
	while (i < map->height)
	{
		get_next_line(0, &line);
		ft_strcpy(map->map[i], line + 4);
		if (DISPLAY_COLORS == 1)
		{
			color_map(map->map[i]);
			ft_putendl_fd("", 2);
		}
		i++;
	}
	if (DISPLAY_COLORS == 1)
		ft_putendl_fd("\n", 2);
}

void	get_size_map(t_map *map)
{
	int		i;
	char	*line;

	i = 8;
	get_next_line(0, &line);
	if (ft_isdigit(line[i]) == 1)
	{
		map->height = ft_atoi(line + i);
		i += ft_len_int(map->height);
	}
	map->width = ft_atoi(line + i);
}

void	color_map(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'O')
		{
			ft_putstr_fd("\033[36m", 2);
			ft_putchar_fd('O', 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else if (map[i] == 'X')
		{
			ft_putstr_fd("\033[32m", 2);
			ft_putchar_fd('X', 2);
			ft_putstr_fd("\033[0m", 2);
		}
		else
		{
			ft_putstr_fd("\033[34m", 2);
			ft_putchar_fd(map[i], 2);
			ft_putstr_fd("\033[0m", 2);
		}
		i++;
	}
}

void	get_size_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 6;
	get_next_line(0, &line);
	if (ft_isdigit(line[i]) == 1)
	{
		piece->height = ft_atoi(line + i);
		i += ft_len_int(piece->height);
	}
	piece->width = ft_atoi(line + i);
}

void	get_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 0;
	get_size_piece(piece);
	while (i < piece->height)
	{
		get_next_line(0, &line);
		ft_strcpy(piece->piece[i], line);
		i++;
	}
}

void	get_player(t_players *players)
{
	char	*line;

	get_next_line(0, &line);
	players->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
	players->adv = players->player == 'O' ? 'X' : 'O';
}