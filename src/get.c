/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:14:30 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 21:06:17 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	color_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'O')
			ft_dprintf(2, "%s%c%s", P1_COLOR, 'O', END);
		else if (map[i] == 'X')
			ft_dprintf(2, "%s%c%s", P2_COLOR, 'X', END);
		else
			ft_dprintf(2, "%s%c%s", BG_COLOR, '.', END);
		i++;
	}
	ft_putendl_fd("", 2);
}

void	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	get_size_map(map);
	map->map = (char **)malloc(sizeof(char *) * map->height + 1);
	get_next_line(0, &line);
	free(line);
	while (i < map->height)
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup(line + 4);
		if (SETCOLORS == 1)
			color_map(map->map[i]);
		free(line);
		i++;
	}
	if (SETCOLORS == 1)
		ft_putendl_fd("", 2);
	map->map[i] = NULL;
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
	else
		exit(-1);
	map->width = ft_atoi(line + i);
	free(line);
}

void	get_size_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 6;
	get_next_line(0, &line);
	if (ft_isdigit(line[i]) == 1)
	{
		piece->original_height = ft_atoi(line + i);
		piece->height = ft_atoi(line + i);
		i += ft_len_int(piece->height);
	}
	else
		exit(-1);
	piece->width = ft_atoi(line + i);
	free(line);
}

void	get_piece(t_piece *piece)
{
	int		i;
	char	*line;

	i = 0;
	get_size_piece(piece);
	piece->piece = (char **)(malloc(sizeof(char *) * piece->height + 1));
	while (i < piece->height)
	{
		get_next_line(0, &line);
		piece->piece[i] = ft_strdup(line);
		i++;
		free(line);
	}
	piece->piece[i] = NULL;
}
