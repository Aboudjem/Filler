/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:04:44 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 20:04:45 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "../../includes/filler.h"

int		choose_p2(WINDOW *win, t_env e, char *p1)
{
	int		key;
	int		choice;

	choice = 0;
	while ((key = getch()) != 27)
	{
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < e.nb_players)) ? 1 : 0;
		if (key == ' ' || key == '\n')
		{
			if (choice == e.nb_players)
				endwin();
			else
				choose_map(win, e, p1, strdup(e.players[choice]));
			return (0);
		}
		print_pmenu(win, choice, e.players, "p2");
		wrefresh(win);
	}
	wclear(win);
	endwin();
	return (0);
}

int		norme_choose_p1(WINDOW *win, t_env e, int choice)
{
	if (choice == e.nb_players)
	{
		wclear(win);
		endwin();
		return (1);
	}
	else
	{
		wclear(win);
		choose_p2(win, e, strdup(e.players[choice]));
	}
	return (0);
}

int		choose_p1(WINDOW *win, t_env e)
{
	int		key;
	int		choice;

	choice = 0;
	while ((key = getch()) != ESCAPE)
	{
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < e.nb_players)) ? 1 : 0;
		if (key == ' ' || key == '\n')
			if (norme_choose_p1(win, e, choice) == 1)
				return (0);
		print_pmenu(win, choice, e.players, "p1");
		wrefresh(win);
	}
	wclear(win);
	endwin();
	return (0);
}

void	norme_choose_map(WINDOW *win, t_env e, int choice, t_print players)
{
	char	*command;

	if (choice == e.nb_maps)
	{
		choose_p2(win, e, strdup(e.players[choice]));
		endwin();
	}
	else
	{
		asprintf(&command,
	"./filler_vm -f maps/%s -p1 players/%s -p2 players/%s | ./graph",
strdup(e.maps[choice]), players.p1, players.p2);
		system(command);
		endwin();
	}
}

int		choose_map(WINDOW *win, t_env e, char *p1, char *p2)
{
	int		key;
	int		choice;
	t_print	players;

	choice = 0;
	while ((key = getch()) != 27)
	{
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < e.nb_maps)) ? 1 : 0;
		if (key == ' ' || key == '\n')
		{
			players.p1 = p1;
			players.p2 = p2;
			norme_choose_map(win, e, choice, players);
			return (0);
		}
		print_choosing_map_menu(win, choice, e.maps);
		wrefresh(win);
	}
	wclear(win);
	endwin();
	return (0);
}
