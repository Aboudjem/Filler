/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:19:17 by plisieck          #+#    #+#             */
/*   Updated: 2017/03/20 22:38:11 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// void	get_pos()
// {
// 	fonction check_position adv 
// 	if (pos me > pos adv)
// }

t_place check_piece(t_lst *lst, t_map *map)
{
    t_place place;
	// t_topbot top;
	// t_topbot bot;
	// t_leftright left;
	// t_leftright right;
	
	place.top = get_top(lst, map);
	place.left = get_left(lst, map);
    place.bot = get_bot(lst, map);
	place.right = get_right(lst, map);
    //dprintf(2, "%d %d\n", place.right.y, place.right.x);
   // ft_printf("%d %d\n", place.top.right.y, place.top.right.x);
	//if (posmex > posadvx && posmey > posadvy)
	//	place right
    return (place);
}
