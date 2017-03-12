/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:26:05 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/09 08:03:25 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size_map(t_map *map)
{
	char *line;
	int i;

	i = 8;
	get_next_line(0, &line);
	if(ft_isdigit(line[i]) == 1)
	{
		map->height = ft_atoi(line+i);
		i += ft_len_int(map->height);
	}
	map->width = ft_atoi(line+i);
}

void	get_map(t_map *map)
{
	char	*line;
	int i;
	i = 0;
	get_size_map(map);
	get_next_line(0, &line);

	while (i < map->height)
	{
		get_next_line(0, &line);
		ft_strcpy(map->map[i], line+4);
		// ft_putendl_fd(map->map[i], 2);
		i++;
	}	
}

void	get_size_piece(t_piece *piece)
{
	char	*line;
	int i;

	i = 6;
	get_next_line(0, &line);
	if(ft_isdigit(line[i]) == 1)
	{
		piece->height = ft_atoi(line+i);
		i += ft_len_int(piece->height);
	}
	piece->width = ft_atoi(line+i);
}

void	get_piece(t_piece *piece)
{
	char	*line;
	int i;
	
	i = 0;
	get_size_piece(piece);
	while (i < piece->height)
	{
		get_next_line(0, &line);
		ft_strcpy(piece->piece[i], line);
		// ft_putendl_fd(piece->piece[i], 2);
		i++;
	}
}

void	debug(t_pos pos, t_map map, t_piece piece)
{
	ft_putendl_fd("==========================", 2);
	ft_putstr_fd("PLAYER:     [", 2);
	ft_putchar_fd(pos.player, 2);
	ft_putendl_fd("]", 2);
	ft_putstr_fd("MAP HEIGHT: [", 2);
	ft_putnbr_fd(map.height, 2);
	ft_putendl_fd("]", 2);
	ft_putstr_fd("MAP WIDTH:  [", 2);
	ft_putnbr_fd(map.width, 2);
	ft_putendl_fd("]", 2);
	ft_putstr_fd("PIECE HEIGHT: [", 2);
	ft_putnbr_fd(piece.height, 2);
	ft_putendl_fd("]", 2);
	ft_putstr_fd("PIECE WIDTH:  [", 2);
	ft_putnbr_fd(piece.width, 2);
	ft_putendl_fd("]", 2);
	ft_putendl_fd("==========================", 2);
}

void	get_player(t_pos *pos)
{
	char 	*line;

	get_next_line(0, &line);
	// dprintf(2, "[[%s]]", line);
	pos->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
	pos->adv = pos->player == 'O' ? 'X' : 'O';
}

int		main (void)
{
	t_map	map;
	t_piece piece;
	t_pos	pos;
	t_lim	lim;
	get_player(&pos);
	// char *line;
	while (1)
	{
		// debug(pos, map, piece);
		get_map(&map);
		get_piece(&piece);
		check_map(&map, piece, &pos,lim);
		break ;
		// is_possible(0,0,piece, map);
		// dprintf(2, "-->[%s]<--", line);
	}
	// // place_piece(map, piece, pos);
	// 	get_map(&map);
	// 	get_piece(&piece);
	// 	int i = 0;
	// 	clean_piece(&piece, &lim);
	// 	i = 0;
	// 	// while (i < piece.height)
	// 		// dprintf(2, "[%s]\n", piece.piece[i++]);
	// 	check_advers(&map, &pos);
	// 	check_player(&map, &pos);
	// 	is_possible(0, 0, piece, map);
	// 	check_map(&map, piece, &pos, lim);
	strerror(2);
	return (0);
}
