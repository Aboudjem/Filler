/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matchmaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 20:04:36 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/01 21:24:15 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "../../includes/filler.h"

int		player_menu2(WINDOW *menu, int choice, char **p, char *player)
{
	int i;
	int h;
	int w;

	getmaxyx(stdscr, h, w);
	i = 0;
	while (p[i])
	{
		if (strcmp(player, "p1") == 0)
		{
			(choice == i ? wattron(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
			mvwprintw(menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, p[i]);
			(choice == i ? wattroff(menu, COLOR_PAIR(P1_COLOR_TXT)) : 0);
		}
		else if (strcmp(player, "p2") == 0)
		{
			(choice == i ? wattron(menu, COLOR_PAIR(P2_COLOR_TXT)) : 0);
			mvwprintw(menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, p[i]);
			(choice == i ? wattroff(menu, COLOR_PAIR(P2_COLOR_TXT)) : 0);
		}
		i++;
	}
	return (i);
}

int		display_menu(WINDOW *win, t_env e)
{
	int		key;
	int		choice;

	choice = 0;
	timeout(30);
	while ((key = getch()) != ESCAPE)
	{
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < 2)) ? 1 : 0;
		if (key == ' ' || key == '\n')
		{
			wclear(win);
			if (choice == 0)
				choose_p1(win, e);
			else if (choice == 1 || choice == 2)
			{
				endwin();
				return (0);
			}
		}
		print_menu(win, choice);
		wrefresh(win);
	}
	endwin();
	return (0);
}

void	norme_get_available(t_env *e, int i, char **tab, char *str)
{
	if (!strcmp(str, "players/"))
	{
		e->players = tab;
		e->nb_players = i;
	}
	else if (!strcmp(str, "maps/"))
	{
		e->maps = tab;
		e->nb_maps = i;
	}
}

void	get_available(t_env *e, char *str)
{
	char			**tab;
	DIR				*dir;
	struct dirent	*ent;
	int				i;

	if ((dir = opendir(str)) != NULL)
	{
		tab = (char **)malloc(sizeof(char*) * 20);
		readdir(dir);
		readdir(dir);
		i = 0;
		while ((ent = readdir(dir)) != NULL)
			tab[i++] = strdup(ent->d_name);
		tab[i] = NULL;
		closedir(dir);
	}
	else
	{
		printf("\033[1;31mError:\033[0;0m Could not open directory: %s\n", str);
		exit(0);
	}
	norme_get_available(e, i, tab, str);
}

int		main(void)
{
	t_env	e;
	WINDOW	*win;

	init_curses();
	get_available(&e, "players/");
	get_available(&e, "maps/");
	win = init_window();
	display_menu(win, e);
	free_env(&e);
	return (0);
}
