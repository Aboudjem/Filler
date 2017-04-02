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

int		player_menu2(t_maker *m, char *player)
{
	int i;

	i = 0;
	while (m->e.players[i])
	{
		if (strcmp(player, "p1") == 0)
		{
			(m->choice == i ? wattron(m->win, COLOR_PAIR(m->c.p1 + 10)) : 0);
			mvwprintw(m->win, (m->h / 2 + i),
			(m->w / 2) - (8), "%d. %s", i, m->e.players[i]);
			(m->choice == i ? wattroff(m->win, COLOR_PAIR(m->c.p1 + 10)) : 0);
		}
		else if (strcmp(player, "p2") == 0)
		{
			(m->choice == i ? wattron(m->win, COLOR_PAIR(m->c.p2 + 10)) : 0);
			mvwprintw(m->win, (m->h / 2 + i),
			(m->w / 2) - (8), "%d. %s", i, m->e.players[i]);
			(m->choice == i ? wattroff(m->win, COLOR_PAIR(m->c.p2 + 10)) : 0);
		}
		i++;
	}
	return (i);
}

int		display_menu(t_maker *m)
{
	m->choice = 0;
	timeout(30);
	while ((m->key = getch()) != ESCAPE)
	{
		m->choice -= ((m->key == KEY_UP) && (m->choice > 0)) ? 1 : 0;
		m->choice += ((m->key == KEY_DOWN) && (m->choice < 2)) ? 1 : 0;
		if (m->key == ' ' || m->key == '\n')
		{
			wclear(m->win);
			if (m->choice == 0)
				choose_p1(m);
			else if (m->choice == 1)
				configure(m);
			else if (m->choice == 2)
			{
				endwin();
				return (0);
			}
		}
		print_menu(m);
		wrefresh(m->win);
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
	t_maker	m;

	m.c.p1 = G_GREEN;
	m.c.p2 = G_PINK;
	init_curses();
	get_available(&m.e, "players/");
	get_available(&m.e, "maps/");
	m.win = init_window();
	display_menu(&m);
	free_env(&m.e);
	return (0);
}
