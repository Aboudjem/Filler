#include "includes/filler.h"
#include <curses.h>
#include <ncurses.h>


void	color_line(char *map, WINDOW *box)
{
	int i;
	i = 0;

	while (map[i])
	{
		if (map[i] == 'O')
		{
			wattron(box,COLOR_PAIR(1));
			wprintw(box, "%s", "OO");
		}
		else if (map[i] == 'X')
		{
			wattron(box,COLOR_PAIR(2));
			wprintw(box,"%s", "XX");
		}
		else
		{
			wattron(box,COLOR_PAIR(3));
			wprintw(box,"%s", "  ");
		}
		i++;
	}
	refresh();
}

void	p1_win(int pair)
{
	attron(COLOR_PAIR(pair));
	printw("\n\n\n\n");

	printw("   ___ ___  _      ___    \n");
	printw("  / _ <  / | | /| / (_)__ \n");
	printw(" / ___/ /  | |/ |/ / / _ \\\n");
	printw("/_/  /_/   |__/|__/_/_//_/\n");
	refresh();
}       
void	p2_win(int pair)
{
	attron(COLOR_PAIR(pair));
	printw("\n   ___  ___    _      ___    ");
	printw("\n  /  _ \\|_  |  | | /| / (_)__ ");
	printw("\n / ___/ __/   | |/ |/ / / _ \\");
	printw("\n/_/  /____/   |__/|__/_/_/\\/_/");
	printw("\n                             ");
	refresh();
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

void	get_player_name(char *line, WINDOW *title)
{
	char *p1;
	char *p2;

	p1 = NULL;
	p2 = NULL;

	while (get_next_line(0, &line) > 0)
	{	
		// ft_dprintf(2, "--->[%s]<---\n", line);
		if (ft_strstr(line, "$$$ exec p1 : [players/"))
			p1 = ft_strdup(line + 23);
		else if(ft_strstr(line, "$$$ exec p2 : [players/"))
			{
			p2 = ft_strdup(line + 23);
			break;
			}

	}
	clean_player(p1);
	clean_player(p2);
	wattron(title,COLOR_PAIR(5));
	mvwprintw(title, 0, 2, p1);
	wattroff(title,COLOR_PAIR(5));
	mvwprintw(title, 1, 10, "V.S");
	wattron(title,COLOR_PAIR(6));
	mvwprintw(title, 2, 13, p2);
	wattroff(title,COLOR_PAIR(6));
	wrefresh(title);
	
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
	// init_color(COLOR_DARKBLUE, 350, 150, 700);
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


        // init_pair_colors();
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

t_coord	print_map(char *line, t_coord c, WINDOW *box)
{
	int tmp;
	int h;
	int w;
	tmp = 1;
	t_coord score;
	getmaxyx(stdscr, h, w);
	box = subwin(stdscr, c.y, c.x*2, (h/2) - c.y, (w/2) - c.x);

	wattron(box, COLOR_PAIR(4));
	wborder(box, '.', '.', '.', '.', '.', '.', '.', '.');
	while(get_next_line(0, &line) > 0)
	{
		if (*line != ' ' && ft_isdigit(*line))
		{
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
		else if(ft_strncmp("== O fin", line, 8) == 0)
		{
			score.y = ft_atoi(line + 9);
		}
		else if(ft_strncmp("== X fin", line, 8) == 0)
			score.x = ft_atoi(line + 9);
	}
	return(score);
}

void	print_score(t_coord score, WINDOW *box)
{
	wattron(box,COLOR_PAIR(5));
	mvwprintw(box, 4, 4, ft_itoa(score.y));
	wattroff(box,COLOR_PAIR(5));
	wattron(box,COLOR_PAIR(6));
	mvwprintw(box, 5, 13, ft_itoa(score.x));
	wattroff(box,COLOR_PAIR(6));
	wrefresh(box);
}

int main(void) 
{
	t_coord c;
	WINDOW *box;
	WINDOW *title;

	t_coord score;
	char *line;
	line = NULL;
	box = NULL;
	title = NULL;
	initCurses();
	attron(COLOR_PAIR(6));
	border('*', '*', '*', '*', '*', '*', '*', '*' );
	refresh();
	title = subwin(stdscr, 25, 40, 5, 5);
	get_player_name(line, title);
	get_height(line, &c);
	score = print_map(line , c, box);
//	ft_printf("[[%d || %d]]\n", score.y, score.x);
	print_score(score, title);
	sleep(2);
	endwin();

	free(box);

	return 0;
}