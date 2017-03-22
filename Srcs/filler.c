/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:26:05 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/22 04:55:19 by plisieck         ###   ########.fr       */
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

/*
void	if_top(t_place place, t_limit lim0, t_limit limX)
{
		if (limO.right >
}*/
//void	ft_solve_bot(t_place place, t_limit me, t_limit adv, t_map map)
//{
	//si au dessus de ladv et a gauche
//	if (me.right > adv.right)
	//	ft_printf("%d %d\n", place.right.top.y)
//}

void	get_diff(t_limit *me, t_limit adv)
{
	// Si on est au dessus de l'adverssaire
	if (me->bot < adv.top)
		me->diff_y = adv.top - me->bot;
	else
		me->diff_y = me->top - adv.bot;


	// Si on est a gauche de l'adverssaire
	if (me->right < adv.left)
		me->diff_x = adv.left - me->right;
	else
		me->diff_x = adv.right - me->left;
}

void	resolve_all(t_place place, t_limit me, t_limit adv, t_map map, int y, int x)
{
	get_diff(&me, adv);
	//dprintf(2, "DIFF_Y=[%d] DIFF_X=[%d]\n", me.diff_y, me.diff_x);
	// Dans le cas ou on est au dessus de l adversaire
	if (me.diff_y > 1)
		ft_printf("%d %d\n", place.right.bot.y - y, place.right.bot.x - x);
	// Dans le cas inverse
	else
	{
		// Si on a atteint la bordure droite ou la bordure du haut
		if (me.right > 15 || me.top == 0)
		{
			if (me.left != 0)
				ft_printf("%d %d\n", place.left.top.y - y, place.left.top.x - x);
			else
				ft_printf("%d %d\n", place.bot.right.y - y, place.bot.right.x - x);
		}
		else
			ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);
	}
	
	(void)place;
	(void)me;
	(void)adv;
	(void)map;
	(void)y;
	(void)x;
}

int		main (void)
{
    t_map	map;
    t_piece piece;
    t_pos	pos;
    t_limit	me;
    t_limit	adv;
    t_lst	*lst;
    t_place place;
	int y = 0;
	int x = 0;

    get_player(&pos);
    while (1)
    {
        get_map(&map);
        get_piece(&piece);
        //debug(pos, map, piece);
        clean_piece(&piece, &y, &x); 
		lst = check_map(&map, piece, &pos);
        //check_piece(lst, &piece, &map, &pos);
        me = get_limits(&map, pos.player);
        adv = get_limits(&map, pos.adv);
		//print_lst(lst);	
		place = check_piece(lst, &map);
		resolve_all(place, me, adv, map, y, x);
        //dprintf(2, "LIMITS : TOP[%d][%d] BOT[%d][%d] LEFT[%d][%d] RIGHT[%d][%d]\n", place.top.y, place.top.x, place.bot.y, place.bot.x, place.left.y, place.left.x, place.right.y, place.right.x);
 //    if (lst)
   //         ft_printf("%d %d\n", lst->y, lst->x);
     //   else
       //     exit(1);
       // print_lst(lst);
    }
    return (0);
}
