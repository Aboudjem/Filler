#include "includes/filler.h"
#include <curses.h>
#include <ncurses.h>


void	color_line(char *map)
{
	int i;
	i = 0;

	while (map[i])
	{
		if (map[i] == 'O')
		{
			 attron(COLOR_PAIR(1));
			printw("%c", 'O');
		}
		else if (map[i] == 'X')
		{
			 attron(COLOR_PAIR(2));
			printw("%c", 'X');
		}
		else
		{
			 attron(COLOR_PAIR(3));
			printw("%c", '.');
		}
		i++;
	}
	refresh();
}

void	printfiller(int pair)
{
	attron(COLOR_PAIR(pair));
printw("\n\n\n\n");
printw("	 ______ _ _ _           \n");
printw("	|  ____(_) | |          \n");
printw("	| |__   _| | | ___ _ __ \n");
printw("	|  __| | | | |/ _ \\ '__|\n");
printw("	| |    | | | |  __/ |   \n");
printw("	|_|    |_|_|_|\\___|_|   \n");
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
printw("\n  /  _ \|_  |  | | /| / (_)__ ");
printw("\n / ___/ __/   | |/ |/ / / _ \\");
printw("\n/_/  /____/   |__/|__/_/_/\/_/");
printw("\n                             ");
refresh();
}
#include <time.h>
#include <unistd.h>
int		main()
{
	char *line;
	int p1 = 0;
	int p2 = 0;
	int i = 0;
	int y = 0;
	int tmp = 0;
	initscr();
	curs_set(0);
		noecho();	
	start_color();
	init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
	while (get_next_line(0, &line) > 0)
	{	
 printfiller(4);
		if (ft_strstr(line, "Plateau"))
		{
			i = 1;
			y = ft_atoi(line + 7);
			tmp = 0;
		}
		else if (i == 1 && *line != ' ' && ft_isdigit(*line))
		{
			move(tmp+12, 0);
			printw("	");
			color_line(line);
			tmp++;
			refresh();
		}
		move(0, 0);
		refresh();
		if (ft_strncmp("== O", line, 4) == 0)
			p1 = ft_atoi(line+10);
		else if (ft_strncmp("== X", line, 4) == 0)
			p2 = ft_atoi(line+10);
	}
	printw("P1[%d]\tP2[%d]\n", p1, p2);
		refresh();
		sleep(5);
		clear();
	if (p1 > p2)
		p1_win(4);
	else
		p2_win(5);
	// attron(COLOR_PAIR(4));
	printw("\n\n");
	printw("P1[%d]\tP2[%d]\n", p1, p2);
	// printw("%d", begin);
	refresh();
		
	sleep(10);
		endwin();
	return (0);
}
