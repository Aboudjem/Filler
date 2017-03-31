#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define ESCAPE 27
#define COLOR_DARKBLUE 92
#define COLOR_GREY 100
#define COLOR_LIGHT_ORANGE_ 104
#define COLOR_ORANGE_ 110
#define COLOR_LIGHT_RED_ 116
#define COLOR_RED_ 122
#define COLOR_L_L_YELLOW_ 128
#define COLOR_L_YELLOW 60
#define COLOR_LIGHT_YELLOW_ 134
#define COLOR_YELLOW_ 140
#define COLOR_FULL_YELLOW_ 146
#define COLOR_PINK 156

#include <dirent.h>
#include <unistd.h>
#include "includes/matchmaker.h"

static void		init_pair_colors(void)
{
	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(8, COLOR_WHITE, COLOR_DARKBLUE);
	init_pair(16, COLOR_BLACK, COLOR_ORANGE_);
	init_pair(32, COLOR_BLACK, COLOR_LIGHT_RED_);
	init_pair(64, COLOR_BLACK, COLOR_RED_);
	init_pair(128, COLOR_BLACK, COLOR_L_L_YELLOW_);
	init_pair(25, COLOR_BLACK, COLOR_L_YELLOW);
	init_pair(51, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(102, COLOR_BLACK, COLOR_YELLOW_);
	init_pair(204, COLOR_BLACK, COLOR_FULL_YELLOW_);
	init_pair(100, COLOR_GREY, COLOR_DARKBLUE);
	init_pair(101, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(102, COLOR_DARKBLUE, COLOR_DARKBLUE);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_DARKBLUE);
	init_pair(4, COLOR_L_YELLOW, COLOR_DARKBLUE);
	init_pair(5, COLOR_PINK, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
}

static void		init_colors(void)
{
	start_color();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_DARKBLUE, 100, 100, 150);
	init_color(COLOR_GREY, 300, 300, 300);
	init_color(COLOR_LIGHT_ORANGE_, 729, 534, 348);
	init_color(COLOR_ORANGE_, 741, 447, 279);
	init_color(COLOR_LIGHT_RED_, 744, 372, 270);
	init_color(COLOR_RED_, 747, 279, 150);
	init_color(COLOR_L_L_YELLOW_, 714, 621, 321);
	init_color(COLOR_L_YELLOW, 723, 624, 225);
	init_color(COLOR_LIGHT_YELLOW_, 711, 606, 3);
	init_color(COLOR_YELLOW_, 711, 699, 0);
	init_color(COLOR_FULL_YELLOW_, 711, 591, 3);
	init_color(COLOR_MAGENTA, 1000, 459, 1000);
	init_color(COLOR_PINK, 1000, 0, 500);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_RED, 1000, 0, 0);
	init_pair_colors();
}

void	initCurses(void)
{
	initscr();
	cbreak();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	init_colors();
}

static void	printLogo(WINDOW *menu, int h, int w)
{
	attron(COLOR_PAIR(2));
	mvwprintw(menu, (h / 3), (w / 2) - (40), "____ _ _    _    ____ ____    _  _ ____ ___ ____ _  _ _  _ ____ _  _ ____ ____ ");
	mvwprintw(menu, (h / 3) + 1, (w / 2) - (40), "|___ | |    |    |___ |__/    |\\/| |__|  |  |    |__| |\\/| |__| |_/  |___ |__/ ");
	mvwprintw(menu, (h / 3) + 2, (w / 2) - (40), "|    | |___ |___ |___ |  \\    |  | |  |  |  |___ |  | |  | |  | | \\_ |___ |  \\ ");
	mvwprintw(menu, h - 2, w - 10, "plisieck");
	attroff(COLOR_PAIR(2));
}

static void	print_menu(WINDOW *menu, int choice)
{
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(2));
	printLogo(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, (h / 2), (w / 2) - (5), "Select Mode:");
	(choice == 0 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + 1), (w / 2) - (2), "1. Play");
	(choice == 0 ? wattroff(menu, COLOR_PAIR(2)) : 0);
	(choice == 1 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + 2), (w / 2) - (2), "2. Configure");
	(choice == 1 ? wattroff(menu, COLOR_PAIR(2)) : 0);
	(choice == 2 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + 3), (w / 2) - (2), "3. Quit");
	(choice == 2 ? wattroff(menu, COLOR_PAIR(2)) : 0);
}

