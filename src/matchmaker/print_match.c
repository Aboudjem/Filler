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

void	print_menu(t_maker *m)
{
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	wattron(m->win, COLOR_PAIR(P1_COLOR_TXT));
	print_title(m->win, h, w);
	wborder(m->win, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(m->win, (h / 2), (w / 2) - (5), "Select Mode:");
	(m->choice == 0 ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(m->win, (h / 2 + 1), (w / 2) - (2), "1. Play");
	(m->choice == 0 ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	(m->choice == 1 ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(m->win, (h / 2 + 2), (w / 2) - (2), "2. Configure");
	(m->choice == 1 ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	(m->choice == 2 ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(m->win, (h / 2 + 3), (w / 2) - (2), "3. Quit");
	(m->choice == 2 ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
}

void	print_p1_or_p2(t_maker *m, char *player)
{
	if (strcmp(player, "p1") == 0)
	{
		wattron(m->win, COLOR_PAIR(m->c.p1 + 10));
		mvwprintw(m->win, (m->h / 2) - 2, (m->w / 2) + 8, "%s", player);
		wattroff(m->win, COLOR_PAIR(m->c.p1 + 10));
	}
	else
	{
		wattron(m->win, COLOR_PAIR(m->c.p2 + 10));
		mvwprintw(m->win, (m->h / 2) - 2, (m->w / 2) + 8, "%s", player);
		wattroff(m->win, COLOR_PAIR(m->c.p2 + 10));
	}
}

void	print_pmenu(t_maker *m, char *player)
{
	int	i;

	i = 0;
	getmaxyx(stdscr, m->h, m->w);
	wattron(m->win, COLOR_PAIR(P1_COLOR_TXT));
	print_title(m->win, m->h, m->w);
	wborder(m->win, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(m->win, (m->h / 2) - 2, (m->w / 2) - (23),
	"Select a player for playing as   :", player);
	print_p1_or_p2(m, player);
	i = player_menu2(m, player);
	(m->choice == i ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(m->win, (m->h / 2 + i + 1), (m->w / 2) - 8, "%d. Back", i);
	(m->choice == i ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	wrefresh(m->win);
}

void	print_choosing_map_menu(t_maker *m)
{
	int		i;

	i = 0;
	wclear(m->win);
	getmaxyx(stdscr, m->h, m->w);
	wattron(m->win, COLOR_PAIR(P1_COLOR_TXT));
	print_title(m->win, m->h, m->w);
	wborder(m->win, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(m->win, (m->h / 2) - 2, (m->w / 2) - (10), "Select a map:");
	while (m->e.maps[i])
	{
		(m->choice == i ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
		mvwprintw(m->win, (m->h / 2 + i),
		(m->w / 2) - (8), "%d. %s", i, m->e.maps[i]);
		(m->choice == i ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
		i++;
	}
	(m->choice == i ? wattron(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	mvwprintw(m->win, (m->h / 2 + i + 1), (m->w / 2) - 8, "%d. Back", i);
	(m->choice == i ? wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT)) : 0);
	wrefresh(m->win);
}
