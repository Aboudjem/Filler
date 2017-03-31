#include "includes/filler.h"
#include <curses.h>
#include <ncurses.h>

void		size_map(char *map, t_mapw *mapw)
{
	int i;

	i =	ft_strlen(map);

	if (i < 17)
	{
		mapw->o = "OOO";
		mapw->x = "XXX";
		mapw->dot = "   ";
	}
	else if (i < 26)
	{
		mapw->o = "OO";
		mapw->x = "XX";
		mapw->dot = "  ";
	}
	else
	{
		mapw->o = "O";
		mapw->x = "X";
		mapw->dot = " ";
	}
}

void	color_line(char *map, WINDOW *box)
{
	int i;
	t_mapw	mapw;
	size_map(map, &mapw);
	i = 0;
	while (map[i])
	{
		if (map[i] == 'O')
		{
			wattron(box,COLOR_PAIR(1));
			wprintw(box, "%s", mapw.o);
		}
		else if (map[i] == 'X')
		{
			wattron(box,COLOR_PAIR(2));
			wprintw(box,"%s", mapw.x);
		}
		else
		{
			wattron(box,COLOR_PAIR(3));
			wprintw(box,"%s", mapw.dot);
		}
		i++;
	}
}

void	clean_player(char *player)
{
	int i;

	i = 0;
	if (player[i])
		player[i] = player[i] - 32;
	while (player[i] && player[i] != '.')
		i++;
	if (player[i] == '.')
		player[i] = '\0';
}

void	get_player_name(char *line, t_print *print)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1 : [players/"))
			print->p1 = ft_strdup(line + 23);
		else if(ft_strstr(line, "$$$ exec p2 : [players/"))
		{
			print->p2 = ft_strdup(line + 23);
			break;
		}
	}
	clean_player(print->p1);
	clean_player(print->p2);
}

void	get_height(char *line, t_coord *c)
{
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			c->y = (ft_atoi(line + 8)) + 1;
			c->x = (ft_atoi(line + (ft_len_int(c->y)) + 8)) + 1;
			break;
		}
	}
}
static void             init_colors(void)
{
	start_color();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_DARKBLUE, 200, 200, 300);
	init_color(COLOR_GREY, 300, 300, 300);
	init_color(COLOR_LIGHT_ORANGE_, 729, 534, 348);
	init_color(COLOR_ORANGE_, 741, 447, 279);
	init_color(COLOR_RED_, 747, 279, 150);
	init_color(COLOR_L_L_YELLOW_, 714, 621, 321);
	init_color(COLOR_L_YELLOW, 723, 624, 225);
	init_color(COLOR_LIGHT_YELLOW_, 711, 606, 3);
	init_color(COLOR_YELLOW_, 1000, 1000, 0);
	init_color(COLOR_FULL_YELLOW_, 711, 591, 3);
	init_color(COLOR_MAGENTA, 500, 0, 800);
	init_color(COLOR_PINK, 1000, 0, 500);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_RED, 1000, 0, 0);
}

static	void				init_pairs(void)
{
	init_pair(1, COLOR_PINK, COLOR_PINK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_DARKBLUE, COLOR_DARKBLUE);
	init_pair(5, COLOR_PINK, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
}
void    initCurses(void)
{
	initscr();
	cbreak();
	curs_set(0);
	noecho();
	timeout(1);
	keypad( stdscr, TRUE );
	init_colors();
	init_pairs();
}

void	norme_print_map(t_coord c, char *line, WINDOW *box)
{
	int tmp;

	tmp = 1;
	while(tmp < c.y-1)
	{
		get_next_line(0, &line);
		wmove(box, tmp, 1);
		color_line(line +4, box);
		tmp++;
		wrefresh(box);
		refresh();
	}
	tmp = 1;
}

void	print_map(t_print *print, char *line, t_coord c, WINDOW *box)
{
	int 	h;
	int 	w;

	getmaxyx(stdscr, h, w);
	if (c.y < 20)
		box = subwin(stdscr, c.y, c.x*2, (h/2) - c.y, (w/2) - c.x);
	else if (c.x < 50)    
		box = subwin(stdscr, c.y, c.x+1, (h/2) - c.y, (w/2) - c.x);
	else
		box = subwin(stdscr, c.y, c.x+1, 10, 35);
	wattron(box, COLOR_PAIR(4));
	wborder(box, '.', '.', '.', '.', '.', '.', '.', '.');
	while(get_next_line(0, &line) > 0)
	{
		if (*line != ' ' && ft_isdigit(*line))
			norme_print_map(c, line, box);
		else if(ft_strncmp("== O fin", line, 8) == 0)
			print->score_p1 = ft_atoi(line + 9);
		else if(ft_strncmp("== X fin", line, 8) == 0)
			print->score_p2 = ft_atoi(line + 9);
	}
}

void	print_score(t_print print, WINDOW *box)
{
	wattron(box,COLOR_PAIR(5));
	mvwprintw(box, 0, 1, print.p1);
	wattroff(box,COLOR_PAIR(5));
	mvwprintw(box, 1, 10, "V.S");
	wattron(box, COLOR_PAIR(6));
	mvwprintw(box, 2, 13, print.p2);
	wattroff(box, COLOR_PAIR(6));
	wattron(box,COLOR_PAIR(5));
	mvwprintw(box, 1, 4, ft_itoa(print.score_p1));
	wattroff(box,COLOR_PAIR(5));
	wattron(box,COLOR_PAIR(6));
	mvwprintw(box, 3, 16, ft_itoa(print.score_p2));
	wattroff(box,COLOR_PAIR(6));
	wrefresh(box);
}

int main(void) 
{
	t_coord c;
	WINDOW *box;
	WINDOW *title;
	t_print print;
	char *line;
	line = NULL;
	box = NULL;
	title = NULL;
	initCurses();
	refresh();
	title = subwin(stdscr, 25, 40, 5, 5);
	get_player_name(line, &print);

	get_height(line, &c);
	print_map(&print, line , c, box);
	print_score(print, title);
	sleep(5);;
	endwin();

	free(box);

	return 0;
}
