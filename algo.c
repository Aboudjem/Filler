/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:19:17 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/15 02:48:10 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	get_pos()
// {
// 	fonction check_position adv 
// 	if (pos me > pos adv)
// }

void	check_piece(t_lst *lst, t_piece *piece, t_map *map, t_pos *pos)
{
	t_coord top;
	t_coord bot;
	t_coord left;
	t_coord right;
	
	top = get_top_y(lst, map);
	left = get_left_x(lst, map);
	bot = get_bot_y(lst, map);
	right = get_right_x(lst, map);
	dprintf(2, "TOP=[%d][%d]; BOT=[%d][%d]; LEFT=[%d][%d]; RIGHT=[%d][%d]\n", top.y, top.x, bot.y, bot.x, left.y, left.x, right.y, right.x);
}
