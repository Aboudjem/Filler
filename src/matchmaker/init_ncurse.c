/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:03:17 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 18:43:05 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	init_colors(void)
{
	start_color();
	init_color(COLOR_GREY, 200, 200, 300);
	init_color(COLOR_ROUGE, 910, 0, 240);
	init_color(COLOR_VERT, 0, 640, 500);
	init_color(COLOR_DARKBLUE, 0, 200, 400);
	init_color(COLOR_CYAN, 0, 1000, 1000);
	init_color(COLOR_JAUNE, 1000, 980, 0);
	init_color(COLOR_MAUVE, 380, 50, 670);
	init_color(COLOR_PINK, 1000, 0, 500);
	init_color(COLOR_GREEN, 0, 1000, 0);
}

void	init_pairs(void)
{
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_GREY, COLOR_GREY);
	init_pair(3, COLOR_ROUGE, COLOR_ROUGE);
	init_pair(4, COLOR_VERT, COLOR_VERT);
	init_pair(5, COLOR_DARKBLUE, COLOR_DARKBLUE);
	init_pair(6, COLOR_CYAN, COLOR_CYAN);
	init_pair(7, COLOR_JAUNE, COLOR_JAUNE);
	init_pair(8, COLOR_MAUVE, COLOR_MAUVE);
	init_pair(9, COLOR_PINK, COLOR_PINK);
	init_pair(10, COLOR_GREEN, COLOR_GREEN);
	init_pair(11, COLOR_WHITE, COLOR_BLACK);
	init_pair(12, COLOR_GREY, COLOR_BLACK);
	init_pair(13, COLOR_ROUGE, COLOR_BLACK);
	init_pair(14, COLOR_VERT, COLOR_BLACK);
	init_pair(15, COLOR_DARKBLUE, COLOR_BLACK);
	init_pair(16, COLOR_CYAN, COLOR_BLACK);
	init_pair(17, COLOR_JAUNE, COLOR_BLACK);
	init_pair(18, COLOR_MAUVE, COLOR_BLACK);
	init_pair(19, COLOR_PINK, COLOR_BLACK);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(21, COLOR_BLACK, COLOR_BLACK);
	init_pair(32, COLOR_BLACK, COLOR_WHITE);
	init_pair(22, COLOR_WHITE, COLOR_WHITE);
}

void	init_curses(void)
{
	initscr();
	cbreak();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	init_colors();
	init_pairs();
}
