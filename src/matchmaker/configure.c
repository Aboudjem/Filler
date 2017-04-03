/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:13:55 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/02 18:13:58 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void	print_configure5(t_maker *m, int h, int w)
{
	mvwprintw(m->win, (h / 2) + 7, (w / 2) - 11, "PINK");
	mvwprintw(m->win, (h / 2) + 7, (w / 2) + 7, "PINK");
	wattroff(m->win, COLOR_PAIR(T_PINK));
	if (m->choice >= 0 && m->choice <= 8)
		mvwprintw(m->win, (h / 2) - 1 + m->choice, (w / 2) - 14, "->");
	else if (m->choice >= 10 && m->choice <= 18)
		mvwprintw(m->win, (h / 2) - 1 + m->choice - 10, (w / 2) + 4, "->");
	else if (m->choice == 9 || m->choice == 19)
		mvwprintw(m->win, (h / 2) + 10, (w / 2) - 4, "->");
	wrefresh(m->win);
}

void	print_configure4(t_maker *m, int h, int w)
{
	wattron(m->win, COLOR_PAIR(T_ROUGE));
	mvwprintw(m->win, (h / 2) + 1, (w / 2) - 11, "RED");
	mvwprintw(m->win, (h / 2) + 1, (w / 2) + 7, "RED");
	wattroff(m->win, COLOR_PAIR(T_ROUGE));
	wattron(m->win, COLOR_PAIR(T_GREEN));
	mvwprintw(m->win, (h / 2) + 2, (w / 2) - 11, "GREEN");
	mvwprintw(m->win, (h / 2) + 2, (w / 2) + 7, "GREEN");
	wattroff(m->win, COLOR_PAIR(T_GREEN));
	wattron(m->win, COLOR_PAIR(T_DARKBLUE));
	mvwprintw(m->win, (h / 2) + 3, (w / 2) - 11, "BLUE");
	mvwprintw(m->win, (h / 2) + 3, (w / 2) + 7, "BLUE");
	wattroff(m->win, COLOR_PAIR(T_DARKBLUE));
	wattron(m->win, COLOR_PAIR(T_CYAN));
	mvwprintw(m->win, (h / 2) + 4, (w / 2) - 11, "CYAN");
	mvwprintw(m->win, (h / 2) + 4, (w / 2) + 7, "CYAN");
	wattroff(m->win, COLOR_PAIR(T_CYAN));
	wattron(m->win, COLOR_PAIR(T_JAUNE));
	mvwprintw(m->win, (h / 2) + 5, (w / 2) - 11, "YELLOW");
	mvwprintw(m->win, (h / 2) + 5, (w / 2) + 7, "YELLOW");
	wattroff(m->win, COLOR_PAIR(T_JAUNE));
	wattron(m->win, COLOR_PAIR(T_MAUVE));
	mvwprintw(m->win, (h / 2) + 6, (w / 2) - 11, "PURPLE");
	mvwprintw(m->win, (h / 2) + 6, (w / 2) + 7, "PURPLE");
	wattroff(m->win, COLOR_PAIR(T_MAUVE));
	wattron(m->win, COLOR_PAIR(T_PINK));
}

void	print_configure3(t_maker *m, int h, int w)
{
	mvwprintw(m->win, (h / 2) + 4, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 4, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 4, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 5, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 5, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 5, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 6, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 6, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 6, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 7, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 7, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 7, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 8, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 8, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 8, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 10, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 10, (w / 2) - 1, "Back");
	mvwprintw(m->win, (h / 2) + 10, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) - 1, (w / 2) - 11, "WHITE");
	mvwprintw(m->win, (h / 2) - 1, (w / 2) + 7, "WHITE");
	wattroff(m->win, COLOR_PAIR(T_WHITE));
	wattron(m->win, COLOR_PAIR(T_GREY));
	mvwprintw(m->win, (h / 2), (w / 2) - 11, "GREY");
	mvwprintw(m->win, (h / 2), (w / 2) + 7, "GREY");
	wattroff(m->win, COLOR_PAIR(T_GREY));
}

void	print_configure2(t_maker *m, int h, int w)
{
	wattron(m->win, COLOR_PAIR(m->c.p1));
	mvwprintw(m->win, (h / 2) - 4, (w / 2) - 4, "..");
	wattroff(m->win, COLOR_PAIR(m->c.p1));
	wattron(m->win, COLOR_PAIR(m->c.p2));
	mvwprintw(m->win, (h / 2) - 4, (w / 2) + 15, "..");
	wattroff(m->win, COLOR_PAIR(m->c.p2));
	wattron(m->win, COLOR_PAIR(T_WHITE));
	mvwprintw(m->win, (h / 2) - 2, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) - 2, (w / 2), "|");
	mvwprintw(m->win, (h / 2) - 2, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) - 1, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) - 1, (w / 2), "|");
	mvwprintw(m->win, (h / 2) - 1, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2), (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2), (w / 2), "|");
	mvwprintw(m->win, (h / 2), (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 1, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 1, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 1, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 2, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 2, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 2, (w / 2) + 18, "|");
	mvwprintw(m->win, (h / 2) + 3, (w / 2) - 18, "|");
	mvwprintw(m->win, (h / 2) + 3, (w / 2), "|");
	mvwprintw(m->win, (h / 2) + 3, (w / 2) + 18, "|");
}

void	print_configure(t_maker *m)
{
	int		h;
	int		w;

	wclear(m->win);
	getmaxyx(stdscr, h, w);
	wattron(m->win, COLOR_PAIR(P1_COLOR_TXT));
	print_title(m->win, h, w);
	wborder(m->win, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(m->win, COLOR_PAIR(P1_COLOR_TXT));
	mvwprintw(m->win,
	(h / 2) - 5, (w / 2) - 18, "I-----------------------------------I");
	mvwprintw(m->win,
	(h / 2) - 4, (w / 2) - 18, "|   P1 COLOR      |    P2 COLOR     |");
	mvwprintw(m->win,
	(h / 2) - 3, (w / 2) - 18, "I-----------------------------------I");
	mvwprintw(m->win,
	(h / 2) + 9, (w / 2) - 18, "I-----------------------------------I");
	mvwprintw(m->win,
	(h / 2) + 11, (w / 2) - 18, "I-----------------------------------I");
	print_configure2(m, h, w);
	print_configure3(m, h, w);
	print_configure4(m, h, w);
	print_configure5(m, h, w);
}
