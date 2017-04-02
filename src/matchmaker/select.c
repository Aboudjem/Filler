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

int		choose_p2(t_maker *m)
{
	m->choice = 0;
	while ((m->key = getch()) != 27)
	{
		m->choice -= ((m->key == KEY_UP) && (m->choice > 0)) ? 1 : 0;
		m->choice += ((m->key == KEY_DOWN) &&
		(m->choice < m->e.nb_players)) ? 1 : 0;
		if (m->key == ' ' || m->key == '\n')
		{
			if (m->choice == m->e.nb_players)
				endwin();
			else
			{
				m->p2 = strdup(m->e.players[m->choice]);
				choose_map(m);
			}
			return (0);
		}
		print_pmenu(m, "p2");
		wrefresh(m->win);
	}
	wclear(m->win);
	endwin();
	return (0);
}

int		norme_choose_p1(t_maker *m)
{
	if (m->choice == m->e.nb_players)
	{
		wclear(m->win);
		endwin();
		return (1);
	}
	else
	{
		wclear(m->win);
		m->p1 = strdup(m->e.players[m->choice]);
		choose_p2(m);
	}
	return (0);
}

int		choose_p1(t_maker *m)
{
	m->choice = 0;
	while ((m->key = getch()) != ESCAPE)
	{
		m->choice -= ((m->key == KEY_UP) && (m->choice > 0)) ? 1 : 0;
		m->choice += ((m->key == KEY_DOWN)
		&& (m->choice < m->e.nb_players)) ? 1 : 0;
		if (m->key == ' ' || m->key == '\n')
			if (norme_choose_p1(m) == 1)
			{
				m->choice = 0;
				return (0);
			}
		print_pmenu(m, "p1");
		wrefresh(m->win);
	}
	wclear(m->win);
	endwin();
	return (0);
}

void	norme_choose_map(t_maker *m, t_print players)
{
	char	*command;

	if (m->choice == m->e.nb_maps)
	{
		m->p1 = strdup(m->e.players[m->choice]);
		choose_p2(m);
		endwin();
	}
	else
	{
		asprintf(&command,
	"./filler_vm -f maps/%s -p1 players/%s -p2 players/%s | ./graph %d %d",
strdup(m->e.maps[m->choice]), players.p1, players.p2, m->c.p1, m->c.p2);
		system(command);
		endwin();
	}
}

int		choose_map(t_maker *m)
{
	t_print	players;

	m->choice = 0;
	while ((m->key = getch()) != 27)
	{
		m->choice -= ((m->key == KEY_UP) && (m->choice > 0)) ? 1 : 0;
		m->choice += ((m->key == KEY_DOWN) &&
		(m->choice < m->e.nb_maps)) ? 1 : 0;
		if (m->key == ' ' || m->key == '\n')
		{
			players.p1 = m->p1;
			players.p2 = m->p2;
			norme_choose_map(m, players);
			return (0);
		}
		print_choosing_map_menu(m);
		wrefresh(m->win);
	}
	wclear(m->win);
	endwin();
	return (0);
}
