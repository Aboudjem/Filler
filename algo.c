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

t_place check_piece(t_lst *lst, t_piece *piece, t_map *map, t_pos *pos)
{
    t_place place;
	
	place.top = get_top_y(lst, map);
	place.left = get_left_x(lst, map);
    place.bot = get_bot_y(lst, map);
	place.right = get_right_x(lst, map);
    dprintf(2, "%d %d\n", place.right.y, place.right.x);
    ft_printf("%d %d\n", place.left.y, place.left.x);
    return (place);
}