static void	print_choosing_player_menu(WINDOW *menu, int choice, char **available_players, char *player) 
{
	int		h;
	int		w;
	int		i;

	i = 0;
	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(2));
	printLogo(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, (h / 2) - 2, (w / 2) - (23), "Select a player for playing as   :", player);
	if (strcmp(player, "p1") == 0)
	{
		wattron(menu, COLOR_PAIR(5));
		mvwprintw(menu, (h / 2) - 2, (w / 2) + 8, "%s", player);
		wattroff(menu, COLOR_PAIR(5));
	}
	else
	{
		wattron(menu, COLOR_PAIR(6));
		mvwprintw(menu, (h / 2) - 2, (w / 2) + 8, "%s", player);
		wattroff(menu, COLOR_PAIR(6));
	}
	while (available_players[i])
	{
		(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
		mvwprintw(menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, available_players[i]);
		(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
		i++;
	}
	(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + i + 1), (w / 2) - 8, "%d. Back", i);
	(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
}

static void	print_choosing_map_menu(WINDOW *menu, int choice, char **available_maps)
{
	int		h;
	int		w;
	int		i;

	i = 0;
	getmaxyx(stdscr, h, w);
	wattron(menu, COLOR_PAIR(2));
	printLogo(menu, h, w);
	wborder(menu, '|', '|', '_', '_', '\\', '/', '|', '|');
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, (h / 2) - 2, (w / 2) - (10), "Select a map:");
	while (available_maps[i])
	{
		(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
		mvwprintw(menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, available_maps[i]);
		(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
		i++;
	}
	(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + i + 1), (w / 2) - 8, "%d. Back", i);
	(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
}

int	choose_p1(WINDOW *w, t_env e);

int			choose_map(WINDOW *win, t_env e, char *p1, char *p2)
{
	int		key;
	int		choice;
	char	*command;

	choice = 0;
	while ((key = getch()) != 27)
	{
		wclear(win);
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < e.nb_maps)) ? 1 : 0;
		if (key == ' ' || key == '\n')
		{
			if (choice == e.nb_maps)
			{
				wclear(win);
				endwin();
				return (0);
			}
			else
			{
				asprintf(&command, "./filler_vm -f maps/%s -p1 players/%s -p2 players/%s | ./graph", strdup(e.maps[choice]), p1, p2);
				system(command);
				choose_p1(win, e);
				return (0);
			}
		}
		print_choosing_map_menu(win, choice, e.maps);
		wrefresh(win);
	}
	endwin();
	return (0);
}

int			choose_p2(WINDOW *win, t_env e, char *p1)
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
			{
				wclear(win);
				endwin();
				return (0);
			}
			else
			{
				choose_map(win, e, p1, strdup(e.players[choice]));
				wrefresh(win);
				return (0);
			}
		}
		print_choosing_player_menu(win, choice, e.players, "p2");
		wrefresh(win);
	}
	wclear(win);
	endwin();
	return (0);
}

int			choose_p1(WINDOW *win, t_env e)
{
	int		key;
	int		choice;

	choice = 0;
	while ((key = getch()) != ESCAPE)
	{
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < e.nb_players)) ? 1 : 0;
		if (key == ' ' || key == '\n')
		{
			if (choice == e.nb_players)
			{
				wclear(win);
				endwin();
				return (0);
			}
			else
			{
				wclear(win);
				choose_p2(win, e, strdup(e.players[choice]));
			}
		}
		print_choosing_player_menu(win, choice, e.players, "p1");
		wrefresh(win);
	}
	wclear(win);
	endwin();
	return 0;
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
			if (choice == 0)
			{
				wclear(win);
				choose_p1(win, e);
			}
			else if (choice == 1 || choice == 2)
			{
				wclear(win);
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

void	get_available(t_env *e, char *str)
{
	char			**tab;
	DIR				*dir;
	struct dirent	*ent;
	int				i;

	if ((dir = opendir(str)) != NULL)
	{
		tab = (char **)malloc(sizeof(char*) * 20);
		/* On saute . et .. */
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

void	free_env(t_env *e)
{
	int	i;

	i = 0;
	while (e->players[i])
		free(e->players[i++]);
	free(e->players);
	i = 0;
	while (e->maps[i])
		free(e->maps[i++]);
	free(e->maps);
}

WINDOW	*init_window(void)
{
	WINDOW	*win;
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	win = newwin(h, w, 0, 0);
	return (win);
}

int		main(void)
{
	t_env	e;
	WINDOW	*win;

	initCurses();
	get_available(&e, "players/");
	get_available(&e, "maps/");
	win = init_window();
	display_menu(win, e);
	free_env(&e);
	return (0);
}