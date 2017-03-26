/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:26:05 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/25 23:16:44 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define color 1 

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


void	color_map(char *map)
{
	int i =0;
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
			ft_putstr_fd("\033[35m", 2);
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
		if (color == 1)
		{
			color_map(map->map[i]);
			ft_putendl_fd("", 2);
		}
		i++;
	}
	if (color == 1)
		ft_putendl_fd("\n", 2);	
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

void	debug(t_players players, t_map map, t_piece piece)
{
	ft_putendl_fd("==========================", 2);
	ft_putstr_fd("PLAYER:     [", 2);
	ft_putchar_fd(players.player, 2);
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

void	get_player(t_players *players)
{
	char 	*line;

	get_next_line(0, &line);
	players->player = ft_strncmp(line, "$$$ exec p1", 11) == 0 ? 'O' : 'X';
	players->adv = players->player == 'O' ? 'X' : 'O';

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
		me->diff_x = me->left - adv.right;
}

t_coord	rightpos(t_lst *lst, t_coord save)
{
	int y = save.y;
	int right = save.x;
	t_lst *first = lst;
	while(lst)
	{
		if (lst->y < y)
			y = lst->y;
		lst = lst->next;
	}
	lst = first;
	while (lst)
	{
		if (lst->y == y)
		{
			if (lst->x > right)
				right = lst->x;
			if (lst->x < left)
				left = lst->x;
		}
		lst = lst->next;
	}
	top.left.x = left;
	top.left.y = y;
	top.right.x = right;
	top.right.y = y;
	return (top);
}

void	big_map(t_place place, t_limit me, t_limit adv, int y, int x,t_map map, t_lst *lst)
{
	get_diff(&me, adv);
//Si on ladv avance sur la droite on decale sur la droite pour monter sinn on monte sur la gauche
			// ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);
	// 		ft_printf("%d %d\n", place.top.left.y - y, place.top.left.x - x);
		
		t_coord save;

			if (me.left != 0)
				{
					if (me.top - 2 == adv.bot)
					{
						save = rightpos(lst, place.top.right);
						ft_putnbr_fd(right, 2);
						ft_putendl_fd("", 2);	
						ft_putnbr_fd(right, 2);	
						ft_putendl_fd("", 2);	
						ft_putnbr_fd(right, 2);	
					}
				ft_printf("%d %d\n", place.left.top.y - y, place.left.top.x - x);
				}
			else
				ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);

	
	// if ((adv.top + 5) < me.top)
	// {
	// 	if (me.diff_x > 5)
	// 	{
	// 		ft_putstr_fd("COUCOU JSS LA\nLALALA\n", 2);
	// 		ft_putnbr_fd(me.diff_x, 2);
	// 		ft_printf("%d %d\n", place.top.left.y - y, place.top.left.x - x);
	// 	}
	// 	else
	// 	{
	// 		ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);
	// 		ft_putstr_fd("111111111\n1111111\n", 2);
	// 		ft_putnbr_fd(me.diff_x, 2);
	// 	}
	// }
	// else
	// {
	// 	ft_putstr_fd("ELSEEEEEEEEEEEE", 2);
	// 	// if (me.bot > adv.bot + 5)
	// 	// 	ft_printf("%d %d\n", place.left.bot.y - y, place.left.bot.x - x);
	// 	// else
	// 		ft_printf("%d %d\n", place.bot.left.y - y, place.bot.left.x - x);

	// }
(void)map;
}

void	resolve_all(t_place place, t_limit me, t_limit adv, t_map map, int y, int x, t_players players)
{
	int div;
	if (map.height >= 100)
		div = map.height / 10;
	else
		div = 1;
	get_diff(&me, adv);
	//dprintf(2, "DIFF_Y=[%d] DIFF_X=[%d]\n", me.diff_y, me.diff_x);

	// Dans le cas ou on est au dessus de l adversaire (on suppose qu'on est a gauche)
	if (players.pos_player_y < players.pos_adv_y)
	{
		if (me.diff_y > div)
			ft_printf("%d %d\n", place.right.bot.y - y, place.right.bot.x - x);
		// Dans le cas inverse
		else
		{
			// Si on a atteint la bordure droite ou la bordure du haut
			if (me.right ==  map.width - 1  || me.top == 0)
			{
				if (me.left != 0)
					ft_printf("%d %d\n", place.left.top.y - y, place.left.top.x - x);
				else
					ft_printf("%d %d\n", place.bot.right.y - y, place.bot.right.x - x);
			}
			else
				ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);
		}
	}
	// Dans le cas ou on est en dessous (on suppose qu'on est a droite)
	else
	{
		big_map(place, me, adv, y, x, map);
		// if (adv.bot + div < me.top)
		// 		ft_printf("%d %d\n", place.top.left.y - y, place.top.left.x - x);
		// else
		// {
		// 	if (me.left == 0)
		// 		ft_printf("%d %d\n", place.top.right.y - y, place.top.right.x - x);
		// 	else	
		// 	ft_printf("%d %d\n", place.left.bot.y - y, place.left.bot.x - x);
		// }
	}
}

int		main (void)
{
	t_map	map;
	t_piece piece;
	t_players	players;
	t_limit	me;
	t_limit	adv;
	t_lst	*lst;
	t_place place;
	int y = 0;
	int x = 0;
	int first_time = 0;

	get_player(&players);
	while (1)
	{
		get_map(&map);
		if (first_time == 0)
			start(&players, map, &first_time);
		//dprintf(2, "{{{{%d}}}}{{{%d}}}}{{{%d}}}{{{%d}}}\n", players.pos_adv_y, players.pos_adv_x, players.pos_player_y, players.pos_player_x);
		get_piece(&piece);
		//debug(players, map, piece);
		clean_piece(&piece, &y, &x); 
		lst = check_map(&map, piece, &players);
		//check_piece(lst, &piece, &map, &players);
		me = get_limits(&map, players.player);
		adv = get_limits(&map, players.adv);
		//print_lst(lst);	
		place = check_piece(lst, &map);
		resolve_all(place, me, adv, map, y, x, players);
		//dprintf(2, "LIMITS : TOP[%d][%d] BOT[%d][%d] LEFT[%d][%d] RIGHT[%d][%d]\n", place.top.y, place.top.x, place.bot.y, place.bot.x, place.left.y, place.left.x, place.right.y, place.right.x);
		//    if (lst)
		//         ft_printf("%d %d\n", lst->y, lst->x);
		//   else
		//     exit(1);
		// print_lst(lst);
	}
	return (0);
}
