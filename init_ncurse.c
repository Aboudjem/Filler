#include "includes/filler.h"

void             init_colors(void)
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

void				init_pairs(void)
{
	init_pair(1, COLOR_PINK, COLOR_PINK);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_DARKBLUE, COLOR_DARKBLUE);
	init_pair(5, COLOR_PINK, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
}
void    init_curses(void)
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