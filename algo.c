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

void	check_piece()
{
	// si la piece est + large
	if (piece->width > piece->height)
	{ 
		if (pos->player == 'O')
			get_right_x();
		else
			get_left_x();
		//on place la piece large a la position la plus "extreme" 
		// c a d la plus a gauche ou a droite selon si jss p1 ou p2
	}
	// si la piece est + haute
	else if (piece->height > piece->width)
	{ 
		if (pos->player == 'O')
			get_bot_y();
		else
			get_top_y();
		//on place la piece haute a la position la plus "extreme"
	}
}


	// pos adv(top, bot, left, right)
	// pos me(top, bot, left, right)
	// largeur piece
	// longueur piece
	
	// 6 2
	// 6 3
	// 7 2
	// 7 3

	
	


	if(position adversaire la plus haut > ma position la plus haut)
		algo 1;
	else if (
