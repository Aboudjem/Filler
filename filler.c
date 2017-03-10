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

t_map	get_map(void)
{
	t_map	map;
	char	*line;
	int i;

	get_next_line(0, &line);
	i = 8;
	if(ft_isdigit(line[i]) == 1)
	{
		map.height = ft_atoi(line+i);
		i += ft_len_int(map.height);
	}
	map.width = ft_atoi(line+i);
	i =0;
	get_next_line(0, &line);

	while (i < map.height)
	{
		get_next_line(0, &line);
		ft_strcpy(map.map[i], line+4);
	//	ft_putendl_fd(map.map[i], 2);
		i++;
	}	
	return (map);
}

t_piece	get_piece(void)
{
	t_piece	piece;
	char	*line;
	int i;

	i = 6;
	get_next_line(0, &line);
	if(ft_isdigit(line[i]) == 1)
	{
		piece.height = ft_atoi(line+i);
		i += ft_len_int(piece.height);
	}
	piece.width = ft_atoi(line+i);

	i =0;
	while (i < piece.height)
	{
		get_next_line(0, &line);
		ft_strcpy(piece.piece[i], line);
		ft_putendl_fd(piece.piece[i], 2);
		i++;
	}
	return (piece);
}

void	debug(char player, t_map map, t_piece piece)
{
	ft_putendl_fd("==========================", 2);
	ft_putstr_fd("PLAYER:     [", 2);
	ft_putchar_fd(player, 2);
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

char get_player(void)
{
	char player;
	char 	*line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
			player = 'O';
	else if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
			player = 'X';
	else
	{
			ft_putendl("Parsing Error : Can't get the player ID.");
			exit(0);
	}
	return (player);
}

int		main (void)
{
		/*
	char	*line;

		ft_putendl_fd("==============================================", 2);
	while (get_next_line(0, &line))
		ft_putendl_fd(line, 2);
		*/

	char	player;
	t_map	map;
	t_piece piece;

	player = get_player();
	map = get_map();
	piece = get_piece();
	int i =0;
	printf("++++++++++++++++++++++++++++++\n");
	while ( i < piece.height)
	{
		printf("[%s]\n", piece.piece[i]);
		i++;
	}
	//debug(player, map, piece);
	clean_piece(&piece);
	i = 0;
	while (i < piece.height)
			ft_putendl(piece.piece[i++]);
	return (0);
}
