/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:05:36 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/02 01:42:42 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"
#include <curses.h>
#include <ncurses.h>

void	color_line(char *map, WINDOW *box, t_coord c)
{
	int		i;
	t_mapw	mapw;

	size_map(map, &mapw);
	i = 0;
	while (map[i])
	{
		if (map[i] == 'O')
		{
			wattron(box, COLOR_PAIR(c.p1));
			wprintw(box, "%s", mapw.o);
		}
		else if (map[i] == 'X')
		{
			wattron(box, COLOR_PAIR(c.p2));
			wprintw(box, "%s", mapw.x);
		}
		else
		{
			wattron(box, COLOR_PAIR(21));
			wprintw(box, "%s", mapw.dot);
		}
		i++;
	}
}

void	norme_print_map(t_coord c, char *line, WINDOW *box)
{
	int tmp;

	tmp = 1;
	while (tmp < c.y - 1)
	{
		get_next_line(0, &line);
		wmove(box, tmp, 1);
		color_line(line + 4, box, c);
		tmp++;
		wrefresh(box);
		refresh();
	}
	tmp = 1;
}

void	print_map(t_print *print, char *line, t_coord c, WINDOW *box)
{
	int h;
	int w;

	getmaxyx(stdscr, h, w);
	if (c.y < 20)
		box = subwin(stdscr, c.y, c.x * 2, (h / 2) - c.y, (w / 2) - c.x);
	else if (c.x < 50)
		box = subwin(stdscr, c.y, c.x + 1, (h / 2) - c.y, (w / 2) - c.x);
	else
		box = subwin(stdscr, c.y, c.x + 1, 10, 35);
	wattron(box, COLOR_PAIR(2));
	wborder(box, '.', '.', '.', '.', '.', '.', '.', '.');
	while (get_next_line(0, &line) > 0)
	{
		if (*line != ' ' && ft_isdigit(*line))
			norme_print_map(c, line, box);
		else if (ft_strncmp("== O fin", line, 8) == 0)
			print->score_p1 = ft_atoi(line + 9);
		else if (ft_strncmp("== X fin", line, 8) == 0)
			print->score_p2 = ft_atoi(line + 9);
	}
}

void	print_score(t_print print, WINDOW *box, t_coord c)
{
	wattron(box, COLOR_PAIR(c.p1 + 10));
	mvwprintw(box, 0, 1, print.p1);
	wattroff(box, COLOR_PAIR(c.p1 + 10));
	mvwprintw(box, 1, 10, "V.S");
	wattron(box, COLOR_PAIR(c.p2 + 10));
	mvwprintw(box, 2, 15, print.p2);
	wattroff(box, COLOR_PAIR(c.p2 + 10));
	wattron(box, COLOR_PAIR(c.p1 + 10));
	mvwprintw(box, 1, 1, ft_itoa(print.score_p1));
	wattroff(box, COLOR_PAIR(c.p1 + 10));
	wattron(box, COLOR_PAIR(c.p2 + 10));
	mvwprintw(box, 3, 15, ft_itoa(print.score_p2));
	wattroff(box, COLOR_PAIR(c.p2 + 10));
	wrefresh(box);
}

int		main(int argc, char *argv[])
{
	WINDOW		*box;
	WINDOW		*title;
	t_print		print;
	char		*line;
	t_coord		c;

	if (argc == 3)
	{
		c.p1 = ft_colors(argv[1]);
		c.p2 = ft_colors(argv[2]);
		box = NULL;
		line = NULL;
		title = NULL;
		init_curses();
		title = subwin(stdscr, 25, 40, 5, 5);
		get_player_name(line, &print);
		get_height(line, &c);
		print_map(&print, line, c, box);
		print_score(print, title, c);
		sleep(5);
		endwin();
		free(box);
	}
	return (0);
}
