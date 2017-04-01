/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:04:40 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 21:16:26 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "../../includes/filler.h"

void	print_title(WINDOW *menu, int h, int w)
{
	attron(COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(menu, (h / 3), (w / 2) - 40, "____ _ _    _    ____ ____    _ ");
	mvwprintw(menu, (h / 3), (w / 2) - 8, " _ ____ ___ ____ _  _ _  _ ____ _");
	mvwprintw(menu, (h / 3), (w / 2) + 25, "  _ ____ ____ ");
	mvwprintw(menu, (h / 3) + 1, (w / 2) - 40, "|___ | |    |    |___ |__/  ");
	mvwprintw(menu, (h / 3) + 1, (w / 2) - 12, "  |\\/| |__|  |  |    |__| |");
	mvwprintw(menu, (h / 3) + 1, (w / 2) + 15, "\\/| |__| |_/  |___ |__/ ");
	mvwprintw(menu, (h / 3) + 2, (w / 2) - 40, "|    | |___ |___ |___ |  \\ ");
	mvwprintw(menu, (h / 3) + 2, (w / 2) - 13, "   |  | |  |  |  |___ |  | |");
	mvwprintw(menu, (h / 3) + 2, (w / 2) + 15, "  | |  | | \\_ |___ |  \\ ");
	mvwprintw(menu, h - 2, w - 10, "plisieck");
	attroff(COLOR_PAIR(P1_COLOR_TXT));
}

void	print_menu(WINDOW *menu, int choice)
{
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(P1_COLOR_TXT));
	print_title(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(menu, (h / 2), (w / 2) - (5), "Select Mode:");
	(choice == 0 ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(menu, (h / 2 + 1), (w / 2) - (2), "1. Play");
	(choice == 0 ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	(choice == 1 ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(menu, (h / 2 + 2), (w / 2) - (2), "2. Configure");
	(choice == 1 ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	(choice == 2 ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(menu, (h / 2 + 3), (w / 2) - (2), "3. Quit");
	(choice == 2 ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
}

void	print_p1_or_p2(WINDOW *menu, char *player, int h, int w)
{
	if (strcmp(player, "p1") == 0)
	{
		wattron(menu, COLOR_PAIR(P1_COLOR_TXT));
		mvwprintw(menu, (h / 2) - 2, (w / 2) + 8, "%s", player);
		wattroff(menu, COLOR_PAIR(P1_COLOR_TXT));
	}
	else
	{
		wattron(menu, COLOR_PAIR(P2_COLOR_TXT));
		mvwprintw(menu, (h / 2) - 2, (w / 2) + 8, "%s", player);
		wattroff(menu, COLOR_PAIR(P2_COLOR_TXT));
	}
}

void	print_pmenu(WINDOW *menu, int choice, char **p, char *player)
{
	int		h;
	int		w;
	int		i;

	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(P1_COLOR_TXT));
	print_title(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(menu, (h / 2) - 2, (w / 2) - (23),
	"Select a player for playing as   :", player);
	print_p1_or_p2(menu, player, h, w);
	i = player_menu2(menu, choice, p, player);
	(choice == i ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(menu, (h / 2 + i + 1), (w / 2) - 8, "%d. Back", i);
	(choice == i ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	wrefresh(menu);
}

void	print_choosing_map_menu(WINDOW *menu, int choice, char **m)
{
	int		h;
	int		w;
	int		i;

	i = 0;
	wclear(menu);
	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(P1_COLOR_TXT));
	print_title(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(menu, (h / 2) - 2, (w / 2) - (10), "Select a map:");
	while (m[i])
	{
		(choice == i ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
		mvwprintw(menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, m[i]);
		(choice == i ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
		i++;
	}
	(choice == i ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(menu, (h / 2 + i + 1), (w / 2) - 8, "%d. Back", i);
	(choice == i ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	wrefresh(menu);
}
