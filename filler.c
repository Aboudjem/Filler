/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:26:05 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/15 02:04:14 by plisieck         ###   ########.fr       */
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
    pos->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
    pos->adv = pos->player == 'O' ? 'X' : 'O';
}

t_limit	get_limits(t_map *map, char c)
{
    t_limit lim;
    int x = 0;
    int y = 0;
    lim.top = 0;
    lim.bot = map->height;
    lim.left = 0;
    lim.right = map->width - 1;
    // Getting Top Limit
    while (y < map->height)
    {
        if (line_contain(map->map[y], c))
            break ;
        else
            lim.top++;
        y++;
    }
    // Getting Left Limit
    while (x < map->width)
    {
        if (column_contain(*map, x, c))
            break ;
        else
            lim.left++;
        x++;
    }
    // Getting Bottom Limit
    while (lim.bot > lim.top)
    {
        if (line_contain(map->map[lim.bot], c))
            break ;
        else
            lim.bot--;
    }
    // Getting Right Limit
    while (lim.right > lim.left)
    {
        if (column_contain(*map, lim.right, c))
            break ;
        else
            lim.right--;
    }
    return (lim);
}

int		main (void)
{
    t_map	map;
    t_piece piece;
    t_pos	pos;
    t_limit	lim;
    t_lst	*lst;
    t_place place;

    get_player(&pos);
    while (1)
    {
        get_map(&map);
        get_piece(&piece);
        //debug(pos, map, piece);
        lst = check_map(&map, piece, &pos);
        //check_piece(lst, &piece, &map, &pos);
        lim = get_limits(&map, 'X');
        ft_putendl_fd("COUCOU", 2);
        place = check_piece(lst, &piece, &map, &pos);
        dprintf(2, "LIMITS : TOP[%d][%d] BOT[%d][%d] LEFT[%d][%d] RIGHT[%d][%d]\n", place.top.y, place.top.x, place.bot.y, place.bot.x, place.left.y, place.left.x, place.right.y, place.right.x);
 //    if (lst)
   //         ft_printf("%d %d\n", lst->y, lst->x);
     //   else
       //     exit(1);
        print_lst(lst);
    }
    return (0);
}
